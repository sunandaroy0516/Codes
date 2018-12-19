/* Implement binary search tree and associated operations */

#ifndef __BINARY_SEARCH_TREE__
#define __BINARY_SEARCH_TREE__

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

#include "error_codes.h"

class Node
{
	int key;
	std::vector<std::string> value;
	Node *left;
	Node *right;
	unsigned int index;
	
public:
	static unsigned int key_index;

	static void display_tree(Node *);
	Node * search_key(int);
	static void insert_key(int, Node *);
	void update_value(int, Node *, std::string);
	Node * get_head();
};

#endif