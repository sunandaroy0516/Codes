/* Implement binary search tree and associated operations */

#include "binary_search_tree.h"

using namespace std;

unsigned int Node::key_index;

void Node::insert_key(int num, Node *head)
{
	if(!key_index)
	{
		head->key = num;
		head->left = NULL;
		head->right = NULL;	
	}
	else if(num == head->key)
	{
		cout << "Key exists already!" << endl;
		return;
	}
	else if(num < head->key)
	{
		head->left = new Node;
		head->left->key = num;
		head->left->left = NULL;
		head->left->right = NULL;
	}
	else
	{			
		head->right = new Node;
		head->right->key = num;
		head->right->left = NULL;
		head->right->right = NULL;		
	}
	
	key_index++;
}

void Node::display_tree(Node *root)
{
	if(!key_index)
	{
		cout << "Binary search tree is empty" << endl;
	}	
	else
	{
		cout << "Key\tLeft Key\tRight Key" << endl;		
		cout << root->key << "\t" << root->left->key << "\t" << root->right->key << endl;
	}
}

// Usage: <executable> [list of keys]
int main(int argc, char **argv)
{
	int i;
	unsigned int keys_cnt;
	int *keys = NULL;
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
	
	btree = new Node;
	
	for(i = 0; i < keys_cnt; i++)
	{
		Node::insert_key(keys[i], btree);
	}
	
	Node::display_tree(btree);
	
	delete btree;
	free(keys);
	
	return SUCCESS;
}