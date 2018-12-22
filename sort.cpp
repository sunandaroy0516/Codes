/*
 * sort.cpp : Implementation of sorting algorithms
 * 
 * Copyright 2016 Sunanda Roy
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


#include <iostream>
#include <new>
#include <ctime>

using namespace std;

static int cnt; /* Number of entries to sort. */

class Sort
{	
	public:
	
	static void insertion(int []);
	static void merge(int []);
	static void merge_recursive(int [], int, int, int []);
	static void display(int []);
};


/* 
 * Description: Implementation of insertion sort algorithm. 
 * Arguments  : Pointer to head of list to be sorted.
 * Returns    : None.
 */
void Sort::insertion(int list[])
{
	cout << "Performing insertion sort." << endl;
	clock_t start = clock();
	
	for(int i = 0; i < cnt; i++)
	{	
		// At the start of each iteration, array elements from 0 till 
		// i - 1 are sorted in ascending order. 
		for(int j = 0; j < i; j++)
		{
			if(list[i] < list[j])
			{
				/* Store element to be moved. */
				int tmp = list[i];
				// Shift right by one place all preceding elements which
				// are greater than itself.
				int k = i;
				while(k > j)
				{
					list[k] = list[k - 1];
					k--;
				}
				/* Insert the element at desired position. */
				list[j] = tmp;
			}
		}
	}
	
	clock_t duration = (clock() - start) / CLOCKS_PER_SEC;
	cout << "Duration(ms): " << duration * 1000 << endl;
}


/* 
 * Description: Implementation of recursive sorting for merge sort. 
 * Arguments  : Pointer to head of list to be sorted, lower bound, upper
 * 				bound.
 * Returns    : None.
 */
void Sort::merge_recursive(int list[], int lb, int ub, int \
	sorted_list[])
{
	int left_lb, left_ub, right_lb, right_ub;
	 
	cout << "Recursive sorting of " << lb << " to " << ub << 
			" index." << endl;
	/* Calculate lower and upper bounds of arrays to be sorted. */
	left_lb = lb;
	left_ub = left_lb + ((ub - lb) / 2);
	right_lb = left_ub + 1;
	right_ub = ub;
	/* Sort each list if it contains atleast 2 elements. */ 
	if(left_lb < left_ub)
		Sort::merge_recursive(list, left_lb, left_ub);
	if(right_lb < right_ub)
		Sort::merge_recursive(list, right_lb, right_ub);
	
}
 
 
/* 
 * Description: Implementation of merge sort algorithm. 
 * Arguments  : Pointer to head of list to be sorted.
 * Returns    : None.
 */
void Sort::merge(int list[])
{
	int sorted_list = new int[cnt];
	cout << "Performing merge sort." << endl;
	clock_t start = clock();
	
	// Divide entire sequence into 2 subsequences of equal length.
	// Sort each of these subsequences recursively using merge sort.
	// Merge the 2 sorted subsequences to produce final sorted list.
	int left_ub = (cnt - 1) / 2;
	int right_lb = left_ub + 1;
	Sort::merge_recursive(list, 0, left_ub, sorted_list);
	Sort::merge_recursive(list, right_lb, cnt - 1, sorted_list); 
	 
	clock_t duration = (clock() - start) / CLOCKS_PER_SEC;
	cout << "Duration(ms): " << duration * 1000 << endl;
	delete sorted_list;
}
 
 
/* 
 * Description: Display entries of list. 
 * Arguments  : Pointer to head of list to be displayed.
 * Returns    : None.
 */
void Sort::display(int list[])
{
	cout << "Display list values." << endl;
	for(int i = 0; i < cnt; i++)
		cout << list[i] << "\t";
	cout << endl;
}


int main()
{
	cout << "Enter no. of values to be sorted: ";
	cin >> cnt;
		
	int *list = new int(cnt);
	
	cout << "Enter values:" << endl; 
	for(int i = 0; i < cnt; i++)
	{
		cin >> list[i];
	}
	
	//Sort::insertion(list);
	Sort::merge(list);
	
	Sort::display(list);
	
	delete list;
	
	return 0;
}

