/* Implement standard heap algorithms:
1. MAX-HEAPIFY(A, i)
2. BUILD-MAX-HEAP(A)
3. HEAPSORT(A)
4. HEAP-EXTRACT-MAX(A)
5. HEAP-INCREASE-KEY(A, i, key)
6. MAX-HEAP-INSERT(A, key) */

#include "heap_sort.h"

using namespace std;

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
/* size_t max_heapify(heap_node *input_heap, unsigned int heap_size,
	size_t heap_index)
{
	// Find address of node with largest key.
	size_t largest;
	
	if (input_heap == NULL)
	{
		stderr << "Pointer to heap is NULL.\n");
	}
		
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
} */

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

void construct_heap(int *input_array, unsigned int array_size,
	HeapNode *output_heap)
{	
	for (size_t i = array_size - 1; i >= array_size / 2; i--)
	{
		output_heap[i].key = input_array[i];
		output_heap[i].index = i;
		output_heap[i].left = NULL;
		output_heap[i].right = NULL;
	}
	
	for (size_t i = array_size / 2 - 1; i >= 0; i--)
	{
		unsigned int left_index, right_index;
		
		output_heap[i].key = input_array[i];
		output_heap[i].index = i;
		
		left_index = i * 2 + 1;
		if (left_index >= array_size)
		{
			output_heap[i].left = NULL;
		}
		else
		{
			output_heap[i].left = &output_heap[left_index];
		}
		
		right_index = i * 2 + 2;
		if (right_index >= array_size)
		{
			output_heap[i].right = NULL;
		}
		else
		{
			output_heap[i].right = &output_heap[right_index];
		}
	}		
}

void display_heap(HeapNode *output_heap, unsigned int array_size)
{
	cout << "Index\tKey\tLeft Key\tRight Key\n" << endl;
	
	for (size_t i = 0; i < array_size; i++)
	{
		HeapNode current = output_heap[i];
		cout << i << "\t" << current.key << "\t";

		if (current.left == NULL)
			cout << "NA\t";
		else
			cout << (current.left)->key << "\t";

		if (current.right == NULL)
			cout << "NA" << endl;
		else
			cout << (current.right)->key << endl;
	}
}

// Usage: <executable> array_of_integers 
int main(int argc, char **argv)
{
	int *input_array = NULL;
	HeapNode *output_heap = NULL;
	unsigned int array_size;
	
	if (argc < 2)
	{
		cerr << "Insufficient number of input elements" << endl;
		return ERR_INSUFFICIENT_NUMBER_OF_ARGUMENTS;
	}
	
	array_size = argc - 1;
	input_array = calloc(array_size, sizeof(int));
	output_heap = calloc(array_size, sizeof(HeapNode));
	
	for (size_t i = 0; i < array_size; i++)
	{
		input_array[i] = argv[i + 1];
	}

	construct_heap(input_array, array_size, output_heap);
	
	display_heap(output_heap, array_size);
	
	return SUCCESS;
}
	
	