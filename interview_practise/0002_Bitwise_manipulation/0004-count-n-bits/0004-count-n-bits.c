#include <stdio.h>

int main (void)
{
	int count = 0;
	int n = 19;

	while(n) {
		count++;
		n = n & (n-1);
	}
	printf ("count %d n %d\n",count,n);
	return 0;
}
