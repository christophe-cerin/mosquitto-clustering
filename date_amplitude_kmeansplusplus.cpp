#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <pthread.h>
#include <stdlib.h>
#include <cmath>
#include "kmeans.h"
#include "kmeansPlusPlus.h"
#include "date_amplitude.h"
#include "sort.beautifier.h"
#include <mosquittopp.h>
#include <bits/stdc++.h>

// Window size -> the most important parameter
#define W 2048

char file_name[128];

#include "concurrentqueue.h"

#include <semaphore.h>
// Semaphore Creation
sem_t semaphore;
#include <mutex>
std::mutex My_mutex;

struct PPoint {
    double
     _x;
    double
     _y;
};

moodycamel::ConcurrentQueue < PPoint > q;
PPoint items[30];

std::thread threads[1];

// A utility function to print an array
void aff_arr(std::list < Point > a)
{
    int i = 0;
    for (std::list < Point >::iterator it = a.begin(); it != a.end(); it++)
	printf("Point %d -> %f, %f\n", i++, (*it)._x, (*it)._y);
    printf("\n");
}

#define isdigit(c)(c >= '0' && c <= '9')

//
// This version of get_float to convert string to double
// seems buggy or not compatible with -std=c++11
// Use std::stod(str); instead
//
double get_float(std::string message)
{
    int len = message.size();
    char *s = new char[len + 1];
    std::copy(message.begin(), message.end(), s);
    s[len] = '\0';

    double a = 0.0;
    int e = 0;
    int c;
    while ((c = *s++) != '\0' && isdigit(c)) {
	a = a * 10.0 + (c - '0');
    }
    if (c == '.') {
	while ((c = *s++) != '\0' && isdigit(c)) {
	    a = a * 10.0 + (c - '0');
	    e = e - 1;
	}
    }
    if (c == 'e' || c == 'E') {
	int sign = 1;
	int i = 0;
	c = *s++;
	if (c == '+')
	    c = *s++;
	else if (c == '-') {
	    c = *s++;
	    sign = -1;
	}
	while (isdigit(c)) {
	    i = i * 10 + (c - '0');
	    c = *s++;
	}
	e += i * sign;
    }
    while (e > 0) {
	a *= 10.0;
	e--;
    }
    while (e < 0) {
	a *= 0.1;
	e++;
    }
    // std::cout << "Message: " << message << std::endl;
    // std::cout << std::fixed << std::setprecision(2) << "Convert: " << a 
    // << std::endl;
    return a;
}

mqtt_tempconv::mqtt_tempconv(const char *id, const char *host,
			     int port):mosquittopp(id)
{
    int keepalive = 60;

    /*
     * Connect immediately. This could also be done by calling
     * mqtt_tempconv->connect(). 
     */
    connect(host, port, keepalive);
};

mqtt_tempconv::~mqtt_tempconv()
{
}

void
 mqtt_tempconv::on_connect(int rc)
{
    printf("Connected with code %d.\n", rc);
    if (rc == 0) {
	/*
	 * Only attempt to subscribe on a successful connect. 
	 */
	// subscribe(NULL, "date/celsius");
	// subscribe on all topics with wildcard #
	subscribe(NULL, "#"); 
    }
}

