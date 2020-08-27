 // ------------------ Quick sort ----------------------
 
#ifndef _QUICK_SORT
#define _QUICK_SORT

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

// calling function for Quick Sort algorithm.
// sorts array using quick sort.
// gets: array, array length, compare function and swap function.
void Quicksort(void *array, int length,int size,
		int (*Compare) (const void * x,const void * y), void (*gswap) (void* ptra, void* ptrb, int size));

// sorts array using quick sort.
// gets: array, low and high indexes, compare function and swap function.
void quicksort(void *array, int low, int high,int size,
		int (*Compare) (const void * x,const void * y), void (*gswap) (void* ptra, void* ptrb, int size));

// places pivot for quick sort.
// gets: array, low and high indexes, compare function and swap function.
int place_pivot(void *array, int low, int high,int size,
		int (*Compare) (const void * x,const void * y), void (*gswap) (void* ptra, void* ptrb, int size));


void srtheap(void *base, int nelem, int size, int (*compar)(const void *, const void *));

void heapify(char *base, const int size, int root, const int bottom, int (*compar)(const void *, const void *));

//void gswap(void* array, int a, int b,int size);
void gswap(void* ptra, void* ptrb, int size);

#endif
