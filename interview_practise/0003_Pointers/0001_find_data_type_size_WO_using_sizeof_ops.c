/*
 * WAP to Find size of data type without
 * using sizeof operator.
 * */

#include <stdio.h>

struct abc
{
	int a;
	char b;
	double c;
	float d;
};

int main (void)
{
	int a = 10, b[5] = {10,20};
	char c = 'A', buff[5] = {"Hello world"};
	char *ptr = "Linux";
	long int d = 1000, e[4] = {2000,5555};
	unsigned int f = 40;
	struct abc st = {.a = 100,.d = 90.5};

	int *iptr = NULL, (*ibptr)[5] = NULL;
	char *cptr = NULL, (*cbptr)[5] = NULL;
	long int *liptr = NULL, (*lbptr) [4] = NULL;;
	unsigned int *uiptr = NULL;
	struct abc *sptr = &st;

	iptr = &a;
	printf ("sizeof a (int) is %ld\n",(char *)(iptr+1)- (char *)iptr);
	ibptr = &b;
	printf ("sizeof b is (int array ) %ld\n",(char *)(ibptr+1)- (char *)ibptr);
	cptr = &c;
	printf ("sizeof c is (char) %ld\n",(char *)(cptr+1)- (char *)cptr);
	cbptr = &buff;
	printf ("sizeof buff (array of char) is %ld\n",(char *)(cbptr+1)- (char *)cbptr);
	cptr = ptr;
	printf ("sizeof ptr (char pointer)  is %ld\n",(char *)(cptr+1)- (char *)cptr);
	liptr = &d;
	printf ("sizeof d (long int) is %ld\n",(char *)(liptr+1)- (char *)liptr);
	lbptr = &e;
	printf ("sizeof e (array of long int) is %ld\n",(char *)(lbptr+1)- (char *)lbptr);
	uiptr = &f;
	printf ("sizeof f (unsigned int) is %ld\n",(char *)(uiptr+1)- (char *)uiptr);

	printf ("sizeof st (structure) is %ld\n",(char *)(sptr+1)- (char *)sptr);

	return 0;
}