void mqtt_tempconv::on_message(const struct mosquitto_message *message)
{
    char buf[128];
    PPoint pp;
    std::vector < std::string > s;	// dimension of data
      
    My_mutex.lock();
    if (!strcmp(message->topic, "date/celsius")) {
	memset(buf, 0, 128 * sizeof(char));
	/*
	 * Copy N-1 bytes to ensure always 0 terminated. 
	 */
	memcpy(buf, message->payload, 128 * sizeof(char));
        
	std::stringstream check1(buf);
	std::string intermediate;
	// Tokenizing w.r.t. ','
	while(getline(check1, intermediate, ','))
	  {
	    s.push_back(intermediate);
	  }

	pp._x = std::stod(s[0]);
	pp._y = std::stod(s[1]);
	q.enqueue(pp);
	s.clear();
	intermediate.clear();
	check1.clear();

    } else {
	if (!strcmp(message->topic, "final/final")) {
	    memset(buf, 0, 128 * sizeof(char));
	    /*
	     * Copy N-1 bytes to ensure always 0 terminated. 
	     */
	    memcpy(buf, message->payload, 128 * sizeof(char));

	    std::stringstream check1(buf);
	    std::string intermediate;
	    // Tokenizing w.r.t. ','
	    while(getline(check1, intermediate, ','))
	      {
		s.push_back(intermediate);
	      }
	    s[0].copy(file_name, s[0].size(), 0);
	    printf("File name of input data: %s\n", file_name);
	    // Release the lock
	    sem_post(&semaphore);
	    s.clear();
	    intermediate.clear();
	    check1.clear();
	}
    }
    My_mutex.unlock();
}

void PrintPoint(std::list < Point > &pointList)
{
    std::list < Point >::iterator pointsIter = pointList.begin();
    int i = 0;
    for (; pointsIter != pointList.end(); pointsIter++) {
	std::cout << std::fixed << i++ << "\t" << pointsIter->_x
	    << "\t" << pointsIter->_y << std::endl;
    }
}

void
DumpToFile(char t[], std::list < Point > &pointList, double duration,
	   int tour)
{
    std::list < Point >::iterator pointsIter = pointList.begin();
    std::ofstream mylog;
    mylog.open(t, std::ofstream::app);
    mylog << "# Sum of execution time of kmeans ; number of kmeans calls"
	<< std::endl;
    mylog << std::fixed << "# " << duration << ";" << tour << std::endl;
    mylog << "# Now the Centroids:" << std::endl;
    for (; pointsIter != pointList.end(); pointsIter++) {
	mylog << std::fixed << pointsIter->_x
	    << ";" << pointsIter->_y << std::endl;
    }
    mylog.close();
}

void MyCopy(std::list < Point > &dest, std::list < Point > &src)
{
    std::list < Point >::iterator pointsIter = src.begin();
    Point p;
    for (; pointsIter != src.end(); pointsIter++) {
	p = Point(pointsIter->_x, pointsIter->_y);
	dest.push_back(p);
    }
}

