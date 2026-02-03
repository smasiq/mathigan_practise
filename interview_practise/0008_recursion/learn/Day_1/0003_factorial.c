#include <stdio.h>

int fact (int);

int fact(int n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

int main (void)
{
	int n=5;
	int ret = 0;

	ret = fact (n);
	printf ("factorial of %d is %d\n",n,ret);
	return 0;
}
