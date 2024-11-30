/*Write a C program to define a structure named Student with name and DOB, where, DOB in turn is a structure with day, month and year. Using the concept of nested structures display your name and date of birth.*/
#include <stdio.h>

struct DOB
{
    int day;
    int month;
    int year;
};

struct Student
{
    char name[50];
    struct DOB birthDate;
};
int main()
{

    struct Student student;

    printf("Enter your name: ");
    scanf("%s", student.name);
    printf("Enter your date of birth (DD MM YYYY): ");
    scanf("%d%d%d", &student.birthDate.day, &student.birthDate.month, &student.birthDate.year);

    printf("\nStudent Information:\n");
    printf("Name: %s", student.name);
    printf("\nDate of Birth: %02d/%02d/%d\n", student.birthDate.day, student.birthDate.month, student.birthDate.year);
    return 0;
}