void mqtt_tempconv::on_subscribe(int mid, int qos_count,
				 const int *granted_qos)
{
    printf("Subscription succeeded.\n");
    // Init semaphore
    sem_init(&semaphore, PTHREAD_PROCESS_SHARED, 1);

    threads[0] = std::thread([&]() {
			     int mycount = 0;
			     //Kmeans mykmeans(5);
			     KmeansPlusPlus mykmeansPlusPlus (5);
			     bool ok = true; bool finish = false;
			     int tour = 1; double somme_duration = 0.0;
			     // Acquire the semaphore
			     sem_wait(&semaphore);
			     // std::list<Point> XXX;
			     while (finish == false) {
			     std::size_t count =
			     q.try_dequeue_bulk(items, 30);
			     int borne =
			     (ok) ? W : int (floor(sqrt(W))) - 1;
			     for (size_t i = 0; (mycount < borne) && (i < count);
				  i++) {
			       Point ppp;
			       float *x = new float;
			       float *y = new float;
			       *x = items[i]._x; *y = items[i]._y;
			       if ((*x == 0.0) && (*y == 0.0)) {
				 finish = true;}
			       else
				 {
				   ppp = Point(0.0 + *x, 0.0 + *y);
				   mykmeansPlusPlus._Points.push_back(ppp);
				   delete[]x; delete[]y; mycount++;}
			          }
			       if (finish == false) {
				 if (((mycount == W) && (ok == true))
				     || ((mycount == int (floor(sqrt(W))) - 1)
					 &&(ok == false))) {
				   mycount = 0;
				   std::clock_t start;
				   double duration; start = std::clock();
				   // aff_arr(kmeans._Points);
				   // PrintPoint(mykmeans._Points); 
				   if (ok == true) {
				     ok = false;
				     mykmeansPlusPlus.InitPoints (mykmeansPlusPlus._Points);
				     mykmeansPlusPlus.InitCenters ();
				     // Make a copy of initial centriods
				     MyCopy(mykmeansPlusPlus._CopyCenters,
					    mykmeansPlusPlus._Centers);
				     // PrintPoint(mykmeans._Centers);
				   }
				   else
				     {
				       mykmeansPlusPlus._Centers.clear();
				       mykmeansPlusPlus.InitPoints (mykmeansPlusPlus._Points);
				       mykmeansPlusPlus.InitCenters();
				     }

				   mykmeansPlusPlus.RunKmean();

			           Point arr[mykmeansPlusPlus._Points.size()];
				   std::copy(mykmeansPlusPlus._Points.begin(),
					     mykmeansPlusPlus._Points.end(), arr);
				   quicksort(arr, 0,
					     mykmeansPlusPlus._Points.size() - 1);
				   // We select SQRT(mykmeans._Points.size()) -
				   // 1 pivots in the sorted array and we remove
				   // the corresponding points in list
				   // mykmeans._Points
				   // We guess that the size is a power of 2
				   int taille =
				     (int) sqrt((double) mykmeansPlusPlus._Points.size());
				   int mysize = mykmeansPlusPlus._Points.size() - 1;
				   for (int i = taille - 1; i < mysize;
					i += taille) {
				     auto it =
				       std::find_if(mykmeansPlusPlus._Centers.begin(),
						    mykmeansPlusPlus._Centers.end(),
						    [&](const Point v) {
						      return equalPoints(v, arr[i]);
						    }
						    );
				     if (mykmeansPlusPlus._Centers.end() == it) {

				       mykmeansPlusPlus._Points.remove_if([&](const Point v) {
						     return
							equalPoints(v,
								    arr
								    [i]);}
					 );
				     }
				     else
				       {
					 // Found a center as a pivot
					 // We cancel the left neighbor
					 mykmeansPlusPlus._Points.remove_if([&](const Point v) {
							return
							equalPoints(v,
								    arr[i -
									1]);}
					   );}
				   }

				   duration =
				     (std::clock() -
				      start) / (double) CLOCKS_PER_SEC;
				   std::cout << "calculate time (" << tour++ <<
				     ") " << duration << std::endl;
				   somme_duration += duration;
				   // Next round: populate mykmeans._Points with
				   // mysize == mykmeans._Points.size()-1;
				   // Points
				 }
			     }}
			     // Wait until the file name becomes known
			     sem_wait(&semaphore);
			     std::cout << "Final centroids:" << std::endl;
			     PrintPoint(mykmeansPlusPlus._Centers); char result[128];
			     // array 
			     // to 
			     // hold 
			     // the 
			     // result.
			     strcpy(result, "Centroids_After_");	// copy 
			     // string 
			     // one 
			     // into 
			     // the 
			     // result.
			     strcat(result, file_name);
			     // append string
			     // two to the
			     // result.
			     std::cout << "File name for centriods AFTER kmeans: " << result << std::endl;
			     DumpToFile(result, mykmeansPlusPlus._Centers, somme_duration, tour - 1);
			     strcpy(result, "");
			     strcpy(result, "Centroids_Before_");	// copy 
			     // string 
			     // one 
			     // into 
			     // the 
			     // result.
			     strcat(result, file_name);	// append string
			     // two to the
			     // result.
			     std::cout <<
			       "File name for centriods BEFORE kmeans: " <<
			       result << std::endl;
			     DumpToFile(result, mykmeansPlusPlus._CopyCenters, 0.0, 0);
			     // Reinit main variables to their initial states
			     //mycount = 0;
			     //ok = true; finish = false;
			     //tour = 1; somme_duration = 0.0;

			     sem_post(&semaphore);});
}
