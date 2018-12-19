/* Implement binary search tree and associated operations */

#include "binary_search_tree.h"

using namespace std;

static void Node::insert_key(int num, Node *head)
{
	Node *current = NULL;
	
	if(head == NULL)
	{
		head->key = num;
		head->left = NULL;
		head->right = NULL;
	}
	else
	{
		if(num == head->key)
		{
			cout << "Key exists already!" << endl;
		}
		else if(num < key)
		{
			if(head->left == NULL)
			{
				head->left = new Node;
				head->left->key = num;
				head->left->left = NULL;
				head->left->right = NULL;
			}
			else
			{
				Node::insert_key(num, head->left);
			}
		}
		else
		{			
			if(head->right == NULL)
			{
				head->right = new Node;
				head->right->key = num;
				head->right->left = NULL;
				head->right->right = NULL;				
			}
			else
			{
				Node::insert_key(num, head->right);
			}
		}
	}
	cout<<"key: "<<head->key;
	if(head->left != NULL)
		cout<<", left: "<<head->left->key;
	if(head->right != NULL)
		cout<<", right: "<<head->right->key<<endl;
}

static void Node::display_tree(Node *root)
{
	
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
	
	btree = new Node[keys_cnt];
	
	for(i = 0; i < keys_cnt; i++)
	{
		Node::insert_key(keys[i], btree);
	}
	
	Node::display_tree(btree);
	
	delete btree;
	free(keys);
	
	return SUCCESS;
}