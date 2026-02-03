/*
 * Qn Find the number that appears once 
 *    when all other elements appear twice
 * */

#include <stdio.h>


int *check_num_appear_once (int *, int ,int*);

int *check_num_appear_once (int *arr, int len, int *ret_leng)
{
	static int ret [1000];
	int i, j, ret_len = 0;
	int is_no_dup = 0;

	for (i=0; i< len; i++)
	{
		for (j=0;j< len;j++)
		{
			//if (arr[i] ^ arr[j] == 0)
			if ( (arr[i] ^ arr[j]) == 0)
			{
				is_no_dup++;
			}
		}
		if (is_no_dup == 1)
		{
			ret[ret_len++] = arr[i];
			*ret_leng = ret_len;
		}
		is_no_dup = 0;
	}

	if (ret_len == 0)
	{
		return NULL;
	}
	else 
	{
		return ret;
	}
}

int main (void)
{
	int arr[] = {12,4,5,6,6,4,7,8,4};
	int len   = sizeof (arr) / sizeof (arr[0]);
	//int *ret = NULL, int ret_leng = 0;
	int *ret = NULL, ret_leng = 0;

	printf ("Elements from given array\n");
	for (int i=0; i<len; i++)
	{
		printf ("%d\t",arr[i]);
	}
	printf ("\n");
	ret = check_num_appear_once (arr, len, &ret_leng);

	if (ret == NULL)
	{
		printf ("from array all element has single occurence\n");
	}
	else
	{
		printf ("From array single element occurs are ...\n");
		for (int i=0;i<ret_leng; i++)
		{
			printf ("%d\t",ret[i]);
		}
	}
	return 0;
}
