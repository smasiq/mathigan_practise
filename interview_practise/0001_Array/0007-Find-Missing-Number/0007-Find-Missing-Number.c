#include <stdio.h>

int find_missing_element (int *, int);

int main (void)
{
	int arr[] = {1,3,4,8,7,5,6};
	int len = sizeof(arr)/sizeof(arr[0]);
	int ret = 0;
	
	ret = find_missing_element (arr,len);
	if (ret > 0)
	{
		printf ("Missing element from array is %d\n",ret);
	}
	else
	{
		printf ("No Missing element\n");
	}
	return 0;
}

int find_missing_element (int *arr, int arr_len)
{
	int sum = 0, arr_sum = 0 ;
    int i = 0, ret = 0;

	for (i=0; i<arr_len; i++)
	{
		//sum += i;
		sum += (i+1);
		arr_sum  = arr_sum + arr[i];
	}
	//sum += i;
	sum += (i+1);
	ret = sum - arr_sum;
	printf ("sum %d ret %d arr_sum %d i %d\n",sum, ret, arr_sum, i);
	return ret;

}
