/*
 * 0002 Check for duplicate in an array
 * */

#include <stdio.h>

int * find_dup_ele_arr (int *,int);

int * find_dup_ele_arr (int *arr, int size)
{
	static int dup_hash[100] = {0};

    for (int i=0; i<size; i++)
	{
		dup_hash[arr[i]]++;
	}
    return dup_hash;
}

int main (void)
{
	int arr[] = {5, 7, 1, 7, 9};
	int size = sizeof(arr) / sizeof(arr[0]);
	int *ret = NULL;
	char is_dup_present = 0;
	
	ret = find_dup_ele_arr (arr,size);
	for (int i=0; i<size; i++)
	{
		if (ret[i] > 0)
		{
			printf ("duplicate elemnt %d is present occured %d times\n",arr[i],ret[arr[i]]);
			is_dup_present = 1;
		}
	}
	if (is_dup_present == 0)
		printf ("duplicate element not present in given array\n");

	return 0;
}
