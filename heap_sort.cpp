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
if r <= heap-size[A] and A[r] > A[largest]
	then largest <- r
if largest != i
	then exchange A[i] <-> A[largest]
		MAX-HEAPIFY(A, largest)
*/
void max_heapify(HeapNode *heap_to_sort, unsigned int heap_size,
	unsigned int heap_index)
{	
	unsigned int largest, tmp;
	HeapNode parent;
	HeapNode *lchild = NULL;
	HeapNode *rchild = NULL;
	
	if (heap_to_sort == NULL)
	{
		cerr << "Pointer to heap_to_sort is NULL." << endl;
		return;
	}
	
	parent = heap_to_sort[heap_index];
	lchild = parent.left;
	rchild = parent.right;
	
	if (lchild == NULL)
	{
		largest = heap_index;
	}
	else
	{
		if (lchild->index < heap_size && lchild->key > parent.key)
			largest = lchild->index;
		else
			largest = heap_index;
	}

	if (rchild != NULL)
	{		
		if (rchild->index < heap_size &&
			rchild->key > heap_to_sort[largest].key)
			largest = rchild->index;
	}
			
	if (largest != heap_index)
	{
		// Exchange current element's key with largest element's key.
		tmp = heap_to_sort[heap_index].key;
		heap_to_sort[heap_index].key = heap_to_sort[largest].key;
		heap_to_sort[largest].key = tmp;

		// Recursively do a max-heapify on heap_to_sort[largest].
		max_heapify(heap_to_sort, heap_size, largest);
	}
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

void construct_heap(int *input_array, unsigned int array_size,
	HeapNode *output_heap)
{
	if (input_array == NULL || output_heap == NULL)
	{
		cout << "Pointer is NULL" << endl;
		return;
	}

	for (size_t i = (array_size - 1); i >= (array_size / 2); i--)
	{
		output_heap[i].key = input_array[i];
		output_heap[i].index = i;
		output_heap[i].left = NULL;
		output_heap[i].right = NULL;
	}
	
	for (size_t i = (array_size / 2 - 1); i >= 0 && i < array_size; i--)
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

void display_heap(std::string title, HeapNode *output_heap,
	unsigned int array_size)
{
	HeapDisplay *header = NULL;
	
	if (output_heap == NULL)
	{
		cout << "Pointer to output_heap is NULL" << endl;
		return;
	}
	
	printf("%s\n", title.c_str());

	header = static_cast<HeapDisplay *>(calloc(HEAP_DISPLAY_FIELDS_LENGTH,
		sizeof(HeapDisplay)));
	header[0].field = "Index";
	header[1].field = "Parent";
	header[2].field = "Left Child";
	header[3].field = "Right Child";

	for (size_t i = 0; i < HEAP_DISPLAY_FIELDS_LENGTH; i++)
	{
		HeapPrintStr((header[i].field).c_str());
	}
	
	cout << endl;
	
	for (size_t i = 0; i < array_size; i++)
	{
		HeapNode current = output_heap[i];
		HeapPrintNum(i);
		HeapPrintNum(current.key);

		if (current.left == NULL)
			HeapPrintStr("NA");
		else			
			HeapPrintNum((current.left)->key);

		if (current.right == NULL)
			HeapPrintStr("NA");
		else
			HeapPrintNum((current.right)->key);
		
		cout << endl;
	}
	
	cout << endl;
}

// Usage: <executable> array_of_integers 
int main(int argc, char **argv)
{
	int *input_array = NULL;
	HeapNode *output_heap = NULL;
	unsigned int array_size;
	std::string title;
	
	if (argc < 2)
	{
		cerr << "Insufficient number of input elements" << endl;
		return ERR_INSUFFICIENT_NUMBER_OF_ARGUMENTS;
	}
	
	array_size = argc - 1;
	input_array = static_cast<int *>(calloc(array_size, sizeof(int)));
	output_heap =
		static_cast<HeapNode *>(calloc(array_size, sizeof(HeapNode)));
	
	for (size_t i = 0; i < array_size; i++)
	{
		std::string curr_argv = argv[i + 1];
		input_array[i] = std::stoi(curr_argv);
	}

	construct_heap(input_array, array_size, output_heap);
	
	title = "Unsorted";
	display_heap(title, output_heap, array_size);
	
	max_heapify(output_heap, array_size, 1);
	
	title = "Max-heapify at Index 1";
	display_heap(title, output_heap, array_size);
	
	return SUCCESS;
}
	
	