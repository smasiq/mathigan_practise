#include <stdio.h>

void selection_sort (int *,int);
void print_data (int *,int);

void selection_sort (int *arr, int size)
{
	int i,j,ss;

	for (int i=0;i<size-1;i++)
	{
		ss = i;
		for (int j=i+1;j<size;j++)
		{
			if (arr[j] < arr[ss])
			{
				ss = j;
			}
		}
		int temp = arr [ss];
		arr[ss] = arr[i];
		arr[i] = temp;
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

	printf ("Before selection sorting ...\n");
	print_data (arr,size);
	selection_sort (arr,size);
	printf ("After selection sorting ...\n");
	print_data (arr,size);
	
	return 0;
}
