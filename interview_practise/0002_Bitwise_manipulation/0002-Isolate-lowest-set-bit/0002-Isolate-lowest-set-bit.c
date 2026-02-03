/*
 *  3) Isolate lowest set bit
 *
 *  Q: Get a number with only the least significant 1-bit of x set (all other bits 0).
 *
 * */

#include <stdio.h>

int main (void)
{
	int value = 0;
	printf ("enter value\n");
	scanf ("%d",&value);

	printf ("LSB value is %d\n", value & -value);
	return 0;
}
