/* Print all possible integer solutions to the equation a^3 + b^3 = c^3 + d^3
		where a, b, c and d are integers between 1 and 100.*/

#include "sum_of_cubes_equality.h"

using namespace std;

// Usage: <executable> start end
int main(int argc, char **argv)
{
	unsigned int start, end, range, count, a, b, c, d;
	long long signed int expected;
	float tmpd;
	
	if (argc < 3)
		cerr << "Invalid number of argmuments" << endl;
	
	count = 0;
	start = atoi(argv[1]);
	end = atoi(argv[2]);

	if (start >= end)
		cerr << "Start is greater than end" << endl;
	
	range = end - start + 1;
	
	Pair *lPairs = NULL;
	lPairs = (Pair *)calloc(pow(range, 2), sizeof(Pair));
	
	if (!lPairs)
		cerr << "Memory allocation failed" << endl;
	
	// Populate all possible combinations of Pair objects.
	for (a = start; a <= end; a++)
	{
		for (b = a + 1; b <= end; b++)
		{
			lPairs[count].value[0] = a;
			lPairs[count].value[1] = b;
			count++;
		}
	}
	
	cout << "a\tb\tc\td" <<endl;
	// For each Pair object, construct unique combinations including value[2].
	for (int i = 0; i < count; i++)
	{	
		Pair current = lPairs[i];
		for (c = start; c <= end; c++)
		{
			if (!(c == current.value[0] || c == current.value[1]))
			{
				// Find expected value of cube of value[3].
				expected = pow(current.value[0], 3) + pow(current.value[1], 3) -
					pow(c, 3);
					
				if (expected > 0)
				{
					// Check if there is a natural no. for cube root of expected.
					tmpd = cbrt(expected);
					d = (unsigned int)tmpd;
					/* debug only
					cout<<expected<<": "<<current.value[0]<<","<<current.value[1]<<","<<c<<": "<<tmpd<<","<<d<<endl;
					*/
					if (pow(d, 3) == expected)
					{
						cout << current.value[0] << "\t" << current.value[1] <<
							"\t" << c << "\t" << d << endl;
					}
				}				
			}
		} 
	}
	
	return 0;
}