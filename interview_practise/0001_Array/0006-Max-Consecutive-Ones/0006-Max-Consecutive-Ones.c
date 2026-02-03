/*
 *
 * Problem: Max Consecutive Ones

Description:
Given a binary array (containing only 0s and 1s), find the length of the longest consecutive 1s in the array.

Example:

Input:  [1,1,0,1,1,1]
Output: 3  // The longest consecutive 1s are three 1s at the end.


Hint:
Use two pointers or a sliding window approach to track consecutive 1s.
 *
 * */

#include <stdio.h>

int find_max_consecutive_one (int *, int );

int find_max_consecutive_one (int *arr, int size)
{
	int fast = 0, count = 0,max_count = 0;
	while (fast < size)
	{/*
		if (arr[fast] == arr[slow])
		{
			fast++;
			count++;
		}
		else
		{
			slow++;
			count=0;
		}*/
		if (arr[fast] == 1)
		{
			count++;
			if (count > max_count)
			{
				max_count =  count;
			}
		}
		else
		{
			count=0;
		}
		fast++;
	}
	return max_count;
}

int main (void)
{
	int arr[] = {1,1,0,1,1,1,0,1,1,0,1,1,1,1,1};
	int size = sizeof(arr) / sizeof(arr[0]);
    int ret = 0;

	ret = find_max_consecutive_one (arr, size);

    printf ("max consecutive one is %d\n", ret);

	return 0;
}
