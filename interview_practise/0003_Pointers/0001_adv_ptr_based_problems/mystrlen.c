#include <stdio.h>
#include <string.h>

int mystrlen (const char *);

int mystrlen (const char * str)
{
	int str_len = 0;

	while (*str != '\0')
	{
		str_len ++;
		str++;
	}
	return str_len;
}

int main (void)
{
	char str[50] = {};
	int ret = 0;

	printf ("Enter string\n");
	scanf ("%s",str);
	ret = mystrlen (str);
	printf ("length of %s is %d\n",str,ret);
	printf ("using strlen () length of %s is %d\n",str,strlen(str));

	return 0;
}


/*
 *  it work but if I give
 *  "good morning" it return 
 *  1st length of string even using
 *  strlen how to print even " " 
 *  space also?
 *
 *
 * */
