/*
 * 2) Check whether an integer n is power of two

Q: Return true if n is a power of two (positive integers).
Hint: Powers of two have exactly one 1 bit.
 *
 * */

#include <stdio.h>
#include <stdbool.h>

bool is_power_of_two (int);

bool is_power_of_two (int value)
{
#if 0
	int i=0, count=0;
	while (i<32)
	{
		// if ((value & 1<<i ) == 1)   // not correct bcz every time its not value is 1
		if ( (value & 1<<i)  != 0 )
		{
			count++;
		}
		i++;
	}
	printf ("count %d\n",count);
	if (count == 1)
		return true;
	else
		return false;
#endif
// alternative one but for positive number
    return  (value > 0) && ((value & (value - 1)) == 0) ;
}

int main (void)
{
	int value = 0;
	bool ret = 0;
	printf ("Enter value\n");
	scanf ("%d",&value);

	ret = is_power_of_two (value);
    if (ret)
	{
		printf ("Given number is %d power of 2\n",value);
	}
	else
	{
		printf ("Given number is %d not power of 2\n",value);
	}

	return 0;
}
