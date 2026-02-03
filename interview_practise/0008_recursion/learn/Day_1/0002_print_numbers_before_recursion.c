#include <stdio.h>

void print_num (int);

void print_num (int n)
{
	if (n==0)
		return ;
	
	printf ("%d\n",n);
	print_num (n-1);
}

int main (void)
{
	int n = 5;
	print_num (n);
	return 0;
}
