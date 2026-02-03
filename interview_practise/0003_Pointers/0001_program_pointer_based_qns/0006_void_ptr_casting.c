#include <stdio.h>

int main (void)
{
	int **idptr = NULL;
	void **vdptr = NULL;

	int val = 10;
	int *ptr = &val;

	idptr = &ptr;

	vdptr = idptr;

	printf ("%d\n",**(int **)vdptr);

	return 0;
}
