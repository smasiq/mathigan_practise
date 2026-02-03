#include <stdio.h>

int (*func1(int *x))[3] {
    static int arr[3] = {1, 2, 3};
    printf("func1 called, *x = %d\n", *x);
    return &arr;
}

int (*func2(int *x))[3] {
    static int arr[3] = {4, 5, 6};
    printf("func2 called, *x = %d\n", *x);
    return &arr;
}

int (*(*p[2])(int *))[3] = {func1, func2};

int main(void) {
    int val = 10;
    int (*arrptr)[3];
    
    arrptr = p[0](&val);  // call func1
    printf("arrptr[0][1] = %d\n", (*arrptr)[1]);

    arrptr = p[1](&val);  // call func2
    printf("arrptr[0][2] = %d\n", (*arrptr)[2]);

    return 0;
}
