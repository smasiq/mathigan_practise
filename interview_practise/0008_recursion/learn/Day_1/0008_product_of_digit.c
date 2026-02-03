#include <stdio.h>

int productofdigit (int );

int productofdigit (int num)
{
	if (num < 10)
		return num;
	return 1 * productofdigit (num%10);
}

int main (void)
{
	int num = 12;
	int ret = 0;

	ret = productofdigit (num);
	printf ("Number of count digit is %d from given number %d\n",ret,num);
	return 0;
}
