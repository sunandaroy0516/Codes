/* Given a smaller string s and a bigger string b, design an algorithm to find 
all permutations of the shorter string within the longer one. Print the
location of each permutation. */

#include "count_permutations_of_substring.h"

using namespace std;

void construct_frequency_map(string *window_str, Frequency *freq_map)
{
}

bool check_if_smaller_can_exist_in_bigger(Frequency *s_freq_map,
	Frequency *b_freq_map)
{
}

char find_char_with_min_freq(Frequency *freq_map)
{
}

void check_for_valid_permutation(string *window_of_substrs,
	Frequency *s_freq_map,	unsigned int s_length)
{
}

// Usage: <executable> smaller_string bigger_string
int main(int argc, char **argv)
{
	string smaller, bigger, window_of_substrs;
	unsigned int s_length, b_length, b_pos;
	bool exists;
	char s_min_freq_char;
	string::iterator it;
	Frequency *s_freq_map = NULL;	
	
	// check for cerr exit flow 
	if (argc < 3)
		cerr << "Invalid number of arguments" << endl;
	
	smaller = argv[1];
	s_length = smaller.length();	
	bigger = argv[2];
	b_length = bigger.length();
	if (s_length > b_length)
		cerr << "Invalid length of smaller string" << endl;
		
	s_freq_map = calloc(s_length, sizeof(Frequency));
	construct_frequency_map(smaller, s_freq_map, s_keys_count);
	construct_frequency_map(bigger, b_freq_map, b_keys_count);
	
	if (s_keys_count > b_keys_count)
		cerr << "Insufficient number of unique characters in bigger_string";
	
	exists = check_if_smaller_can_exist_in_bigger(s_freq_map, b_freq_map);
	
	if (!exists)
		cerr << "Smaller string cannot exist in bigger string" << endl;

	s_min_freq_char = find_char_with_min_freq(s_freq_map);
	
	b_pos = 0;
	while (b_pos < b_length)
	{
		if (bigger[b_pos] == s_min_freq_char)
		{			
			window_of_substrs = bigger.substr(b_pos - s_length + 1,
				s_length * 2 - 1);
			check_for_valid_permutation(window_of_substrs, s_freq_map,
				s_length);			
			b_pos += s_length;
		}
		else
		{
			b_pos++;
		}
	}

	return 0;
}