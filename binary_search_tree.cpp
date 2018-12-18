/* Implement binary search tree and associated operations */

#include "binary_search_tree.h"

using namespace std;

// Usage: <executable> [list of keys]
int main(int argc, char **argv)
{
	int i;
	unsigned int keys_cnt;
	int *keys = NULL;
	
	if(argc < 2)
	{
		return ERR_INSUFFICIENT_NUMBER_OF_ARGUMENTS;
	}
	
	keys_cnt = argc - 1;
	keys = (int *)calloc(keys_cnt, sizeof(int));
	
	for(i = 0; i < keys_cnt; i++)
	{
		keys[i] = atoi(argv[i + 1]);
	}
	
	free(keys);
	
	return SUCCESS;
}