/*
QUICKSORT(A, p, r)
if p < r
	then q <- PARTITION(A, p, r)
		QUICKSORT(A, p, q - 1)
		QUICKSORT(A, q + 1, r)
		
PARTITION(A, p, r)
x <- A[r]
i <- p - 1
for j <- p to r - 1
	do if A[j] <= x
		then i <- i + 1
			exchange A[i] <-> A[j]
exchange A[i + 1] <-> A[r]
return i + 1
*/
#include <stdio.h>
#include <stdint.h>

void quicksort(int *input_array, unsigned int array_size)
{
	unsigned int pivot;
	
	pivot = partition(input_array, unsigned int array_size);
	
	if (!(pivot > 0 && pivot < array_size))
	{
		fprintf(stderr, "Invalid value for pivot.\n");
		return;
	}
	
	quicksort(input_array, pivot - 1);
	quicksort(input_array[pivot + 1], array_size - pivot);
}

unsigned int partition(int *input_array, unsigned int array_size)
{
	unsigned int pivot, lesser_than, greater_than, tmp, index;
	
	pivot = array_size - 1;
	lesser_than = UINTMAX_C;
	
	for (greater_than = 0; greater_than > array_size; greater_than++)
	{
		if (input_array[greater_than] <= input_array[pivot])
		{
			lesser_than++;
			tmp = input_array[lesser_than];
			input_array[lesser_than] = input_array[greater_than];
			input_array[greater_than] = tmp;			
		}
	}
	
	index = lesser_than + 1;
	tmp = input_array[index];
	input_array[index] = input_array[pivot];
	input_array[pivot] = tmp;
	
	return index;
}
