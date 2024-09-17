/**
* Author:    Matéo Guenot
 * Created:   17/09/2024
 *
 **/

#include <stdio.h>
#include <string.h>

int main() {
    char file[100], str[100];
    printf("Entrer le nom du fichier : ");
    scanf("%s", file);
    printf("Entrer la phrase string: ");
    scanf("%s", str);

    FILE *f = fopen(file, "r");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return 1;
    }

    // Search for the string in each line of the file and count the number of occurrences in each line
    int line = 1;
    char lineStr[100];
    while (fgets(lineStr, 100, f) != NULL) {
        int count = 0;
        char *pos = lineStr;
        while ((pos = strstr(pos, str)) != NULL) {
            count++;
            pos++;
        }
        if (count > 0) {
            printf("Ligne %d, %d fois\n", line, count);
        }
        line++;
    }

    fclose(f);
    return 0;
}
