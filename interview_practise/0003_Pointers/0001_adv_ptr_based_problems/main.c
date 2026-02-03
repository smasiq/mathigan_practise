#include <stdio.h>
#include <string.h>

int main(void)
{
	int arr[] = {1,2,3};

	printf ("arr %p &arr %p &arr[0] %p\n",arr,&arr,&arr[0]);

	//char str1[] = {a,b,c,d,e,f};
	char str1[] = "abcdef";

	printf ("Original string str1 %s\n",str1);

//	memcpy (str1+1 ,str1 + 2, 3);

	//printf ("After memcpy str1 %s\n",str1);

	char str2[] = "ghijkl";
	printf ("Original string str2 %s\n",str2);
	memmove (str2+2,str2+1,3);
	memcpy (str1+2,str1+1,3);
	printf ("After memove str2 %s\n",str2);
	printf ("After memmove str1 %s\n",str1);
	return 0;
}
