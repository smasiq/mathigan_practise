#include <stdio.h>

// for practise use return both value
// from function.

//void find_large_small_elem (int *,int);

typedef struct ret_vals {
	int l_ele;
	int s_ele;
}ret_vals;

ret_vals find_large_small_elem (int *,int);

ret_vals find_large_small_elem (int *arr, int size)
{
	/*  int l_ele = s_ele = arr[0];  */
	//  above line don't use 
	//  bcz s_ele compiler consider undeclared.
	
	//int l_ele = arr[0];
	//int s_ele = arr[0];
	
	ret_vals vals = {0,0};
	vals.l_ele = vals.s_ele = arr[0];
	for (int i=1; i<size; i++)
	{
		if (vals.l_ele < arr[i])
		{
			vals.l_ele = arr[i];
		}
		// Avoid else if for
		// safety purpose if both 
		// value are same.
		if (vals.s_ele > arr[i])
		{
			vals.s_ele = arr[i];
		}
	}
	return vals;
}

int main(void)
{
	int arr[] = {23,1,42,5,33,77,43,78};
	int size = sizeof(arr) / sizeof(arr[0]);
	ret_vals vals = {0,0};
	vals = find_large_small_elem(arr,size);
	printf ("large element = %d "
	       "small element = %d "
		   "in given array\n",vals.l_ele,vals.s_ele);
	return 0;
}
