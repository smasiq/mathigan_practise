/*
 * String reverse using two pointer
 *
 * */

#include <stdio.h>

void strrev (char *);

void strrev (char *str)
{
	char *temp = str;
	char *end_str = NULL, *start_str = str;

	while (temp != '\0')
	{
		temp++;
		end_str = temp;
	}

	while (str != '\0')
	{
		
	}
}

int main (void)
{
	char *str = "hello";

	printf ("Before string reverse %s\n",str);
	strrev (str);
	printf ("After string reverse %s\n",str);

	return 0;
}
