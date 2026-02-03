#include <stdio.h>
#include <string.h>

char * mystrcpy (char *, const char *);

/*
 * Original function description :
 *
 * char *strcpy(char *restrict dest, const char *restrict src);
 *    Copy the string src to dest, 
 *	  returning a pointer to the start of dest.
 * */

char * mystrcpy (char * dest, const char * str)
{
	char *ret = dest;
	while (*str != '\0')
	{
		*dest = *str;
		dest++;
		str++;
	}
	*dest = '\0';
    return ret;	
}

int main (void)
{
	char src_str[50] = {}/*,dest_str_arr[50] = {}*/;
	//char *dest_str = NULL; OR char *dest_str ;
	// it lead seg fault bcz ptr point NULL or random address
	// those address are not safe to use So kernel throw 
	// seg fault.
	char dest_str [50]= {};
	char *ret_str = NULL;
	int ret = 0;

	printf ("Enter string\n");
	scanf ("%s",src_str);
	ret_str = mystrcpy (dest_str,src_str);
	//dest_str_arr = mystrcpy (dest_str,src_str);
	//it throw error bcz dest_str is fixed address
	//constant not able to change.
	printf ("After copy dest_str is %s ret_str is %s\n",dest_str,ret_str);
	printf ("using strcpy () dest_str is %s \n",strcpy(dest_str,src_str));

	return 0;
}
