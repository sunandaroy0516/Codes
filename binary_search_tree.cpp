/* Implement binary search tree and associated operations */

#include "binary_search_tree.h"

using namespace std;

Node* Node::insert_key(int num, Node *head)
{
	Node *current = NULL;
	
	if(head == NULL)
	{
		key = num;
		left = NULL;
		right = NULL;
		head = this;
		current = this;
	}
	else
	{
		if(num == key)
		{
			current = head;
		}
		else if(num < key)
		{
			if(left == NULL)
			{
				left = new Node;
				left->key = num;
				left->left = NULL;
				left->right = NULL;
				current = left;
			}
			else
			{
				current = insert_key(num, left);
			}
		}
		else
		{			
			if(right == NULL)
			{
				right = new Node;
				right->key = num;
				right->left = NULL;
				right->right = NULL;
				current = right;
			}
			else
			{
				current = insert_key(num, right);
			}
		}
	}
}

// Usage: <executable> [list of keys]
int main(int argc, char **argv)
{
	int i;
	unsigned int keys_cnt;
	int *keys = NULL;
	Node *head = NULL;	
	Node *btree = NULL;
	
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
	
	btree = new Node[keys_cnt];
	
	for(i = 0; i < keys_cnt; i++)
	{
		btree[i].insert_key(keys[i], head);
	}
	
	delete btree;
	free(keys);
	
	return SUCCESS;
}