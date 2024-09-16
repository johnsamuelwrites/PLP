#include <stdio.h>

int main()
{
    int a = 16;
    int b = 3;

    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %.6f\n", (double)a / (double)b);
    printf("a %% b = %d\n", a % b);
    printf("a == b = %d\n", a == b);
    printf("a > b = %d\n", a > b);
    return 1;
}