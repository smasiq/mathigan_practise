#include <stdio.h>
#include <string.h>
#include <stddef.h>
#define BUFF_SIZE 14

void mystrncpy (char *, const char *,size_t);

int main (void)
{
	char src[BUFF_SIZE] = "good";
    char dest[BUFF_SIZE] ={};
	int num_of_bytes = 10;

    strncpy (dest, src, num_of_bytes);
    printf ("strncpy dest buffer is %s\n",dest);
    //dest[BUFF_SIZE] ={0};
	memset (dest,0,sizeof(dest));
    mystrncpy (dest, src, num_of_bytes);
    printf ("mystrncpy dest buffer is %s\n",dest);
	return 0;
}

void mystrncpy (char *dest, const char *src,size_t num_of_bytes) 
{
#if 0
	int j=0, count=0, i=0;

	while (src[count] != '\0')
	{
		count++;
	}

	for (i=0; i < num_of_bytes; i++)
	{
		dest[j++] = src[i];
	}

	if (count < num_of_bytes)
	{
		for (;i<num_of_bytes;i++) {
			dest[j++] = '\0';
		}
	}
#endif
    int i = 0;

	while (i < num_of_bytes && src[i] != '\0') {
		dest[i] = src[i];
		i++;
    }

    // Pad remaining bytes with '\0'
    while (i < num_of_bytes) {
        dest[i++] = '\0';
    }
}
