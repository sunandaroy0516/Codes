/*
Applicable for unsigned int array elements only.
A: Input array
B: Output array
k: Maximum value of an element in input array
COUNTING-SORT(A, B, k)
for i <- 0 to k
	do C[i] <- 0
for j <- 1 to length[A]
	do C[A[j]] <- C[A[j]] + 1
// C[i] now contains the no. of elements equal to i.
for i <- 1 to k
	do C[i] <- C[i] + C[i - 1]
// C[i] now contains the no. of elements less than or equal to i.
for j <- length[A] downto 1
	do B[C[A[j]] <- A[j]
		C[A[j]] <- C[A[j]] - 1
*/
#include <stdio.h>
#include <stdlib.h>

unsigned int find_max_element(unsigned int *array, unsigned int array_size)
{
	unsigned int max = 0;
	
	for (size_t i = 0; i < array_size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}			
	}
	
	return max;
}

void populate_filter_elements(unsigned int *filter_elements,
	unsigned int filter_elements_size, unsigned int *array,
	unsigned int array_size)
{
	unsigned int filter_i;
	
	// Store no. of occurences of each array element.
	for (size_t i = 0; i < array_size; i++)
	{
		filter_i = array[i];
		(filter_elements[filter_i])++;
	}
	
	/* Add no. of occurences of each element with no. of occurences of elements
		with value less than that element*/
	for (size_t j = 1; j < filter_elements_size; j++)
	{
		filter_elements[j] = filter_elements[j] + filter_elements[j - 1]; 
	}
}

void counting_sort(unsigned int *input_array, unsigned int array_size,
	unsigned int *output_array)
{
	unsigned int max, i, filter_i, output_i;
	unsigned int *filter_elements = NULL;
	
	max = find_max_element(input_array, array_size);
	
	filter_elements = calloc(max, sizeof(unsigned int));
	
	populate_filter_elements(filter_elements, max, input_array, array_size);

	for (i = array_size - 1; i >= 0; i--)
	{
		// Populate output array.
		filter_i = input_array[i];
		output_i = filter_elements[filter_i];
		output_array[output_i] = filter_i;
		
		// Decrement filter element.
		(filter_elements[filter_i])--;
	}
		
	free(filter_elements);	
}

void convert_to_uint(char **argv, unsigned int argc, unsigned int *array)
{
	for (size_t i = 0; i < argc; i++)
	{
		array[i] = atoi(argv[i]);
	}
}

int main(int argc, char **argv)
{
	unsigned int *input_array = NULL;
	unsigned int *output_array = NULL;
	
	input_array = malloc(sizeof(unsigned int) * argc);
	output_array = malloc(sizeof(unsigned int) * argc);
	
	convert_to_uint(argv, (unsigned int)argc, input_array);
	counting_sort(input_array, argc, output_array);
	
	printf(" Sorted array:\n");
	for (size_t i = 0; i < argc; i++)
	{
		printf("%u, ", output_array[i]);
	}
	printf(".\n");
	
	return 0;
}	
