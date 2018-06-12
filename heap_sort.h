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

#define HEAP_DISPLAY_FIELDS_LENGTH	4
#define HEAP_DISPLAY_FIELD_WIDTH	-13

#define HeapPrintStr(value) printf("%*s", HEAP_DISPLAY_FIELD_WIDTH, value)
#define HeapPrintNum(value) printf("%*d", HEAP_DISPLAY_FIELD_WIDTH, value)

typedef enum
{
/* 	ERR_INVALID_NUMBER_OF_ARGUMENTS = -5,
	ERR_INVALID_LENGTH_OF_SMALLER_STRING = -4,
	ERR_NULL_POINTER = -3,
	ERR_INSUFFICIENT_NUMBER_OF_KEYS_IN_BIGGER_STRING = -2, */
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

/* 
Input1	:	Pointer to array of integes
Input2	:	Size of array
Output 	:	Pointer to array of heap elements
Returns	:	None
 */
void construct_heap(int *, unsigned int, HeapNode *);

/* 
Input1	:	Pointer to array of heap elements
Input2	:	Size of array
Returns	:	None
 */
void display_heap(HeapNode *, unsigned int);

#endif