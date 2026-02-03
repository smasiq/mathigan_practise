#include <stdio.h>

void insertion_sort (int *,int);
void print_data (int *,int);

void insertion_sort (int *arr, int size)
{
	int i,j,key;

	for (int i=1;i<size;i++)
	{
		key = arr[i];
		j = i-1;
		while (j>=0 && arr[j]>key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

void print_data (int *arr, int size)
{
	for (int i=0;i<size;i++)
	{
		printf ("%d\n",arr[i]);
	}
}

int main (void)
{
	int arr[] = {60,30,20,50,10,40};
	int size  = sizeof(arr) / sizeof(arr[0]);

	printf ("Before insertion sorting ...\n");
	print_data (arr,size);
	insertion_sort (arr,size);
	printf ("After insertion sorting ...\n");
	print_data (arr,size);
	
	return 0;
}
