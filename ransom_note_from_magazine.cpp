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

	para = static_cast<char *>(malloc(MAX_WORD_SIZE * MAX_WORD_COUNT * sizeof(char)));
	FILE *fp = std::fopen(text_file, "r");
	char_count = 0;

	// Get the number of characters in text_file.
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

	// Extract array of words from list of characters.
	while (i < char_count)
	{
		current = i;
		word_size = 0;

		// Get size of current word.
		while (!isspace(para[i]) && isprint(para[i]))
		{
			word_size++;
			i++;
		}

		if (word_size > 0)
		{
			// Reset start position of reading characters to old value.
			word = static_cast<char *>(malloc(word_size * sizeof(char)));
			// Extract current word.
			strncpy(word, &para[current], word_size);
			// Copy current word into string member of Phrase object.
			strcpy(p_txt->word[word_count], word);
			word_count++;
		}

		i++;
	}

	// Update current number of extracted words in Phrase object.
	p_txt->word_count = word_count;
}

void display_phrase(Phrase *p_txt)
{
	// Print list of all words and total word count.
	for (size_t i = 0; i < p_txt->word_count; i++)
		cout << p_txt->word[i] << endl;

	cout << "WORD COUNT: " << p_txt->word_count << endl;
}

void display_frequency(Phrase *p_txt)
{
}

/*void compare_phrases(Phrase *p1_txt, Phrase *p2_txt)
{
	bool wfound;
	unsigned int i, j, wc1, wc2, cnt, c1, c2;
	std::map<std::string, int> map1;
	std::map<std::string, int> map2;
	std::string word, w1, w2;

	if (p1_txt == NULL || p2_txt == NULL)
	{
		cerr << "Pointer cannot be NULL." << endl;
		return;
	}

	wc1 = p1_txt->word_count;
	wc2 = p2_txt->word_count;

	if (wc1 == 0 || wc2 == 0)
	{
		cerr << "Word count cannot be 0." << endl;
		return;
	}

	for (i = 0; i < wc1; i++)
	{
		cnt = 0;
		word = p1_txt->word[i];

		for (j = i; j < wc1; j++)
		{
			if (word == p1_txt->word[j])
				cnt++;
		}

		map1[word] = cnt;
	}

	for (i = 0; i < wc2; i++)
	{
		cnt = 0;
		word = p2_txt->word[i];

		for (j = i; j < wc2; j++)
		{
			if (word == p2_txt->word[j])
				cnt++;
		}

		map2[word] = cnt;
	}

	cout << "Key: " << "Value" << endl;

	for (auto it = map2.begin(); it != map2.end(); it++)
		cout << it->first << ": " << it->second << endl;

	if (wc1 < wc2)
	{
		wfound == true;
		for (auto it1 = map1.begin(); it1 != map1.end(); it1++)
		{
			w1 = it1->first;
			c1 = it1->second;

			for (auto it2 = map2.begin();
				it2 != map2.end() && wfound == true; it2++)
			{
				wfound = false;

				if (it2->first == w1 && it2->second >= c1)
					wfound = true;
			}

			if (wfound == true)
				cout << "String 1 can be formed from string 2." << endl;
		}
	}
	else
	{
		wfound == true;
		for (auto it2 = map2.begin(); it2 != map2.end(); it2++)
		{
			w2 = it2->first;
			c2 = it2->second;

			for (auto it1 = map1.begin();
				it1 != map1.end() && wfound == true; it1++)
			{
				wfound = false;

				if (it1->first == w2 && it1->second >= c2)
					wfound = true;
			}

			if (wfound == true)
				cout << "String 2 can be formed from String 1." << endl;
		}
	}
}*/

// Usage: <executable> ransom.txt magazine.txt
int main(int argc, char **argv)
{
	Phrase *p_ran = NULL;
	Phrase *p_mag = NULL;

	if (argc < 3)
	{
		cerr << "Insufficient number of arguments." << endl;
		return ERR_INSUFFICIENT_NUMBER_OF_ARGUMENTS;
	}

	p_ran = static_cast<Phrase *>(malloc(sizeof(Phrase)));
	cout << "Ransom: " << endl;
	construct_phrase(argv[1], p_ran);
	display_phrase(p_ran);
	display_frequency(p_ran);

	p_mag = static_cast<Phrase *>(malloc(sizeof(Phrase)));
	cout << "Magazine: " << endl;
	construct_phrase(argv[2], p_mag); //todo: check parsing of special characters.
	display_phrase(p_mag);
	display_frequency(p_mag);

	//compare_phrases(p_ran, p_mag);

	return SUCCESS;
}
