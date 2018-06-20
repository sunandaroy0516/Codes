/* A ransom note can be formed by cutting words out of a magazine to form a new
sentence. How would you figure out if a ransom note (represented as a string)
can be formed from a given magazine (string)? */

#ifndef __RANSOM_NOTE_FROM_MAGAZINE__
#define __RANSOM_NOTE_FROM_MAGAZINE__

#include <iostream>
#include <ctype.h>
#include <string.h>
#include <string>
#include <cstdio>
#include <map>
#include "error_codes.h"

#define MAX_ARRAY_SIZE	100
#define MAX_WORD_COUNT	20

typedef struct __PHRASE__
{
	std::string word[MAX_WORD_COUNT];
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

#endif

