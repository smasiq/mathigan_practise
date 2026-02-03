#include <stdio.h>

#pragma pack(2)

struct A {
    char c;
    int x;
};

int main (void)
{
	struct A temp;
	temp.c = 'A';
	temp.x = 100;

	printf ("x = %d, c = %c, size of temp = %ld\n",temp.x,temp.c,sizeof(temp));
    printf("Alignment of struct = %zu\n", __alignof__(struct A));
	return 0;
}
