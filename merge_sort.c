/*
MERGE(A, p, q, r)
n1 <- q - p + 1
n2 <- r - q
// Create arrays L[1..n1 + 1] and R[1..n2 + 1]
for i <- 1 to n1
	do L[i] <- A[p + i - 1]
for j <- 1 to n2
	do R[j] <- A[q + j]
L[n1 + 1] <- inf
R[n2 + 1] <- inf
i <- 1
j <- 1
for k <- p to r
	do if L[i] <= R[j]
		then A[k] <- L[i]
			i <- i + 1
		else A[k] <- R[j]
			j <- j + 1
			
MERGE-SORT(A, p, r)
if p < r
	then q <- [(p + r)/2]
		MERGE-SORT(A, p, q)
		MERGE-SORT(A, q + 1, r)
		MERGE(A, p, q, r)
*/
#include <stdio.h>
#include <stdbool.h>

void compare_less(int *a, int *b)
{
	int temp;
	
	if (NULL == a || NULL == b)
	{
		printf("Input pointer cannot be NULL.\n");
		return;
	}

	if (a > b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}

void sort_numbers(int *input_array, unsigned int start_index,
	unsigned int end_index)
{
	unsigned int p, q, r, n1, n2, array_length;
	
	if (NULL == input_array)
	{
		printf("Pointer to input array cannot be NULL.\n");
		return;
	}

	// assumption is index starts at 0.
	array_length = end_index - start_index + 1;
	if (!array_length)
	{
		printf("Err: count for sort_numbers cannot be 0.\n");
		return;
	}
	if (1 == array_length)
	{
		printf("Warn: no sorting required for 1 no.\n");
		return;
	}
	if (2 == array_length)
	{
		compare_less(numbers[0], numbers[1]);
		return;
	}
	
	p = start_index;
	r = end_index;
	q = (p + r) / 2;
	n1 = q - p;
	n2 = r - q;

	sort_numbers(input_array[p], p, q);
	sort_numbers(input_array[q], q + 1, n1 + n2);
}

/* assumption is both left and right arrays are sorted and needs to be merged */
void merge_arrays(int *left, unsigned int left_length, int *right,
	unsigned int right_length, int *merged)
{
	size_t left_index, right_index, merged_index;
	int left, right;
	
	if (NULL == left || NULL == right)
	{
		printf("Pointer to arrays to be merged cannot be NULL.\n");
		return;
	}
	if (left_length - right_length > 1 || right_length - left_length > 1)
	{
		printf("Err: Failed to split input array into sub arrays.\n");
		return;
	}
	if (!left_length || !right_length)
	{
		printf("Warn: Atleast one of the input arrays have invalid length.\n");
		return;
	}

	merged_length = left_length + right_length;
	left_index = 0;
	right_index = 0;
	merged_index = 0;
	while (merged_index < merged_length)
	{
		left = *left[left_index];
		right = *right[right_index];
		if (left < right)
		{
			*merged[merged_index] = left;
			left_index++;
		}
		else
		{
			*merged[merged_index] = right;
			right_index++;
		}		
		merged_index++;
	}		
}		
		