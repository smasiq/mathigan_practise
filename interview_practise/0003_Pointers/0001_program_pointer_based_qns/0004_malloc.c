#include <stdio.h>
#include <stdlib.h>

void alloc(int **p) {
    *p = malloc(sizeof(int));
    **p = 10;
}

int main (void)
{
	int *ptr = NULL;
	alloc (&ptr);
	printf ("%d\n",*ptr);
	return 0;
}
