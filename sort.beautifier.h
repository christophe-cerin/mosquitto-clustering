
#include <algorithm>
#include <iostream>
#include "kmeans.h"


// Custom less comparator
bool
lessPoints (const Point & lhs, const Point & rhs);

// Custom less or equal comparator
bool
lessEqualPoints (const Point & lhs, const Point & rhs);

// Custom greater comparator
bool
greaterPoints (const Point & lhs, const Point & rhs);

// Custom greater or equal comparator
bool
greaterEqualPoints (const Point & lhs, const Point & rhs);

// Custom equal comparator
bool
equalPoints (const Point & lhs, const Point & rhs);

/* Function to sort an array using insertion sort*/
void
insertionSort (Point arr[], int n);

/* This function partitions a[] in three parts
a) a[l..i] contains all elements smaller than pivot
b) a[i+1..j-1] contains all occurrences of pivot
c) a[j..r] contains all elements greater than pivot */
void
partition (Point a[], int l, int r, int &i, int &j);

// 3-way partition based quick sort
void
quicksort (Point a[], int l, int r);

int
quickSort_without_stack_or_recursion (Point arr[], int elements);

