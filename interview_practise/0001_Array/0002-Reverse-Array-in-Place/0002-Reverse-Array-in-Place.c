/*
 *  Problem 2: Reverse Array in Place
    Given an array, reverse it without using extra array.

	Example:
	   Input: [1,2,3,4,5] → Output: [5,4,3,2,1]

Hint: Use two pointers at start and end and swap.
 *
 * */

#include <stdio.h>

void reverse_arr (int *, int);

void reverse_arr (int *arr, int size)
{
	int last_pointer =  size-1, first_pointer = 0;
//	int check_bound = (size%2==0) ? size/2 : (size/2)-1; // this is not correct logic when use 2 pointer algo

	//for (int i=0; i<check_bound ;i++)
	while (first_pointer < last_pointer)
	{
		arr[first_pointer] = arr[first_pointer] ^ arr[last_pointer];
		arr[last_pointer] = arr[first_pointer] ^ arr[last_pointer];
		arr[first_pointer] = arr[first_pointer] ^ arr[last_pointer];
		first_pointer++;
		last_pointer--;
	}
}

int main (void)
{
	int arr[] = {10,20,30,40,50}, size=0;
	size = sizeof (arr) / sizeof(arr[0]);

    printf ("before reverse array\n");
	for (int i=0; i<size; i++)
	{
		printf ("%d\n",arr[i]);
	}
	reverse_arr (arr, size);
    printf ("after reverse array\n");
	for (int i=0; i<size; i++)
	{
		printf ("%d\n",arr[i]);
	}
	return 0;
}
