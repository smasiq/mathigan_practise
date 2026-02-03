#include <stdio.h>

int main (void)
{
	int a=1,b=2,c=3;
	int *arr[3] = {&a,&b,&c};
	printf("%d %d %d\n", *arr[0], *arr[1], *arr[2]);
	printf("%p %p %p\n", &a, &b, &c);
	printf("%p %p %p\n", arr[0], arr[1], arr[2]);
	return 0;
}
