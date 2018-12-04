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
		printf("No. of keys cannot be zero.\n");
		return NULL;
	}
	
	while(cnt < num)
	{
		printf("%d. Enter key value:\n", cnt+1);
		scanf("%d", &key);
		
		/* Initialize current node to head of BST. */
		bstcurr = bsthead;
		
		if(cnt == 0)
		{
			/* Store head pointer info. */
			bsthead->key = key;
			bsthead->parent = NULL;
			bsthead->lchild = NULL;
			bsthead->rchild = NULL;
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
	myNodePtr bstcurr = bsthead;
	if(bstcurr->lchild != NULL)
	{
		while(bstcurr->lchild != NULL)
			bstcurr = bstcurr->lchild;
	}
	
	printf("Inorder traversal of BST.\n");
	
	if(bstcurr != bsthead)
	{
		/* Display subtree to the left of root. */
		printf("%d\t->\t", bstcurr->key);
		while(bstcurr->parent != NULL)
		{			
			bstcurr = bstcurr->parent;	
			printf("%d\t->\t", bstcurr->key);
			if(bstcurr->rchild != NULL)
			{
				printf("%d\n", (bstcurr->rchild)->key);
			}
		}
	}
	else
	{
		/* Display subtree to the right of root. */
		printf("%d\t", bstcurr->key);
		if(bstcurr->rchild != NULL)
		{
			printf("->\t%d\n", (bstcurr->rchild)->key);
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

