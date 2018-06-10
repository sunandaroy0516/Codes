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

typedef struct heap_node
{
	int key;
	size_t index;
	
	heap_node *left;
	heap_node *right;
};

#endif