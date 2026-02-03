#include <stdio.h>

void rotate_arr (int [], int, int);

void rotate_arr (int arr[], int size, int pos)
{
	if (pos >= size)
	{
		printf ("Given position value is out of boundary, exiting ...\n");
		return ;
	}
	int temp;
	for (int i=0,inc=0;i<pos;i++,inc++)
	{
#if 1
		arr[i]                   = arr[i] ^ arr[ (size-pos) + inc];
		arr[ (size - pos) + inc] = arr[i] ^ arr[ (size - pos) + inc];
		arr[i]                   = arr[i] ^ arr[ (size-pos) + inc];
#endif
#if 0
        temp = arr[i];
		arr[i] = arr[ (size - pos) + inc];
		arr[ (size - pos) + inc] = temp;
#endif
	}
}

int main(void)
{
	int arr[] = {1,2,3,4,5,6,7};
	int size = sizeof(arr)/sizeof(arr[0]);
	printf ("Before rotate array\n");
    for (int i=0;i<size;i++)
        printf ("%d\t",arr[i]);
    printf("\n");
	rotate_arr (arr,size,4);
	printf ("After rotate array\n");
    for (int i=0;i<size;i++)
        printf ("%d\t",arr[i]);
    printf("\n");
	return 0;
}
