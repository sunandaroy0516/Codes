/*
 * binarytree.c : Implement binary search tree operations.
 *
 * Copyright 2015 Sunanda Roy
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */


#include <stdio.h>
#include <stdlib.h>

#include "error_codes.h"

typedef struct node
{
	int key;
	struct node *parent, *lchild, *rchild;

} myNode, *myNodePtr;

myNodePtr get_leftmost_child(myNodePtr current)
{
	if(current->lchild != NULL)
	{
		while(current->lchild != NULL)
			current = current->lchild;
	}
	else
	{
		printf("Left child does not exist.\n");
	}
	
	return current;
}

/*
 * Description: Create a binary search tree from user input.
 * Arguments  : None.
 * Returns    : Pointer to head of BST.
 */
myNodePtr create_bst()
{
	int num, key, cnt = 0;

	/* Pointer to head of BST. */
	myNodePtr bsthead = malloc(sizeof(myNode));
	/* Pointer to current node of BST. */
	myNodePtr bstcurr = malloc(sizeof(myNode));
	/* Pointer to parent node of current node. */
	myNodePtr parent = malloc(sizeof(myNode));

	/* User input. */
	printf("Create binary search tree.\n");
	printf("Enter no. of keys to insert:\n");
	scanf("%d", &num);

	if(num <= 0)
	{
		printf("Invalid no. of keys.\n");
		return NULL;
	}

	while(cnt < num)
	{
		printf("%d. Enter key value:\n", cnt+1);
		scanf("%d", &key);

		if(cnt == 0)
		{
			/* Store head pointer info. */
			bstcurr->key = key;
			bstcurr->parent = NULL;
			bstcurr->lchild = NULL;
			bstcurr->rchild = NULL;
			/* Initialize current node to head of BST. */
			bsthead = bstcurr;
		}
		else
		{
			//Traverse to the child node where key needs to be
			//inserted.
			while(num != 1)
			{
				/* Store parent node info. */
				parent = bstcurr;
				if(key <= bstcurr->key)
				{
					if(bstcurr->lchild != NULL)
						bstcurr = bstcurr->lchild;
				}
				else
				{
					if(bstcurr->rchild != NULL)
						bstcurr = bstcurr->rchild;
				}
				/* Break out of loop if it is end of traversal. */
				if(parent == bstcurr)
					break;
			}
			/* Select left or right child node for inserting key. */
			if(key <= bstcurr->key)
			{
				bstcurr->lchild = malloc(sizeof(myNode));
				bstcurr = bstcurr->lchild;
			}
			else
			{
				bstcurr->rchild = malloc(sizeof(myNode));
				bstcurr = bstcurr->rchild;
			}
			/* Store destination node info. */
			bstcurr->key = key;
			bstcurr->parent = parent;
			bstcurr->lchild = NULL;
			bstcurr->rchild = NULL;
		}
		cnt++;
	}

	return bsthead;
}

/*
 * Description: Key of the root of subtree is printed between the values
 * 				in its left subtree and those in its right subtree.
 * Arguments  : Pointer to head of BST.
 * Returns    : None.
 */
void traverse_inorder(myNodePtr bsthead)
{
	/* Traverse to node with smallest key value. */
	printf("Inorder traversal of BST.\n");
	
	myNodePtr bstcurr = get_leftmost_child(bsthead);

	if(bstcurr != bsthead)
	{
		/* Display subtree to the left of root. */
		printf("%d", bstcurr->key);
		while(bstcurr->parent != NULL)
		{
			bstcurr = bstcurr->parent;
			printf("\t->\t%d", bstcurr->key);
			if(bstcurr->rchild != NULL)
			{
				printf("\t->\t%d", (bstcurr->rchild)->key);
			}
		}
	}
	else
	{
		/* Display subtree to the right of root. */
		if(bstcurr->rchild != NULL)
		{			
			while(bstcurr != NULL)
			{
				bstcurr = bstcurr->rchild;
				if(bstcurr->lchild != NULL)
				{
					printf("\t->\t%d", (bstcurr->lchild)->key);
				}				
				printf("\t->\t%d", bstcurr->key);
				if(bstcurr->rchild != NULL)
				{
					printf("\t->\t%d", (bstcurr->rchild)->key);
				}	
			}	
		}
	}
}

int main()
{
	myNodePtr bsthead = create_bst();

	/* Error check for valid BST. */
	if(bsthead == NULL)
	{
		return ERR_NULL_POINTER;
	}

	traverse_inorder(bsthead);

	free(bsthead);

	return 0;
}

