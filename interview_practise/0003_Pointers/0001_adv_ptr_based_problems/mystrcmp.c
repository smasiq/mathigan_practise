#include <stdio.h>
#include <string.h>

int mystrcmp (const char *, const char *);

int mystrcmp (const char * str_1, const char * str_2)
{
	int ret = 0;

	while (*str_1 == *str_2)
	{
		if (*str_1 == '\0' || *str_2 == '\0')
		{
			goto label;
		}
		str_1++;
		str_2++;
	}
label:
	ret = *str_1 - *str_2;
    return ret;	
}

int main (void)
{
	char str_1[50] = {} ,str_2 [50]= {};
	int ret = 0;

	printf ("Enter string\n");
	scanf ("%s %s",str_1,str_2);
	ret = mystrcmp (str_1, str_2);
	printf ("mystrcmp ret is %d\n",ret);
	printf ("strcmp ret is %d\n",strcmp(str_1,str_2));

	return 0;
}
