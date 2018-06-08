/* Given a smaller string s and a bigger string b, design an algorithm to find 
all permutations of the shorter string within the longer one. Print the
location of each permutation. */

#include "count_permutations_of_substring.h"

using namespace std;

void construct_frequency_map(std::string window_str, Frequency *freq_map,
	unsigned int *keys_count)
{
	if (freq_map == NULL)
	{
		cerr << "Pointer to freq_map is NULL" << endl;
		return;
	}
	
	for (size_t i = 0; i < window_str.size(); i++)
	{
		bool match_found = false;
		unsigned int curr_keys_count = *keys_count;

		for (size_t j = 0; j < curr_keys_count; j++)
		{
			if (window_str[i] == freq_map[j].key)
			{
				freq_map[j].value++;
				match_found = true;
				break;
			}
		}
		
		if (match_found == false)
		{
			freq_map[curr_keys_count].key = window_str[i];
			(freq_map[curr_keys_count].value)++;
			(*keys_count)++;
		}
	}
}

bool check_if_smaller_can_exist_in_bigger(Frequency *s_freq_map, unsigned int
	s_keys_count, Frequency *b_freq_map, unsigned int b_keys_count)
{
	if (s_freq_map == NULL || b_freq_map == NULL)
	{
		cerr << "Pointer to freq_map is NULL" << endl;
		return false;
	}
	
	bool match_found = false;

	for (size_t i = 0; i < s_keys_count; i++)
	{		
		for (size_t j = 0; j < b_keys_count; j++)
		{
			if (s_freq_map[i].key == b_freq_map[j].key && s_freq_map[i].value
				<= b_freq_map[j].value)
			{
				match_found = true;
				break;
			}
		}
		
		if (match_found == false)
			break;
	}
	
	return match_found;
}

char find_char_with_min_freq(Frequency *freq_map, unsigned int keys_count)
{
	char key_with_min_freq = numeric_limits<char>::min();
	unsigned int min_freq = numeric_limits<unsigned int>::max(); 
	
	for (size_t i = 0; i < keys_count; i++)
	{
		if (freq_map[i].value < min_freq)
		{
			min_freq = freq_map[i].value;
		}
	}
	
	for (size_t i = 0; i < keys_count; i++)
	{
		if (freq_map[i].value == min_freq)
		{
			key_with_min_freq = freq_map[i].key;
			break;
		}
	}

	return key_with_min_freq;
}

void check_for_valid_permutation(unsigned int window_middle_pos,
	std::string window_of_substrs, Frequency *s_freq_map,
	unsigned int s_length, unsigned int s_keys_count)
{
	for (size_t i = 0; i < window_of_substrs.size(); i++)
	{
		unsigned int curr_keys_count = 0;		
		Frequency *curr_freq_map = NULL;		
		curr_freq_map = (Frequency *)calloc(s_length, sizeof(Frequency));
		std::string curr_substr = window_of_substrs.substr(i, s_length);
		construct_frequency_map(curr_substr, curr_freq_map, &curr_keys_count);

		if (check_if_equal(curr_freq_map, curr_keys_count, s_freq_map,
			s_keys_count) == true)
		{
			if (window_middle_pos > s_length)
				cout << window_middle_pos - s_length + i + 1 << endl;
			else
				cout << i << endl;
		}		
		
		free(curr_freq_map);
	}
}

bool check_if_equal(Frequency *first_freq_map, unsigned int first_keys_count,
	Frequency *second_freq_map, unsigned int second_keys_count)
{
	bool is_equal = false;
	
	if (first_keys_count == second_keys_count)
	{
		bool key_matches = true;

		for (size_t i = 0; i < first_keys_count && key_matches == true; i++)
		{
			key_matches = false;
			Frequency curr_first_freq = first_freq_map[i];

			for (size_t j = 0; j < first_keys_count; j++)
			{
				if (curr_first_freq.key == second_freq_map[j].key &&
					curr_first_freq.value == second_freq_map[j].value)
				{
					key_matches = true;
					break;
				}
			}
		}
		
		is_equal = key_matches;
	}
	
	return is_equal;
}

void calculate_offsets(unsigned int bigger_str_pos,
	unsigned int bigger_str_len, unsigned int substr_len,
	unsigned int *start, unsigned int *length)
{
	unsigned int end;
	
	if (bigger_str_pos < substr_len)
	{
		*start = 0;
	}
	else
	{
		*start = bigger_str_pos - substr_len + 1;
	}
	
	if (bigger_str_pos > (bigger_str_len - substr_len))
	{
		end = bigger_str_len;
	}
	else
	{
		end = bigger_str_pos + substr_len;
	}
	
	*length = end - *start;
}

// Usage: <executable> smaller_string bigger_string
int main(int argc, char **argv)
{
	std::string smaller, bigger, window_of_substrs;
	unsigned int s_length, s_keys_count, b_length, b_keys_count, b_pos;
	size_t window_start, window_length;
	bool exists;
	char s_min_freq_char;
	std::string::iterator it;
	Frequency *s_freq_map = NULL;	
	Frequency *b_freq_map = NULL;	
	
	if (argc < 3)
	{
		cerr << "Invalid number of arguments" << endl;
		return ERR_INVALID_NUMBER_OF_ARGUMENTS;
	}
	
	smaller = argv[1];
	s_length = smaller.length();	
	bigger = argv[2];
	b_length = bigger.length();
	
	if (s_length > b_length)
	{
		cerr << "Invalid length of smaller string" << endl;
		return ERR_INVALID_LENGTH_OF_SMALLER_STRING;
	}
		
	s_freq_map = (Frequency *)calloc(s_length, sizeof(Frequency));
	s_keys_count = 0;
	construct_frequency_map(smaller, s_freq_map, &s_keys_count);
	b_freq_map = (Frequency *)calloc(b_length, sizeof(Frequency));
	b_keys_count = 0;
	construct_frequency_map(bigger, b_freq_map, &b_keys_count);
	
	if (s_keys_count > b_keys_count)
	{
		cerr << "Insufficient number of unique characters in bigger string";
		return ERR_INSUFFICIENT_NUMBER_OF_KEYS_IN_BIGGER_STRING;
	}
	
	exists = check_if_smaller_can_exist_in_bigger(s_freq_map, s_keys_count,
		b_freq_map, b_keys_count);
	
	if (!exists)
	{
		cerr << "Smaller string cannot exist in bigger string" << endl;
		return ERR_SMALLER_STRING_CANNOT_EXIST_IN_BIGGER_STRING;
	}

	s_min_freq_char = find_char_with_min_freq(s_freq_map, s_keys_count);

	b_pos = 0;
	while (b_pos < b_length)
	{
		if (bigger[b_pos] == s_min_freq_char)
		{	
			calculate_offsets(b_pos, b_length, s_length, &window_start,
				&window_length);
			window_of_substrs = bigger.substr(window_start,	window_length);			
			check_for_valid_permutation(b_pos, window_of_substrs, s_freq_map,
				s_length, s_keys_count);			
		}
		b_pos++;
	}
	
	free(s_freq_map);
	free(b_freq_map);

	return 0;
}