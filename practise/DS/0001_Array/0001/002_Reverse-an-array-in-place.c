#include <stdio.h>

void reverse_arr (int *, int );

// Try this recursive instead of loop

void reverse_arr (int *arr, int size)
{
	int l_index = size -1;
	for (int i=0 ; i< (size/2) ; i++)
	{
		arr[i]         = arr[i] ^ arr[l_index-i];
		arr[l_index-i] = arr[i] ^ arr[l_index-i];
		arr[i]         = arr[i] ^ arr[l_index-i];
	}
}

int main(void)
{
	int arr[] = {10,20,30,40,50};
	int size = sizeof(arr) / sizeof(arr[0]);
	printf ("Before reverse array\n");
	for (int i=0;i<size;i++)
		printf ("%d\t",arr[i]);
	printf("\n");
	reverse_arr (arr,size);
	printf ("After reverse array\n");
	for (int i=0;i<size;i++)
		printf ("%d\t",arr[i]);
	printf("\n");
	return 0;
}
