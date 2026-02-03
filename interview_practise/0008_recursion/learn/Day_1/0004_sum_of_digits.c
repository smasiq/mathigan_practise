#include <stdio.h>

int sumOfDigits(int n)
{
    if (n == 0)     /* base case */
        return 0;

    return (n % 10) + sumOfDigits(n / 10);
}

int main(void)
{
    int n = 1234;
    printf("Sum of digits: %d\n", sumOfDigits(n));
    return 0;
}

