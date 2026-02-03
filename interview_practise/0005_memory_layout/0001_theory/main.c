#include <stdio.h>
#include <stdlib.h>

int g = 10;         // .data
int g1;             // .bss

void func(void)
{
    static int s = 5;    // .data
    int a = 1;           // stack
    int *p = malloc(sizeof(int)); // heap
    *p = 100;
    printf("g=%d g1=%d s=%d a=%d *p=%d\n", g, g1, s, a, *p);
    getchar(); // keep program running for inspection
}

int main(void)
{
    func();
    return 0;
}
