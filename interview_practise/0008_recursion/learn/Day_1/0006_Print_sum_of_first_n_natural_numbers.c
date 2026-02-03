#include <stdio.h>

int sum_n_nos (int );

int sum_n_nos (int n)
{
	if (n <= 0)
		return 0;
	return n + sum_n_nos (n-1);
}

int main (void)
{
	int n=10, ret = 0;
	ret = sum_n_nos (n);
	printf ("sum of %d = %d\n",n,ret);
	return 0;
}
