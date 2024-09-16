#include <stdio.h>

int main()
{
    printf("Size of char: %ld\n", sizeof(char));
    printf("Size of unsigned char: %ld\n", sizeof(unsigned char));
    printf("Size of short: %ld\n", sizeof(short));
    printf("Size of unsigned short: %ld\n", sizeof(unsigned short));
    printf("Size of int: %ld\n", sizeof(int));
    printf("Size of unsigned int: %ld\n", sizeof(unsigned int));
    printf("Size of long int: %ld\n", sizeof(long int));
    printf("Size of unsigned long int: %ld\n", sizeof(unsigned long int));
    printf("Size of long long int: %ld\n", sizeof(long long int));
    printf("Size of float: %ld\n", sizeof(float));
    printf("Size of double: %ld\n", sizeof(double));
    printf("Size of long double: %ld\n", sizeof(long double));

    return 0;
}