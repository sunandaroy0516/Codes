/* Implement standard heap algorithms:
1. MAX-HEAPIFY(A, i)
2. BUILD-MAX-HEAP(A)
3. HEAPSORT(A)
4. HEAP-EXTRACT-MAX(A)
5. HEAP-INCREASE-KEY(A, i, key)
6. MAX-HEAP-INSERT(A, key) */

#ifdef __HEAP_SORT__
#define __HEAP_SORT__

#include <iostream>
#include <stdlib.h>

typedef enum
{
/* 	ERR_INVALID_NUMBER_OF_ARGUMENTS = -5,
	ERR_INVALID_LENGTH_OF_SMALLER_STRING = -4,
	ERR_NULL_POINTER = -3,
	ERR_INSUFFICIENT_NUMBER_OF_KEYS_IN_BIGGER_STRING = -2, */
	ERR_INSUFFICIENT_NUMBER_OF_ARGUMENTS = -1,
	SUCCESS = 0
} ExitCode;

typedef struct
{
	int key;
	unsigned int index;
	
	HeapNode *left;
	HeapNode *right;
} HeapNode;

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