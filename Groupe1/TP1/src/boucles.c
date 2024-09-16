/**
 * Author:    Matéo Guenot
 * Created:   16/09/2024
 *
 **/

#include <stdio.h>

int main()
{
    // Déclaration et assignation des variables
    printf("Entrer la largeur du triangle rectangle : ");
    float largeur;
    scanf("%f", &largeur);

    if (largeur < 0)
    {
        printf("La largeur du triangle rectangle est négative\n");
        return 1;
    }

    if (largeur >= 10)
    {
        printf("La largeur du triangle rectangle est trop grande\n");
        return 1;
    }

    for (int i = 0; i <= largeur; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (j == 0 || j == i - 1 || i == largeur)
                printf("*");
            else
                printf("#");
        }
        printf("\n");
    }

    int i = 0;
    while (i <= largeur)
    {
        int j = 0;
        while (j < i)
        {
            if (j == 0 || j == i - 1 || i == largeur)
                printf("*");
            else
                printf("#");
            j++;
        }
        printf("\n");
        i++;
    }

    return 0;
}