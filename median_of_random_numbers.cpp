/* Numbers are randomly generated and stored into an (expanding) array. How
would you keep track of the median? */

#include "median_of_random_numbers.h"

using namespace std;

// Usage: <executable> count_of_random_numbers
int main(int argc, char **argv)
{
	int *input_array = NULL;
	unsigned int count, middle;
	int median;
	
	count = std::stoi(argv[1]);	
	input_array = static_cast<int *>(calloc(count, sizeof(int)));
	
	if (argc < 0)
	{
		cerr << "Insufficient number of input elements." << endl;
		return ERR_INSUFFICIENT_NUMBER_OF_ARGUMENTS;
	}
	
	for (size_t i = 0; i < count; i++)
	{
		input_array[i] = std::rand();
	}
	
	cout << "Before sorting:" << endl;
	
	for (size_t i = 0; i < count; i++)
		cout << input_array[i] << endl;
	
	sort_integers_ascending(input_array, count);
	
	cout << "After sorting:" << endl;
	
	for (size_t i = 0; i < count; i++)
		cout << input_array[i] << endl;
		
	if (count % 2 == 0)
	{
		middle = count / 2 - 1;
		median = (input_array[middle] + input_array[middle + 1]) / 2;
	}
	else
	{
		middle = count / 2;
		median = input_array[middle];
	}
		
	cout << "Median: " << median << endl;
	
	return SUCCESS;
}
	
	