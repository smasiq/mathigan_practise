#include <stdio.h>

static inline int add (int,int);

static inline int add (int a, int b)
// inline int add(int a, int b)
//
// In C, 'inline' does not guarantee that a function body
// will be emitted as a callable symbol.
//
// When compiled with -O0, the compiler typically does not inline
// the function and also does not emit an external definition,
// which leads to a linker error (undefined reference to 'add').
//
// With -O2, the compiler may inline the function, so no call to
// 'add' remains and the linker error disappears.
//
// Using 'static inline' gives the function internal linkage and
// avoids the linker error regardless of optimization level.
{
	return a+b;
}

int main (void)
{
	add (2,3);
	return 0;
}
