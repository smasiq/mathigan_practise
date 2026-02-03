#include <stdio.h>

int main (void)
{
	int *p =0x7ffd78dde4b8;
	// int *p = 10;
	// It not valid CPU tries to find
	// address of p but it point random
	// not able to locate its address
	// So OS protects to avoid access
	// random memory it throw seg fault.
	// same for random address user not use 
	// like until it was reserved,OS not allow 
	// this type of random address access,
	// may chance this address use by some other
	// process or read only or reserved or not valid.
	 printf ("*p = %d p =%p\n",*p,p);
	return 0;
}
