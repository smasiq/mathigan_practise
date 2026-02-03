#include <stdio.h>
#include <string.h>

char * mystrstr (char *, char *);

char * mystrstr (char * str_1, char * str_2)
{
	char * ret = NULL,*temp=NULL;

    while (*str_1 != '\0')
	{
		if (*str_1 == *str_2)
		{
			ret = str_1;
			temp = str_2;
			while (*str_2 != '\0')
			{
				if (*str_1 == *str_2)
				{
					str_1++;
					str_2++;
				}
				else
				{
					str_2 = temp;
					break;
				}
				if (*str_2 == '\0')
					return ret;
			}
		}
		else
		{
			str_1++;
		}
	}
	return NULL;
}

int main (void)
{
	char str_1[50] = {} ,str_2 [50]= {};
	char * ret = NULL;

	printf ("Enter string\n");
	scanf ("%s %s",str_1,str_2);
	ret = mystrstr (str_1, str_2);
	printf ("mystrstr ret is %s\n",ret);
	printf ("strstr ret is %s\n",strstr(str_1,str_2));

	return 0;
}
