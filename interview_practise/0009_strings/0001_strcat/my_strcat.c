#include <stdio.h>
#include <string.h>
#include <stddef.h>
#define BUFF_SIZE 25

char *mystrcat (char *, const char *);

int main (void)
{
	char src[10] = "say hi";
	char dest[BUFF_SIZE] = "Hello world";
	char *ret = NULL;
    
	ret = mystrcat (dest, src);
	printf ("ret from mystrcat %s\n",ret);
	return 0;
}

char *mystrcat (char *dest, const char *src)
{
	size_t src_len = 0, dest_len = 0;
	char *ret = dest;
 #if 0
	while (*dest != '\0')
	{
		dest++;
		dest_len++;
	}

	while (*src != '\0')
	{
		dest_len++;
		*(dest + dest_len) = *(src + src_len);
		dest++;
		src++;
		src_len++;
	}
	return dest;
#endif	
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*(dest++) = *(src++);
	}
	return ret;
}
