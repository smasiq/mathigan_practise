#include <stdio.h>
#include <stddef.h>
#include <string.h>

#define BUFF_SIZE 10

size_t my_strlcpy (char *, const char*, size_t);

int main (void)
{
	//char *src = "good_morning";
	//char src[6] = {'H', 'e', 'l', 'l', 'o',}; // No '\0' terminator!
	//char src[6] = {'H', 'e', 'l', 'l', 'o','\0'}; 
	char *src = "good_morning have a nice day";
	char dest [BUFF_SIZE] = {};

    size_t n = strlcpy(dest, src, sizeof(dest)); // internally does strlen(src)
    printf("Copied %zu characters: %s\n", n, dest);
	n = my_strlcpy (dest,src,sizeof(dest));
	printf ("copied %zu dest : %s\n",n,dest);
	return 0;
}

size_t my_strlcpy (char *dest, const char *src, size_t dest_buff_size)
{
	size_t ret_dest_len = 0, i=0;
	size_t src_len = strlen(src);
    
    if (dest_buff_size == 0)
		return src_len;

	while (i < (dest_buff_size-1) && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
    return src_len;
}
