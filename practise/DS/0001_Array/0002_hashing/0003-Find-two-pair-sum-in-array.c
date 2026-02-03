/**
 *  
 * Two Sum (Pair with Given Sum)
 *
 * */

#include <stdio.h>

int * find_sum_of_target_num (int *, int, int);

int * find_sum_of_target_num (int *arr, int size, int target)
{
	int hash_arr[100] = {0};
	static int ret[2] ;

    for (int i=0; i<size; i++)
	{
		//hash_arr[arr[i]] = arr[i];
		hash_arr[arr[i]]++;
	}
	for (int i=0; i<size; i++)
	{
		int needed = target - arr[i];

		if (hash_arr[needed] == 1) // check if complement exists
		//if ( arr[i] + hash_arr[arr[i+1]] == target)
		{
			ret[0] = arr[i];
			ret[1] = arr[i+1];
			return ret;
		}
	}
	return NULL;
}

int main (void)
{
	int arr[] = {15, 3, 7, 10}, target = 17;
	int size  = sizeof (arr) / sizeof(arr[0]);
	int *ret = NULL;

    ret = find_sum_of_target_num ( arr, size, target);
	if (ret == NULL)
	{
		printf ("no sum elements found to match target value %d\n",target);
	}
	else
	{
		printf ("Two sum elements %d and %d for target %d\n", ret[0],ret[1],target);
	}
	return 0;
}
