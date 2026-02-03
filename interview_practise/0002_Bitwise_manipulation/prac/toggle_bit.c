#include <stdio.h>

int main (void)
{
	int n=19;
	int toggle_bit_pos = 4;
	int toggle_bit_value = n^1<<4;
	printf ("After toggle bit value is %d for value %d\n",toggle_bit_value,n);

	return 0;
}
