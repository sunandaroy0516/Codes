/* Given a smaller string s and a bigger string b, design an algorithm to find 
all permutations of the shorter string within the longer one. Print the
location of each permutation. */

#ifndef __COUNT_PERMUTATIONS_OF_SUBSTRING__
#define __COUNT_PERMUTATIONS_OF_SUBSTRING__

#include <iostream>
#include <string>
#include <limits>

#define MAX_LENGTH	4

typedef enum
{
	ERR_INVALID_NUMBER_OF_ARGUMENTS = -5,
	ERR_INVALID_LENGTH_OF_SMALLER_STRING = -4,
	ERR_NULL_POINTER = -3,
	ERR_INSUFFICIENT_NUMBER_OF_KEYS_IN_BIGGER_STRING = -2,
	ERR_SMALLER_STRING_CANNOT_EXIST_IN_BIGGER_STRING = -1,
	SUCCESS = 0
} ExitCode;

typedef struct
{
	char key;
	unsigned int value;
} Frequency;

/* 
Input	:	String to parse
Output1	:	Pointer to an array of Frequency objects
Output2 :	Pointer to count of unique keys
Returns	:	None
 */
void construct_frequency_map(std::string, Frequency *, unsigned int *);

/* 
Input1	:	Pointer to an array of Frequency objects for smaller string
Input2	:	Count of unique keys for smaller string
Input3	:	Pointer to an array of Frequency objects for bigger string
Input4	:	Count of unique keys for bigger string
Returns	:	Boolean result
 */
bool check_if_smaller_can_exist_in_bigger(Frequency *, unsigned int,
	Frequency *, unsigned int);

/* 
Input1	:	Pointer to an array of Frequency objects for a string
Input2	:	Count of unique keys for string
Returns	:	Character result
 */
char find_first_char_with_min_freq(Frequency *, unsigned int);

/* 
Input1	:	Position of center of window of substrings
Input2	:	Pointer to a window of substrings
Input3	:	Pointer to an array of Frequency objects for substring
Input4	:	Length of substring for which permutation is to be found
Input5	:	Count of unique keys for substring
Returns	:	None
 */
void check_for_valid_permutation(unsigned int, std::string, Frequency *, 
	unsigned int);
	
/* 
Input1	:	Pointer to an array of Frequency objects for first string
Input2	:	Count of unique keys for first string
Input3	:	Pointer to an array of Frequency objects for second string
Input4	:	Count of unique keys for second string
Returns	:	Boolean result
 */
bool check_if_equal(Frequency *, unsigned int, Frequency *, unsigned int);

/* 
Input1	:	Position in bigger string
Input2	:	Length of bigger string
Input3	:	Length of substring to extract
Output1	:	Start position of substring in bigger string
Output2 :	Length of substring in bigger string
Returns	:	None
 */
void calculate_offsets(unsigned int, unsigned int, unsigned int,
	unsigned int *,	unsigned int *);

#endif                                                                        