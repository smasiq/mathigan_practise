#include <stdio.h>

void mystrcpy (char *, const char *);

int main (void)
{
	char *src = "hello_world";
	char dest[20];
	mystrcpy(dest,src);
	printf ("after string copy %s\n",dest);
	return 0;
}

void mystrcpy (char *dest, const char *src)
{
	int j=0;
	for (int i=0; src[i]!='\0'; i++)
	{
		dest[j++] = src[i];
	}
	dest[j] = '\0';
}
