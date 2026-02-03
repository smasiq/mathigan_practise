#include <stdio.h>
#include <string.h>

int my_strcmp (const char *, const char *);

int my_strcmp (const char * str_1, const char *str_2)
{
	if (str_1 == NULL || str_2 == NULL)
	{
		printf ("Given strings are NULL\n");
		return 0;
	}
	else
	{
		int count = 0;
		//while (str_1 != NULL && str_2 != NULL) // this line runs in loop not terminating
		while (*str_1 != '\0' && *str_2 != '\0')
		{
			count = *str_1 - *str_2;
			if (!count) {
				str_1++;
				str_2++;
			}
			//else
				//return count;
		}
	}
	return *str_1 - *str_2;
}

int main(void)
{
	char *str_1 = "apple", *str_2 = "apple_banana";
	int ret = 0;

	ret = my_strcmp (str_1, str_2);
	printf ("ret value from my_strcmp is %d\n",ret);
	printf ("ret value from strcmp is %d\n",strcmp (str_1, str_2));
	return 0;
}
