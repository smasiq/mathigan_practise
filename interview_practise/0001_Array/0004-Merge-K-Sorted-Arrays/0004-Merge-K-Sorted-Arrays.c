/*
 *  
You are given k sorted arrays of integers. Merge them into a single sorted array.

Example:

Input:
arr1 = [1, 4, 7]
arr2 = [2, 5, 8]
arr3 = [3, 6, 9]

Output:
[1, 2, 3, 4, 5, 6, 7, 8, 9]
 *
 * */

#include <stdio.h>
#include <stdlib.h>

int * merge_k_sorted_arr (const int * , const int , const int * , const int , const int * , const int , int *);
int * merge_two_arr (const int * , const int , const int *, const int, int *);

int * merge_two_arr (const int *arr1 , const int size1, const int *arr2, const int size2, int *length)
{
	int *  merge_arr = NULL, index=0;
	int first_array_pointer = 0, second_array_pointer = 0;
	
    merge_arr = (int *) malloc((size1 + size2) * sizeof(int));
	if (merge_arr == NULL)
	{
		printf ("%s:%d malloc failed\n",__func__,__LINE__);
		exit(EXIT_FAILURE);
	}

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

int * merge_k_sorted_arr (const int * arr1, const int size1, const int * arr2, const int size2, const int * arr3, const int size3, int *length)
{
	int first_arr_pointer = 0, second_arr_pointer = 0, third_arr_pointer = 0;
	int *merge_arr = NULL, *final = NULL ,merge_arr_length = 0,final_length=0;
/*
	merge_arr = (int *) malloc ( merge_arr_size);
	if (merge_arr == NULL)
	{
		printf ("%s:%d malloc failed\n",__func__,__LINE__);
		exit(EXIT_FAILURE);
	}*/
    
	merge_arr = merge_two_arr (arr1, size1, arr2, size2,&merge_arr_length);
/*
    final = (int *) malloc (final_arr_size);
	if (final == NULL)
	{
		printf ("%s:%d malloc failed\n",__func__,__LINE__);
		exit(EXIT_FAILURE);
	}*/
    final = merge_two_arr (merge_arr,merge_arr_length, arr3, size3,&final_length);

	free(merge_arr);
	*length = final_length;
    return final;
}

int main (void)
{
	int arr1[] = {1,4,7};
	int arr2[] = {2,5,8};
	int arr3[] = {3,6,9};
	int size1 = 0, size2 = 0, size3 = 0;
	int length = 0, *ret = NULL;

    size1 = sizeof (arr1) / sizeof (arr1[0]);
    size2 = sizeof (arr2) / sizeof (arr2[0]);
    size3 = sizeof (arr3) / sizeof (arr3[0]);

	ret = merge_k_sorted_arr (arr1, size1, arr2, size2, arr3, size3, &length);
	for (int i=0; i<length; i++)
	{
		printf ("%d\t", ret[i]);
	}
	printf ("\n");
	return 0;
}
