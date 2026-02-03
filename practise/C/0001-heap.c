#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int *ptr = NULL;

	while (1)
	{
		ptr = malloc (10000*sizeof(int));
		if (ptr == NULL)
		{
			printf("malloc failed ...\n");
		}
		printf ("press Enter ...\n");
		//getchar();
	}
	return 0;
}
