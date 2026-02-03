#include <stdio.h>

int main (void)
{
	char *ptr = "hello world from C";

	//printf ("%s\n", *(ptr));
	printf ("%s\n", (ptr+1));

	return 0;
}
