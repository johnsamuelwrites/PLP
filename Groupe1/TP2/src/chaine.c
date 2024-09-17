/**
* Author:    Matéo Guenot
 * Created:   17/09/2024
 *
 **/

#include <stdio.h>

int length(char *str);

void copy(char *src, char *dest);

void concatenate(char *src1, char *src2, char *dest);

int main() {
    char str1[100], str2[100], dest[200];
    printf("Entrer la première string : ");
    scanf("%s", str1);
    printf("Entrer la deuxième string: ");
    scanf("%s", str2);
    printf("La longueur de la première string est : %d\n", length(str1));
    printf("La longueur de la deuxième string est : %d\n", length(str2));
    copy(str1, dest);
    printf("La copie de la première string est : %s\n", dest);
    concatenate(str1, str2, dest);
    printf("La concaténation des deux strings est : %s\n", dest);

    return 0;
}

int length(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

void copy(char *src, char *dest) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void concatenate(char *src1, char *src2, char *dest) {
    int i = 0;
    while (src1[i] != '\0') {
        dest[i] = src1[i];
        i++;
    }
    int j = 0;
    while (src2[j] != '\0') {
        dest[i] = src2[j];
        i++;
        j++;
    }
    dest[i] = '\0';
}
