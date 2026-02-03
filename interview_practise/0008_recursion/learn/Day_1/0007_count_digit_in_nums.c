#include <stdio.h>

int countdigit (int );

int countdigit (int num)
{
	if (num == 0)
		return 0;
	return 1 + countdigit (num/10);
}

int main (void)
{
	int num = 12345;
	int ret = 0;

	ret = countdigit (num);
	printf ("Number of count digit is %d from given number %d\n",ret,num);
	return 0;
}
