/* Implement standard heap algorithms:
1. MAX-HEAPIFY(A, i)
2. BUILD-MAX-HEAP(A)
3. HEAPSORT(A)
4. HEAP-EXTRACT-MAX(A)
5. HEAP-INCREASE-KEY(A, i, key)
6. MAX-HEAP-INSERT(A, key) */

#ifndef __HEAP_SORT__
#define __HEAP_SORT__

#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <cmath>
#include <limits>

#define HEAP_DISPLAY_FIELDS_LENGTH	4
#define HEAP_DISPLAY_FIELD_WIDTH	-13
#define HEAP_MAX_ELEMENTS			20

#define HeapPrintStr(value) printf("%*s", HEAP_DISPLAY_FIELD_WIDTH, value)
#define HeapPrintNum(value) printf("%*d", HEAP_DISPLAY_FIELD_WIDTH, value)

typedef enum
{
	ERR_OVERFLOW_OF_NUMBER_OF_ARGUMENTS = -4,
	ERR_HEAP_UNDERFLOW = -3,
	ERR_NULL_POINTER = -2,
	ERR_INSUFFICIENT_NUMBER_OF_ARGUMENTS = -1,
	SUCCESS = 0
} ExitCode;

typedef struct __HeapNode__
{
	int key;
	unsigned int index;
	
	__HeapNode__ *left;
	__HeapNode__ *right;
} HeapNode;

typedef struct __HeapDisplay__
{
	std::string field;
} HeapDisplay;

inline unsigned int parent(unsigned int child)
{
	unsigned int parent;
	
	if (child % 2 == 0)
		parent = (child - 2) / 2;
	else
		parent = (child - 1) / 2;
	
	return parent;
}

/* 
Input_Output	:	Pointer to array of HeapNodes
Input1	:	Size of array
Input2 	:	Current index of pointer to array of HeapNodes
Returns	:	None
 */
void max_heapify(HeapNode *, unsigned int, unsigned int);

/* 
Input_Output	:	Pointer to array of HeapNodes
Input	:	Size of array
Returns	:	None
 */
void build_max_heap(HeapNode *, unsigned int);

/* 
Input_Output	:	Pointer to array of HeapNodes
Input	:	Size of array
Returns	:	None
 */
void heap_sort(HeapNode *, unsigned int);

/* 
Input_Output	:	Pointer to array of HeapNodes
Input	:	Size of array
Returns	:	None
 */
int heap_extract_max(HeapNode *, unsigned int);

/* 
Input_Output	:	Pointer to array of HeapNodes
Input1	:	Size of array
Input2	:	Index to update
Input3	:	New key
Returns	:	None
 */
void heap_increase_key(HeapNode *, unsigned int, unsigned int, int);

/* 
Input_Output1	:	Pointer to array of HeapNodes
Input_Output2	:	Size of array
Input	:	New key
Returns	:	None
 */
void max_heap_insert(HeapNode *, unsigned int *, int);

/* 
Input1	:	Pointer to array of integers
Input2	:	Size of array
Output 	:	Pointer to array of heap elements
Returns	:	None
 */
void construct_heap(int *, unsigned int, HeapNode *);

/* 
Input1	:	Info regarding context of display
Input2	:	Pointer to array of heap elements
Input3	:	Size of array
Returns	:	None
 */
void display_heap(std::string title, HeapNode *, unsigned int);

/* 
Input_Output	:	Pointer to array of integers
Input	:	Size of array
Returns	:	None
 */
void sort_integers_ascending(int *, unsigned int);

#endif