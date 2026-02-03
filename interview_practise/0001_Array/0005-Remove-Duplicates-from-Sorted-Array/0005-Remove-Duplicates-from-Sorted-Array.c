/*
 *  Given a sorted array, remove the duplicates in-place and return the new length.

Example:

Input:  [1,1,2,2,3,4,4]
Output: [1,2,3,4] (length = 4)

using two pointer algo
 * */

#include <stdio.h>

void remove_dup_arr (int *, int *);

void remove_dup_arr (int *arr, int *size)
{
	int fast = 1, slow = 0;
	while ( fast < *size)
	{
		if (arr[fast] == arr[slow])
		{
			fast++;
		}
		else
		{
			slow++;
			arr[slow] = arr[fast];
		}
	}
    *size = slow;	
}

int main(void)
{
	int arr[] = {1,1,2,2,3,4,4};
	int size = sizeof (arr) / sizeof (arr[0]);

	printf ("Before removing duplicate elements\n");
	for (int i=0; i<size; i++)
	{
		printf ("%d\t",arr[i]);
	}
    
	remove_dup_arr (arr, &size);

	printf ("\nAfter removing duplicate elements\n");
	for (int i=0; i<=size; i++)
	{
		printf ("%d\t",arr[i]);
	}
	printf ("\n");

	return 0;
}

