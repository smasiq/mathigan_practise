#include <stdio.h>

int main (void)
{
	const int x = 10;
	int *p = &x;  // valid or invalid?
    /*
	 * seems *p = 100 works but as per C std
	 * not valid, bcz const use read only
	 * it may work but it unexpected behaviour.
	 * if pointer need means based on req
	 * use const ptr or ptr to const.
	 * */
    *p = 100;
	printf ("%d\n",*p);
	return 0;
}
