/**
 * Author:    Rémi Jara
 * Created:   17/09/2024
 *
 **/

#include <stdio.h>

int main()
{

    int tableau[100];

    for (int compteur = 0; compteur < sizeof(tableau) / sizeof(int); compteur++)
    {
        tableau[compteur] = tableau[compteur] * 2;
    }

    return (0);
}
