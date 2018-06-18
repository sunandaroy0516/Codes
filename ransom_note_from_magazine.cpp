/* A ransom note can be formed by cutting words out of a magazine to form a new
sentence. How would you figure out if a ransom note (represented as a string)
can be formed from a given magazine (string)? */

#include "ransom_note_from_magazine.h"

using namespace std;

void construct_phrase(char *text_file, Phrase *p_txt)
{
	int c;
	unsigned int word_count, char_count, word_size, current, i, j;
	char *para = NULL;
	char *word = NULL;

	if (text_file == NULL || p_txt == NULL)
	{
		cerr << "Pointer is NULL." << endl;
		return;
	}
	
	para = static_cast<char *>(malloc(MAX_ARRAY_SIZE * sizeof(char)));
	FILE *fp = std::fopen(text_file, "r");
	char_count = 0;
	
	while ((c = fgetc(fp)) != EOF)
	{
		para[char_count] = c;
		char_count++;
	}

	if (std::ferror(fp))
	{ 
		cerr << "I/O error while reading from " << text_file << endl;
		return;
	}
	
	std::fclose(fp);	
	word_count = 0;
	i = 0;
	
	while (i < char_count)
	{
		current = i;
		word_size = 0;
		
		while (!isspace(para[i]) && i < char_count)
		{		
			word_size++;
			i++;
		}

		word = static_cast<char *>(malloc(word_size * sizeof(char)));
		i = current;
		j = 0;
		
		while (j < word_size)
		{
			word[j] = para[i];	
			i++;
			j++;
		}		
		
		p_txt->word[word_count] = word;
		word_count++;		
		i++;
	}
	
	p_txt->word_count = word_count;
}

void display_phrase(Phrase *p_txt)
{
	for (size_t i = 0; i < p_txt->word_count; i++)
		cout << p_txt->word[i] << endl;
	
	cout << "WORD COUNT: " << p_txt->word_count << endl;
}	

// Usage: <executable> ransom.txt magazine.txt
int main(int argc, char **argv)
{	
	Phrase *p_ran = NULL;

	if (argc < 3)
	{
		cerr << "Insufficient number of arguments." << endl;
		return ERR_INSUFFICIENT_NUMBER_OF_ARGUMENTS;
	}
	
	p_ran = static_cast<Phrase *>(malloc(sizeof(Phrase)));
	construct_phrase(argv[1], p_ran);
	display_phrase(p_ran);
	
	return SUCCESS;
}
