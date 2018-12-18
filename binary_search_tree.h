/* Implement binary search tree and associated operations */

#ifndef __BINARY_SEARCH_TREE__
#define __BINARY_SEARCH_TREE__

class Node
{
	int key;
	std::vector<std::string>;
	Node *left;
	Node *right;
	
public:

	void display_tree(Node *);
	Node * search_key(int);
	Node * insert_key(int, Node *);
	void update_value(int, Node *, std::string);
	Node * get_head();
	Node * get_tail();

#endif