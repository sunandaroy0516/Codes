/*
 * linkedlist.c : Implement linked list operations.
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

/* Definition of node structure and pointer to node structure. */
typedef struct Node
{
    int value;
    struct Node *prev, *next;

} myNode, *myNodePtr;


/*
 * Description: Create a single node object.
 * Arguments  : Integer.
 * Returns    : Address of node object.cd Down
 */
myNodePtr create_node(int value)
{
    /* Allocate memory for object and store value. */
    myNodePtr elem = malloc(sizeof(myNode));
    elem->value = value;

    return elem;
}


/*
 * Description: Create a linked list.
 * Arguments  : None.
 * Returns    : Address to the beginning of linked list.
 */
myNodePtr create_linked_list()
{
    int value, cnt = 0, num;
    /* Pointer to store address of current node. */
    myNodePtr list = NULL;
    /* Pointer to store address of first node. */
    myNodePtr head = NULL;

    printf("Create linked list.\n");
    printf("Enter no. of values to insert: ");
    scanf("%d", &num);

    printf("Enter values:\n");
    while(cnt < num)
    {
        scanf("%d", &value);
        myNodePtr elem = create_node(value);
        if(cnt == 0)
        {

	        /*
			 * If the list is empty, set head and current node to
			 * element. Set current node's previous and next pointer to
			 * NULL.
			 */
            head = elem;
            list = elem;
            list->prev = NULL;
            list->next = NULL;
        }
        else
        {
			/*
			 * If the list is non-empty, set element's previous pointer
			 * to current node. Set element's next pointer to NULL.
			 * Set current node's next pointer to element. Set current
			 * node to element.
			 */
            elem->prev = list;
            elem->next = NULL;
            list->next = elem;
            list = list->next;
        }

        cnt++;
    };

    return head;
}


/*
 * Description: Display a linked list.
 * Arguments  : Pointer to beginning of linked list.
 * Returns    : None.
 */
void display_linked_list(myNodePtr head)
{
	myNodePtr list = head;
	printf("Display linked list.\n");
	while(list != NULL)
	{
		printf("{address: %p, value: %d}\n", list, list->value);
		list = list->next;
	}
}


/*
 * Description: Insert an element at beginning of given linked list.
 * Arguments  : Pointer to beginning of linked list, element to be
 * 				inserted.
 * Returns    : Pointer to beginning of updated linked list.
 */
myNodePtr insert_element_begin(myNodePtr head, int val)
{
	myNodePtr list = create_node(val);
	list->next = head;

	return list;
}


/*
 * Description: Insert an element at end of given linked list.
 * Arguments  : Pointer to beginning of linked list, element to be
 * 				inserted.
 * Returns    : Ponter to beginning of updated linked list.
 */
myNodePtr insert_element_end(myNodePtr head, int val)
{
	myNodePtr elem = create_node(val);
	myNodePtr list = head;

	while(list->next != NULL)
		list = list->next;

	list->next = elem;
	elem->next = NULL;

	return head;
}


/*
 * Description: Calculate minimum value of given linked list.
 * Arguments  : Pointer to beginning of linked list.
 * Returns    : Minimum value of linked list.
 */
 int calc_min_val(myNodePtr head)
 {
    myNodePtr list = head;
    int min = list->value;

    while(list->next != NULL)
    {
        list = list->next;
        if(min > list->value)
            min = list->value;
    }

    return min;
 }

/*
 * Description: Calculate maximum value of given linked list.
 * Arguments  : Pointer to beginning of linked list.
 * Returns    : Maximum value of linked list.
 */
int calc_max_val(myNodePtr head)
 {
    myNodePtr list = head;
    int max = list->value;

    while(list->next != NULL)
    {
        list = list->next;
        if(max < list->value)
            max = list->value;
    }

    return max;
 }


int main()
{
	int val, min, max;

    myNodePtr head = create_linked_list();
    display_linked_list(head);

    printf("Enter value to be inserted at the beginning:\n");
    scanf("%d", &val);
    head = insert_element_begin(head, val);
	display_linked_list(head);

	printf("Enter value to be inserted at the end:\n");
    scanf("%d", &val);
    head = insert_element_end(head, val);
    display_linked_list(head);

    min = calc_min_val(head);
    printf("Min = %d\n", min);

    max = calc_max_val(head);
    printf("Max = %d\n", max);

	free(head);

    return 0;
}
