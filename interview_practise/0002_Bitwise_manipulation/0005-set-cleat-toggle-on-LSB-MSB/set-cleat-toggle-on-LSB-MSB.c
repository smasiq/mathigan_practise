/*
 *  2. Write a program to perform the following operations on the Least and Most Significant Bits (LSB/MSB) of a given
	integer:
	Set the LSB to 1
	Clear the LSB (set to 0)
	Toggle the LSB
	Set the MSB to 1
	Clear the MSB (set to 0)
	Toggle the MSB
	Set a specific bit to 1
	Clear a specific bit
	Toggle a specific bit
 *
 * */

#include <stdio.h>

int main (void)
{
	int n=10;
	printf ("Set bit on LSB for n=%d\n",n);
	printf ("%d\n",n|(1<<0));
	n=11;
	printf ("Clear bit on LSB for n=%d\n",n);
	printf ("%d\n",n&~(1<<0));
	n=11;
	printf ("Toggle bit on LSB for n=%d\n",n);
	printf ("%d\n",n^(1<<0));
	n=10;
	printf ("Set bit on MSB for n=%d\n",n);
	printf ("%d\n",n|(1<<31));	
	printf ("Clear bit on MSB for n=%d\n",n);
	printf ("%d\n",n&~(1<<31));
	n=11;
	printf ("Toggle bit on MSB for n=%d\n",n);
	printf ("%d\n",n^(1<<31));
	n=20;
	printf ("Set bit on 1th bit for n=%d\n",n);
	printf ("%d\n",n|(1<<1));
	printf ("Clear bit on 1th bit for n=%d\n",n);
	printf ("%d\n",n&~(1<<1));
	printf ("Toggle bit on 1th bit for n=%d\n",n);
	printf ("%d\n",n^(1<<1));
	return 0;
}
