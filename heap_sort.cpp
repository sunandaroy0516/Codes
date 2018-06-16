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
	
	// Calculate index with largest element in left subtree.
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

	// Calculate index with largest element in right subtree.
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
void build_max_heap(HeapNode *heap_to_sort, unsigned int heap_size)
{
	unsigned int index;
	float tmp_index;
	
	if (heap_to_sort == NULL)
	{
		cerr << "Pointer to heap_to_sort is NULL." << endl;
		return;
	}
	
	// Calculate position of node preceding leaves of heap. 
	tmp_index = heap_size / 2;
	index = floor(tmp_index);
	
	// Max-heapify each parent node.
	for (size_t i = index - 1; i >= 0 && i < heap_size; i--)
		max_heapify(heap_to_sort, heap_size, i);
}

/*
HEAPSORT(A)
BUILD-MAX-HEAP(A)
for i <- length[A] downto 2
	do exchange A[1] <-> A[i]
		heap-size[A] <- heap-size[A] - 1
		MAX-HEAPIFY(A, 1)
*/
void heap_sort(HeapNode *heap_to_sort, unsigned int heap_size)
{
	unsigned int tmp, end;
	
	if (heap_to_sort == NULL)
	{
		cerr << "Pointer to heap_to_sort is NULL." << endl;
		return;
	}
	
	build_max_heap(heap_to_sort, heap_size);
	
	end = heap_size - 1;
	for (size_t i = end; i > 0 && i < heap_size; i--, end--)
	{
		// Exchange last node's key with max key at root.
		tmp = heap_to_sort[0].key;
		heap_to_sort[0].key = heap_to_sort[end].key;
		heap_to_sort[end].key = tmp;

		max_heapify(heap_to_sort, end, 0);
	}		
}	

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
int heap_extract_max(HeapNode *heap_to_update, unsigned int *heap_size)
{
	unsigned int current, parent;
	int max;
	
	if (heap_to_update == NULL || heap_size == NULL)
	{
		cerr << "Pointer is NULL." << endl;
		return ERR_NULL_POINTER;
	}
	
	current = *heap_size - 1;
	if (current == 0)
	{
		cerr << "Heap underflow" << endl;
		return ERR_HEAP_UNDERFLOW;
	}
	
	// Store current value of max key and replace it with key of last node.
	max = heap_to_update[0].key;
	heap_to_update[0].key = heap_to_update[current].key;
	
	/* Calculate parent node from current node and update pointer to its
	child nodes. */
	if (current % 2 == 0)
	{
		parent = (current - 2) / 2;
		free(heap_to_update[parent].right);
		heap_to_update[parent].right = NULL;
	}
	else
	{
		parent = (current - 1) / 2;
		free(heap_to_update[parent].left);
		heap_to_update[parent].left = NULL;
	}
	
	// Update size of heap and max-heapify at root.
	*heap_size = current;
	max_heapify(heap_to_update, *heap_size, 0);

	return max;
}

/*
HEAP-INCREASE-KEY(A, i, key)
if key < A[i]
	then error "new key is smaller then current key"
A[i] <- key
while i > 1 and A[PARENT(i)] < A[i]
	do exchange A[i] <-> A[PARENT(i)]
		i <- PARENT(i)
*/
void heap_increase_key(HeapNode *heap_to_update, unsigned int heap_size,
	unsigned int index_to_update, int new_key)
{
	unsigned int current;
	int tmp;
	
	if (heap_to_update == NULL)
	{
		cerr << "Pointer to heap_to_update is NULL." << endl;
		return;
	}

	current = index_to_update;
	if (new_key < heap_to_update[current].key)
	{
		cerr << "New key is smaller than current key" << endl;
		return;
	}	
	
	heap_to_update[current].key = new_key;
		
	while (current > 0 &&
		heap_to_update[parent(current)].key < heap_to_update[current].key)
	{
		unsigned int parent_index = parent(current);
		
		/* Compare current node's key with parent node's key and exchange to
		maintain max-heap property. */
		tmp = heap_to_update[current].key;
		heap_to_update[current].key = heap_to_update[ parent_index].key;
		heap_to_update[ parent_index].key = tmp;
		
		current = parent_index;
	}
}

/*
MAX-HEAP-INSERT(A, key)
heap-size[A] <- heap-size[A] + 1
A[heap-size[A]] <- -inf
HEAP-INCREASE-KEY(A, heap-size[A], key)
*/
void max_heap_insert(HeapNode *heap_to_update, unsigned int *heap_size,
	int key)
{
	unsigned int end;
	
	if (heap_to_update == NULL || heap_size == NULL)
	{
		cerr << "Pointer cannot be NULL." << endl;
		return;
	}
	
	// Update size of heap and initialize newly inserted node.
	*heap_size = *heap_size + 1;
	end = *heap_size - 1;	
	heap_to_update[end].key = std::numeric_limits<int>::min();
	
	// Update parent node with pointer to new node.
	if (end % 2 == 0)
	{
		heap_to_update[parent(end)].right = &heap_to_update[end];
	}
	else
	{
		heap_to_update[parent(end)].left = &heap_to_update[end];
	}
	
	heap_increase_key(heap_to_update, *heap_size, end, key); 
}

void construct_heap(int *input_array, unsigned int array_size,
	HeapNode *output_heap)
{
	if (input_array == NULL || output_heap == NULL)
	{
		cout << "Pointer is NULL" << endl;
		return;
	}

	/* Construct nodes of leaves with pointer to its children initialized to
	NULL. */
	for (size_t i = (array_size - 1); i >= (array_size / 2); i--)
	{
		output_heap[i].key = input_array[i];
		output_heap[i].index = i;
		output_heap[i].left = NULL;
		output_heap[i].right = NULL;
	}
	
	// Construct remaining nodes and update pointer to its children.
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

	// Print header of table.
	for (size_t i = 0; i < HEAP_DISPLAY_FIELDS_LENGTH; i++)
	{
		HeapPrintStr((header[i].field).c_str());
	}
	
	cout << endl;
	
	// Print body of table.
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
	
	if (argc >= HEAP_MAX_ELEMENTS)
	{
		cerr << "Maximum allowed number of input elements is " <<
			HEAP_MAX_ELEMENTS << endl;
		return ERR_OVERFLOW_OF_NUMBER_OF_ARGUMENTS;
	}
	
	array_size = argc - 1;
	input_array = static_cast<int *>(calloc(array_size, sizeof(int)));
	output_heap =
		static_cast<HeapNode *>(calloc(HEAP_MAX_ELEMENTS, sizeof(HeapNode)));
	
	for (size_t i = 0; i < array_size; i++)
	{
		std::string curr_argv = argv[i + 1];
		input_array[i] = std::stoi(curr_argv);
	}

	construct_heap(input_array, array_size, output_heap);
	
	title = "Unsorted";
	display_heap(title, output_heap, array_size);
	
	// max_heapify(output_heap, array_size, 1);	
	// title = "Max-heapify at Index 1";
	
	// build_max_heap(output_heap, array_size);
	// title = "Build-max-heap";
	
	heap_sort(output_heap, array_size);	
	title = "Heapsort: max-heap";
	
	// title = "Heap-extract-max";
	// cout << "Max value of key: " << heap_extract_max(output_heap, &array_size)
		// << endl;
	
	// heap_increase_key(output_heap, array_size, 8, 15);
	// title = "Heap-increase-key";
	
	// max_heap_insert(output_heap, &array_size, 15);
	// title = "Max-heap-insert";

	display_heap(title, output_heap, array_size);
	
	return SUCCESS;
}
	
	