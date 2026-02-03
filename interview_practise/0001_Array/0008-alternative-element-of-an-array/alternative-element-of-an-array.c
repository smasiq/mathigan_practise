#include <stdio.h>

void print_alternative_elements (int *arr, int size)
{
	for (int i=0;i<size;i+=2)
	//for (int i=0;i<size;i++)
	{
		//if (i%2==0) 
		{
			printf ("%d\n",arr[i]);
		}
	}
}

int main (void)
{
	int arr[] = {90,30,10,40,60,20};
	int size = sizeof(arr) / sizeof(arr[0]);

	for (int i=0;i<size;i++)
		printf ("%d\n",arr[i]);

	printf ("Print alternative elements of an array\n");
	print_alternative_elements (arr,size);

	return 0;
}
