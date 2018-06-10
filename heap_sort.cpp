/* Implement standard heap algorithms:
1. MAX-HEAPIFY(A, i)
2. BUILD-MAX-HEAP(A)
3. HEAPSORT(A)
4. HEAP-EXTRACT-MAX(A)
5. HEAP-INCREASE-KEY(A, i, key)
6. MAX-HEAP-INSERT(A, key) */

#include "heap_sort.h"

/*
MAX-HEAPIFY(A, i)
l <- LEFT(i)
r <- RIGHT(i)
if l <= heap-size[A] and A[l] > A[i]
	then largest <- l
	else largest <- i
if r <= heap-size[A] and A[r] > A[i]
	then largest <- r
	else largest <- i
if r <= heap-size[A] and A[r] > A[largest]
	then largest <- r
if largest != i
	then exchange A[i] <-> A[largest]
		MAX-HEAPIFY(A, largest)
*/
size_t max_heapify(heap_node *input_array, unsigned int count, size_t position)
{
	if (!count)
	{
		fprintf(stderr, "Number of input array elements is zero.\n");
	}
	
	// Find address of node with largest key.
	size_t largest, largest_left ,largest_right;
	
	// Pointer to start of input array.
	heap_node current = input_array[position];
	heap_node *left = current.left;
	heap_node *right = current.right;
		
	// Compare left child and current.
	if (position < count && left->key > current.key)
		largest_left = left->index;
	else
		largest_left = position;
		
	// Compare right child and current.
	if (position < count && right->key > current->key)
		largest_right = right->index;
	else
		largest_right = position;
		
	// Compare largest of current and both children.
	if (largest_left > largest_right)
		largest = largest_left;
	else
		largest = largest_right;
		 
		if (largest != position)
		{
			// Exchange current element's key with largest element's key.
			input_array[position].key = input_array[largest].key;
			input_array[largest].key = current.key;
			
			// Recursively do a max-heapify with new key of current heap_node.
			MAX-HEAPIFY(input_array, position);
		}
	}
		
	return position;
}

/*
BUILD-MAX-HEAP(A)
heap-size[A] <- length[A]
for i <- floor(length[A] / 2) downto 1
	do MAX-HEAPIFY(A, i)
*/

/*
HEAPSORT(A)
BUILD-MAX-HEAP(A)
for i <- length[A] downto 2
	do exchange A[1] <-> A[i]
		heap-size[A] <- heap-size[A] - 1
		MAX-HEAPIFY(A, 1)
*/

/*
HEAP-EXTRACT-MAX(A)
if heap-size[A] < 1
	then error "heap underflow"
max <- A[1]
A[1] <- A[heap-size[A]]
heap-size[A] <- heap-size[A] - 1
MAX-HEAPIFY(A, 1)
return max
*/

/*
HEAP-INCREASE-KEY(A, i, key)
if key < A[i]
	then error "new key is smaller then current key"
A[i] <- key
while i > 1 and A[PARENT(i)] < A[i]
	do exchange A[i] <-> A[PARENT(i)]
		i <- PARENT(i)
*/

/*
MAX-HEAP-INSERT(A, key)
heap-size[A] <- heap-size[A] + 1
A[heap-size[A]] <- -inf
HEAP-INCREASE-KEY(A, heap-size[A], key)
*/
		