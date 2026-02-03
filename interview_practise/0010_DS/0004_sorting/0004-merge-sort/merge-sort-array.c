#include <stdio.h>

void mergesort (int *, int, int);
void print_data (int *, int);
void merge (int *, int, int ,int);

void merge (int *arr, int left, int mid, int right)
{
	int L1 = mid-left+1; //end - start +1;
	int R1 = right - mid;
	int L[L1] , R[R1];

	for (int i=0;i<L1;i++)
		L[i] = arr[left+i];

	for (int j=0;j<R1;j++)
		R[j] = arr[mid+1+j];

	int i=0, j=0, k=left;

	while (i<L1 && j<R1)
	{
		if (L[i] <= R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}
	while (i<L1)
		arr[k++] = L[i++];
	while (j<R1)
		arr[k++] = R[j++];
}

void mergesort (int *arr, int left, int right)
{
	int mid = left + (right - left)/2 ; // start + (end - start)/2
	if (left < right)
	{
		mergesort (arr,left,mid);
		mergesort (arr,mid+1,right);
		merge (arr,left,mid,right);
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
	int arr[] = {60,10,30,20,40,50};
	int size = sizeof(arr)/sizeof(arr[0]);

	printf ("Before merge sorting ...\n");
	print_data (arr,size);
	mergesort (arr,0,size-1);
	printf ("After merge sorting ...\n");
	print_data (arr,size);
}
