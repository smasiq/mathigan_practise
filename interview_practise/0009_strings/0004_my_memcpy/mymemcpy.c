#include <stdio.h>
#include <string.h>

int main (void)
{
	char *src = "destination", *dest=NULL;
	memcpy (dest,src,11);
	printf ("dest %s\n",dest);
	return 0;
}
