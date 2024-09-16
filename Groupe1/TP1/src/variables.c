/**
 * Author:    Matéo Guenot
 * Created:   16/09/2024
 *
 **/

#include <stdio.h>

int main()
{
    // Déclaration et assignation des variables
    char c = 'A';
    signed char sc = -50;
    unsigned char uc = 255;

    short s = -32768;
    unsigned short us = 65535;

    int i = -2147483648;
    unsigned int ui = 4294967295;

    long int li = -9223372036854775807L;
    unsigned long int uli = 18446744073709551615UL;

    long long int lli = -9223372036854775807LL;

    float f = 3.14f;
    double d = 2.718281828459;
    long double ld = 3.14159265358979323846L;

    // Affichage des valeurs avec printf()
    printf("char: %c\n", c);
    printf("signed char: %d\n", sc);
    printf("unsigned char: %u\n", uc);

    printf("short: %d\n", s);
    printf("unsigned short: %u\n", us);

    printf("int: %d\n", i);
    printf("unsigned int: %u\n", ui);

    printf("long int: %ld\n", li);
    printf("unsigned long int: %lu\n", uli);

    printf("long long int: %lld\n", lli);

    printf("float: %f\n", f);
    printf("double: %lf\n", d);
    printf("long double: %Lf\n", ld);

    return 0;
}