#include <stdio.h>

void print_num (int);

void print_num (int n)
{
	if (n==6)
		return ;
	
	//print_num (n-1);
	print_num (n+1);
	printf ("%d\n",n);
}

int main (void)
{
	//int n = 5;
	int n = 1;
	print_num (n);
	return 0;
}
