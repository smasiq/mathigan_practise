/*
 *  0001 - Count frequency of elements
 * */

#include <stdio.h>

int * count_freq_arr (int *,int);

int * count_freq_arr (int *arr, int size)
{
	static int freq_hash [100] = {};
    
	for (int i=0;i<size;i++)
	{
		freq_hash[arr[i]] ++;
	}
	return freq_hash;
}

int main (void)
{
	int arr[] = {10, 20, 10, 30, 20, 10};
	int size  = sizeof (arr) / sizeof(arr[0]);
	int *ret = NULL;
	ret = count_freq_arr (arr, size);
	for (int i=0;i<size;i++)
	{
		if (ret[arr[i]] > 0)
		{
			//printf ("%d occurs %d times\n",arr[i],ret[i]);
			printf ("%d occurs %d times\n",arr[i],ret[arr[i]]);
			ret[arr[i]] = 0; //avoid repeat output
		}
	}
	return 0;
}
