/*
INSERTION_SORT(A)
for j <- 2 to length[A]
	do key <- A[j]
		// Insert A[j] into the sorted sequence A[1..j-1]
		i <- j - 1
		while i > 0 and A[i] > key
			do A[i + 1] <- A[i]
				i <- i - 1
		A[i + 1] <- key
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_INT_DIGITS 10

int main(int argc, char **argv)
{
	// Check if array length is valid.
	if (argc < 2)
	{
		printf("Need atleast 1 element as array input.\n");
		exit(-1);
	}
	
	unsigned int array_length = argc - 1;

	int *sorted = NULL;
	sorted = malloc(array_length * sizeof(int));
	
	if (NULL == sorted)
		printf("Input array is not allocated.");
	
	// Check if input array elements are valid integers.
	for (int i = 1; i < array_length; i++)
	{
		sorted[i] = atoi(argv[i]);
		char *filter = NULL;
		filter = malloc(array_length * sizeof(char) * MAX_INT_DIGITS);
		sprintf(filter, "%i", sorted[i]);
		
		if (argv[i] != filter)
		{
			printf("Input array contains invalid integer value at index %i.\n",
				i);
		}
		else
		{
			printf("Input array element at index %i = %i.\n", i, sorted[i]);
		}
	}
	
	// Sort in place.
	for (int j = 1; j < array_length; j++)
	{
		int key = sorted[j];
		int i = j - 1;
		while ((i > 0) && (sorted[i] > key))
		{
			// Right-shift each array element by one index.
			sorted[i + 1] = sorted[i];
			i--;
		}		
		sorted[i + 1] = key;
	}
	
	// Display sorted array.
	for (int i = 0; i < array_length; i++)
		printf("Output array element at index %i = %i.\n", i, sorted[i]);
	
	return 0;
}

