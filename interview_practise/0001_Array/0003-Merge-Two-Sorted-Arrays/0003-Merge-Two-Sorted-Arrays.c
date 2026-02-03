/*
 *
Given two sorted arrays arr1 and arr2, merge them into a single sorted array (can use extra array).

Example:

arr1 = [1,3,5]
arr2 = [2,4,6]
Output: [1,2,3,4,5,6]


Hint: Use two pointers, one for each array, and pick the smaller element each time.
 * */


#include <stdio.h>
#include <stdlib.h>

int * merge_two_arr (const int * , const int , const int *, const int, int *);

int * merge_two_arr (const int *arr1 , const int size1, const int *arr2, const int size2, int * length)
{
	int *  merge_arr = NULL, index=0;
	int first_array_pointer = 0, second_array_pointer = 0;
	
//	merge_arr = (int *) malloc (size1+size2);
    merge_arr = (int *) malloc((size1 + size2) * sizeof(int));
	if (merge_arr == NULL)
	{
		printf ("%s:%d malloc failed\n",__func__,__LINE__);
		exit(EXIT_FAILURE);
	}

	//while ( first_array_pointer < size1 || second_array_pointer < size2)
	while ( first_array_pointer < size1 && second_array_pointer < size2)
	{
		if (arr1[first_array_pointer] < arr2[second_array_pointer])
		{
			merge_arr [index] = arr1[first_array_pointer];
			first_array_pointer++;
			index++;
		}
		else 
		{
			merge_arr [index] = arr2[second_array_pointer];
			second_array_pointer++;
			index++;
		}
	}

	while (first_array_pointer < size1)
		merge_arr[index++] = arr1[first_array_pointer++];

	while (second_array_pointer < size2)
		merge_arr[index++] = arr2[second_array_pointer++];

	*length = index;
	return merge_arr;
}

int main (void)
{
	int arr1[] = {1,3,5}, size1 = 0;
	int arr2[] = {2,4,6}, size2 = 0;
    int length = 0,*ret = NULL;

    size1 = sizeof(arr1) / sizeof(arr1[0]);
    size2 = sizeof(arr2) / sizeof(arr2[0]);
	ret = merge_two_arr (arr1, size1, arr2, size2,&length);
	for (int i=0;i<length;i++)
	{
		printf ("%d\t",ret[i]);
	}
	printf ("\n");
	free (ret);
	ret = NULL;
	return 0;
}
