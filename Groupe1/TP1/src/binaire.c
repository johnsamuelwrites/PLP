#include <stdio.h>

int main()
{
    int a = 0;

    int binaire[32];
    int i = 0;

    while (a > 0)
    {
        binaire[i] = a % 2;
        a = a / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binaire[j]);
    }
    if (i == 0)
    {
        printf("0");
    }

    return 0;
}