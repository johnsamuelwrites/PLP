/**
 * Author:    Matéo Guenot
 * Created:   16/09/2024
 *
 **/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int num1 = 0;
    int num2 = 0;
    char op = ' ';

    printf("Entrer le premier nombre : ");
    scanf("%d", &num1);

    printf("Entrer le deuxième nombre : ");
    scanf("%d", &num2);

    printf("Choisir un opérateur (+, -, *, /, %%, &, |, ~) : ");
    scanf(" %c", &op); // Ajoute un espace avant %c pour ignorer le \n du scanf précédent

    switch (op)
    {
    case '+':
        printf("%d + %d = %d\n", num1, num2, num1 + num2);
        break;
    case '-':
        printf("%d - %d = %d\n", num1, num2, num1 - num2);
        break;
    case '*':
        printf("%d * %d = %d\n", num1, num2, num1 * num2);
        break;
    case '/':
        if (num2 == 0)
        {
            printf("Division par zéro\n");
            break;
        }
        printf("%d / %d = %d\n", num1, num2, num1 / num2);
        break;
    case '%':
        printf("%d %% %d = %d\n", num1, num2, num1 % num2);
        break;
    case '&':
        printf("%d & %d = %d\n", num1, num2, num1 & num2);
        break;
    case '|':
        printf("%d | %d = %d\n", num1, num2, num1 | num2);
        break;
    case '~':
        printf("~%d = %d\n", num1, ~num1);
        break;
    default:
        printf("Opérateur inconnu\n");
    }

    return 0;
}
