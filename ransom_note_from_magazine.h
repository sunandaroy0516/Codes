/* A ransom note can be formed by cutting words out of a magazine to form a new
sentence. How would you figure out if a ransom note (represented as a string)
can be formed from a given magazine (string)? */

#ifndef __RANSOM_NOTE_FROM_MAGAZINE__
#define __RANSOM_NOTE_FROM_MAGAZINE__

#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>
#include <cstdlib>

#include "error_codes.h"

#define MAX_WORD_SIZE	50
#define MAX_WORD_COUNT	50

typedef struct __PHRASE__
{
	char word[MAX_WORD_COUNT][MAX_WORD_SIZE];
	unsigned int word_count;
} Phrase;

/*
Input	:	String to parse
Output	:	Pointer to a Phrase object
Returns	:	None
 */
void construct_phrase(std::string, Phrase *);

/*
Input	:	Pointer to a Phrase object
Returns	:	None
 */
void display_phrase(Phrase *);

/*
Input1	:	Pointer to a Phrase object
Input2	:	Pointer to a Phrase object
Returns	:	None
 */
void compare_phrases(Phrase *, Phrase *);

/*
Input	:	Pointer to a Phrase object
Returns	:	None
 */
void display_frequency(Phrase *);

#endif

