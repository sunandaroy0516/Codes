/* Given a smaller string s and a bigger string b, design an algorithm to find 
all permutations of the shorter string within the longer one. Print the
location of each permutation. */

#ifndef __COUNT_PERMUTATIONS_OF_SUBSTRING__
#define __COUNT_PERMUTATIONS_OF_SUBSTRING__

#include <iostream>
#include <string>

typedef struct
{
	char key;
	unsigned int value;
} Frequency;

/* 
Input	:	Pointer to a string
Output1	:	Pointer to an array of Frequency objects
Output2 :	Count of unique keys
Returns	:	None
 */
void construct_frequency_map(string &, Frequency *, unsigned int *);

/* 
Input1	:	Pointer to an array of Frequency objects for smaller string
Input2	:	Pointer to an array of Frequency objects for bigger string
Returns	:	Boolean result
 */
bool check_if_smaller_can_exist_in_bigger(Frequency *, Frequency *);

/* 
Input	:	Pointer to an array of Frequency objects for a string
Returns	:	Character result
 */
char find_char_with_min_freq(Frequency *);

/* 
Input1	:	Pointer to a string
Input2	:	Pointer to an array of Frequency objects for substring
Input3	:	Length of string for which permutation is to be found
Returns	:	None
 */
void check_for_valid_permutation(string *,	Frequency *,	unsigned int);

#endif                                                                        