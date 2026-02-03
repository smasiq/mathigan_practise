#include <stdio.h>

void print_arr (int *, int);
void bubble_sort (int *, int);

int main (void)
{
	int arr[5] = {70,20,10,40,30};
	int arr_size = ( sizeof(arr) / sizeof(arr[0]) );

    printf ("Before bubble sorting ...\n");
	print_arr (arr, arr_size);
	bubble_sort (arr,arr_size);
    printf ("After bubble sorting ...\n");
	print_arr (arr, arr_size);

	return 0;
}

void print_arr (int *arr, int size)
{
	for (int i=0; i<size; i++)
	{
		printf ("%d\n",arr[i]);
	}
}

void bubble_sort (int *arr, int size)
{
	int i,j,is_sorted = 0;

	for (i=0; i<size; i++)
	{
		for (j=0;j<size-i+1;j++)
		{
			if (arr[j] > arr [j+1])
			{
				is_sorted = 1;
				int temp;
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
		if (is_sorted == 0)
			break;
		else
			is_sorted = 0;
	}
}
