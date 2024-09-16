#include <stdio.h>

int main(int argc, char *argv[]) {
    const float pi = 3.14159;
    // Get the radius from the user
    printf("Entrer le rayon du cercle : ");
    float radius;
    scanf("%f", &radius);

    const float air = pi * radius * radius;

    if (air < 0) {
        printf("L'air du cercle est négatif\n");
    } else {
        printf("L'air du cercle est : %f\n", air);
    }

    return 0;
}

