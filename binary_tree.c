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

/*
 * Description: Create a binary search tree from user input.
 * Arguments  : None.
 * Returns    : Pointer to head of BST.
 */
myNodePtr create_bst()
{
	int num, key, cnt = 0;

	/* Pointer to head of BST. */
	myNodePtr head = malloc(sizeof(myNode));
	/* Pointer to current node of BST. */
	myNodePtr curr = malloc(sizeof(myNode));
	/* Pointer to parent node of current node. */
	myNodePtr parent = malloc(sizeof(myNode));

	/* User input. */
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

		/* Initialize current node to head of BST. */
		curr = head;

		if(cnt == 0)
		{
			/* Store head pointer info. */
			head->key = key;
			head->parent = NULL;
			head->lchild = NULL;
			head->rchild = NULL;
		}
		else
		{
			//Traverse to the child node where key needs to be
			//inserted.
			while(1)
			{
				/* Store parent node info. */
				parent = curr;

				if(key <= curr->key)
				{
					if(curr->lchild != NULL)
						curr = curr->lchild;
				}
				else
				{
					if(curr->rchild != NULL)
						curr = curr->rchild;
				}

				/* Break out of loop if it is end of traversal. */
				if(parent == curr)
					break;
			}

			/* Select left or right child node for inserting key. */
			if(key <= curr->key)
			{
				curr->lchild = malloc(sizeof(myNode));
				curr = curr->lchild;
			}
			else
			{
				curr->rchild = malloc(sizeof(myNode));
				curr = curr->rchild;
			}

			/* Store destination node info. */
			curr->key = key;
			curr->parent = parent;
			curr->lchild = NULL;
			curr->rchild = NULL;
		}

		cnt++;
	}

	/* NOTE: If local pointers are freed, then values won't be retained across
	function calls. */
	return head;
}

/*
 * Description: Key of the root of subtree is printed between the values
 * 				in its left subtree and those in its right subtree.
 * Arguments  : Pointer to head of BST.
 * Returns    : None.
 */
void traverse_inorder(myNodePtr bsthead)
{
	printf("Inorder traversal of BST.\n");

	/* Error check for valid BST. */
	if(bsthead == NULL)
	{
		printf("Error: BST does not exist.\n");
		return;
	}

	/* Traverse to node with smallest key value. */
	myNodePtr bstcurr = bsthead;

	if(bstcurr->lchild != NULL)
	{
		while(bstcurr->lchild != NULL)
			bstcurr = bstcurr->lchild;
	}

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
		printf("%d\t->\t", bstcurr->key);

		if(bstcurr->rchild != NULL)
		{
			bstcurr = bstcurr->rchild;

			while(1)
			{
				if (bstcurr->lchild == NULL && bstcurr->rchild == NULL)
				{
					break;
				}

				if(bstcurr->lchild != NULL)
				{
					printf("\t->\t%d", (bstcurr->lchild)->key);
				}

				printf("%d", bstcurr->key);

				if(bstcurr->rchild != NULL)
				{
					bstcurr = bstcurr->rchild;
					printf("\t->\t%d", bstcurr->key);

					if(bstcurr->rchild != NULL)
					{
						printf("\t->\t%d", (bstcurr->rchild)->key);
					}
				}

			}
		}
	}

	free(bstcurr);
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