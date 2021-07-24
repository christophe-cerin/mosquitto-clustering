#include<iostream>
#include <cstdio>
#include <ctime>
#include "kmeans.h"
#include "kmeansPlusPlus.h"
int
main ()
{
  std::clock_t start;
  double duration;

  Kmeans kmeans (15);
  kmeans.InitPoints ("S1.txt");
  start = std::clock ();
  kmeans.InitCenters ();
  //kmeans.InitSpecifiedCenters();
  kmeans.RunKmean ();
  duration = (std::clock () - start) / (double) CLOCKS_PER_SEC;
  std::cout << "calculate time " << duration << std::endl;
  kmeans.SaveEPS ("S1.eps");

  std::
    cout << "----------------- kmeans Plus Plus -----------------" <<
    std::endl;
  KmeansPlusPlus kmeansPlusPlus (15);
  kmeansPlusPlus.InitPoints ("S1.txt");
  start = std::clock ();
  kmeansPlusPlus.InitCenters ();
  //kmeans.InitSpecifiedCenters();
  kmeansPlusPlus.RunKmean ();
  duration = (std::clock () - start) / (double) CLOCKS_PER_SEC;
  std::cout << "calculate time " << duration << std::endl;
  kmeansPlusPlus.SaveEPS ("S1_++.eps");
  kmeansPlusPlus.SaveSVG ("S1_++.svg");
  //system("pause");


  Point myPoints[64];
  int arrSize = sizeof (myPoints) / sizeof (Point);

#ifdef CONGRUENCE
  cout << "Enter a prime number" << endl;
  cin >> x;
  for (int i = 0; i < arrSize; i++)
    {
      Point p ((float (next ())), (float (next ())));
      myPoints[i] = p;
    }
#endif

#ifndef CONGRUENCE
  //int a[] = { 4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4 };
  std::random_device rd;	//Will be used to obtain a seed for the random number engine
  std::mt19937 gen (rd ());	//Standard mersenne_twister_engine seeded with rd()
  std::uniform_real_distribution < float >distribution (0.0, 100.0);
  for (int i = 0; i < arrSize; i++)
    {

      Point p (distribution (gen), distribution (gen));
      // std::cout << p._x<<"\t" << p._y << std::endl;
      myPoints[i] = p;

    }
#endif

  //int size = sizeof(a) / sizeof(int);

  // Function Call
  printarr (myPoints, arrSize);
#ifdef RECURSION
  cout << "Recursive 3way quicksort\n";
  quicksort (myPoints, 0, arrSize - 1);
#endif
#ifndef RECURSION
  cout << "Quicksort without stack or recursion\n";
  quickSort_without_stack_or_recursion (myPoints, arrSize);
#endif
  printarr (myPoints, arrSize);

  return 1;
}
