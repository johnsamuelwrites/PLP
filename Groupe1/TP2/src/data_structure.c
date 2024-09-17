/**
 * Author:    Rémi Jara
 * Created:   17/09/2024
 *
 **/

struct Student
{
    char firstName[50];
    char lastName[50];
    char address[100];
    float grades[5];
};
#include <stdio.h>
#include <string.h>

int main()
{
    struct Student students[5];

    char firstName[50];
    char lastName[50];
    char address[100];
    float grades[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Enter the first name of student %d: ", i + 1);
        scanf("%s", firstName);
        strcpy(students[i].firstName, firstName);

        printf("Enter the last name of student %d: ", i + 1);
        scanf("%s", lastName);
        strcpy(students[i].lastName, lastName);

        printf("Enter the address of student %d: ", i + 1);
        scanf("%s", address);
        strcpy(students[i].address, address);

        for (int j = 0; j < 5; j++)
        {
            printf("Enter the grade %d of student %d: ", j + 1, i + 1);
            scanf("%f", &grades[j]);
            students[i].grades[j] = grades[j];
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("Student %d\n", i + 1);
        printf("First name: %s\n", students[i].firstName);
        printf("Last name: %s\n", students[i].lastName);
        printf("Address: %s\n", students[i].address);
        printf("Grades: ");
        for (int j = 0; j < 5; j++)
        {
            printf("%.2f ", students[i].grades[j]);
        }
        printf("\n");
    }

    return 0;
}