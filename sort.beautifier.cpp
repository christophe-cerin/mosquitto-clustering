//
// C++ program for sorting (3-way quicksort and other methods)
// 
// This file is a reduced version of functions implemented in quicksort.cpp
//
// g++ -Wall -O3 quicksort.cpp -lomp  <-- clang
// g++ -Wall -O3 quicksort.cpp -lgomp -fopenmp  <-- Linux
//
// if you want to execute with the recursive 3way quicksort, please
// compile as follows:
// g++ -Wall -O3 -DRECURSION quicksort.cpp -lomp  <-- clang
// g++ -Wall -O3 -DRECURSION quicksort.cpp -lgomp -fopenmp  <-- Linux
//
// if you want to compile with the congrential method for random
// number generation, compile as follows:
// g++ -Wall -O3 -DCONGRUENCE quicksort.cpp -lomp  <-- clang
// g++ -Wall -O3 -DCONGRUENCE quicksort.cpp -lgomp -fopenmp  <-- Linux
//
// Special note: you can also combine the RECURSION and CONGUENCE flags
//
// Testing environment:
// $ g++ --version
// g++ (Ubuntu 10.2.0-13ubuntu1) 10.2.0
// Copyright (C) 2020 Free Software Foundation, Inc.
// This is free software; see the source for copying conditions.  There is NO
// warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//
// Christophe Cérin (May 2021)
//
#ifdef USING_OMP
#include <omp.h>
#endif
#include <algorithm>
#include <iostream>
#include "kmeans.h"

using namespace std;

// Custom less comparator
bool
lessPoints (const Point & lhs, const Point & rhs)
{
  return (lhs._x < rhs._x) || ((lhs._x == rhs._x) && (lhs._y < rhs._y));
}

// Custom less or equal comparator
bool
lessEqualPoints (const Point & lhs, const Point & rhs)
{
  return (lhs._x <= rhs._x) || ((lhs._x == rhs._x) && (lhs._y <= rhs._y));
}

// Custom greater comparator
bool
greaterPoints (const Point & lhs, const Point & rhs)
{
  return (lhs._x > rhs._x) || ((lhs._x == rhs._x) && (lhs._y > rhs._y));
}

// Custom greater or equal comparator
bool
greaterEqualPoints (const Point & lhs, const Point & rhs)
{
  return (lhs._x >= rhs._x) || ((lhs._x == rhs._x) && (lhs._y >= rhs._y));
}

// Custom equal comparator
bool
equalPoints (const Point & lhs, const Point & rhs)
{
  return (lhs._x == rhs._x) && (lhs._y == rhs._y);
}

/* Function to sort an array using insertion sort*/
void
insertionSort (Point arr[], int n)
{
  int i, j;
  Point key = Point (0.0, 0.0, 0);
  for (i = 1; i < n; i++)
    {
      key = arr[i];
      j = i - 1;

      /* Move elements of arr[0..i-1], that are
         greater than key, to one position ahead
         of their current position */
      while (j >= 0 && greaterPoints (arr[j], key))
	{
	  swap (arr[j + 1], arr[j]);
	  j = j - 1;
	}
      swap (arr[j + 1], key);
    }
}


/* This function partitions a[] in three parts
a) a[l..i] contains all elements smaller than pivot
b) a[i+1..j-1] contains all occurrences of pivot
c) a[j..r] contains all elements greater than pivot */
void
partition (Point a[], int l, int r, int &i, int &j)
{
  i = l - 1, j = r;
  int p = l - 1, q = r;
  Point v = a[r];

  while (true)
    {
      // From left, find the first element greater than
      // or equal to v. This loop will definitely
      // terminate as v is last element
      while (lessPoints (a[++i], v))
	;

      // From right, find the first element smaller than
      // or equal to v
      while (lessPoints (v, a[--j]))
	if (j == l)
	  break;

      // If i and j cross, then we are done
      if (i >= j)
	break;

      // Swap, so that smaller goes on left greater goes
      // on right
      swap (a[i], a[j]);

      // Move all same left occurrence of pivot to
      // beginning of array and keep count using p
      if (equalPoints (a[i], v))
	{
	  p++;
	  swap (a[p], a[i]);
	}

      // Move all same right occurrence of pivot to end of
      // array and keep count using q
      if (equalPoints (a[j], v))
	{
	  q--;
	  swap (a[j], a[q]);
	}
    }

  // Move pivot element to its correct index
  swap (a[i], a[r]);

  // Move all left same occurrences from beginning
  // to adjacent to arr[i]
  j = i - 1;
  for (int k = l; k < p; k++, j--)
    swap (a[k], a[j]);

  // Move all right same occurrences from end
  // to adjacent to arr[i]
  i = i + 1;
  for (int k = r - 1; k > q; k--, i++)
    swap (a[i], a[k]);
}

// 3-way partition based quick sort
void
quicksort (Point a[], int l, int r)
{
  if (r <= l)
    return;
  if ((r - l + 1) <= 1024)
    {				// dependant of the cache structure
      insertionSort (a, r - l + 1);
      return;
    }

  int i, j;

  // Note that i and j are passed as reference
  partition (a, l, r, i, j);

  // Recur -- in parallel
#pragma omp task shared(a) firstprivate(l,j)
  {
    quicksort (a, l, j);
  }
#pragma omp task shared(a) firstprivate(i,r)
  {
    quicksort (a, i, r);
  }
#pragma omp taskwait
}

#define MAX_LEVELS  64

int
quickSort_without_stack_or_recursion (Point arr[], int elements)
{
  int beg[MAX_LEVELS], end[MAX_LEVELS], L, R;
  int i = 0;

  beg[0] = 0;
  end[0] = elements;
  while (i >= 0)
    {
      L = beg[i];
      R = end[i];
      if (R - L > 1)
	{
	  int M = L + ((R - L) >> 1);
	  Point piv = arr[M];
	  swap (arr[M], arr[L]);

	  if (i == MAX_LEVELS - 1)
	    return -1;
	  R--;
	  while (L < R)
	    {
	      while (greaterEqualPoints (arr[R], piv) && L < R)
		R--;
	      if (L < R)
		swap (arr[L++], arr[R]);
	      while (lessEqualPoints (arr[L], piv) && L < R)
		L++;
	      if (L < R)
		swap (arr[R--], arr[L]);
	    }
	  arr[L] = piv;
	  M = L + 1;
	  while (L > beg[i] && equalPoints (arr[L - 1], piv))
	    L--;
	  while (M < end[i] && equalPoints (arr[M], piv))
	    M++;
	  if (L - beg[i] > end[i] - M)
	    {
	      beg[i + 1] = M;
	      end[i + 1] = end[i];
	      end[i++] = L;
	    }
	  else
	    {
	      beg[i + 1] = beg[i];
	      end[i + 1] = L;
	      beg[i++] = M;
	    }
	}
      else
	{
	  i--;
	}
    }
  return 0;
}


#ifdef CONGRUENCE
const unsigned long Modulus = static_cast < unsigned long >(pow (2, 32));
const unsigned long multiplier = 1664525;
const unsigned long increment = 1013904223;
unsigned long x;

unsigned long
next ()
{
  x = (multiplier * x + increment) % Modulus;
  return x;
}
#endif

#ifndef CONGRUENCE
#include <random>
#endif

// A utility function to print an array
void
printarr (Point a[], int n)
{
  for (int i = 0; i < n; ++i)
    printf ("%d -> %f, %f\n", i, a[i]._x, a[i]._y);
  printf ("\n");
}
