// Write a C program to perform string concatenation using the library function strcat()
#include <stdio.h>
#include <string.h>
int main()
{
    char str1[50], str2[50];
    printf("Enter the string1 ");
    gets(str1);
    printf("Enter the string2 ");
    gets(str2);
    strcat(str1, str2);
    printf("The Concatenated string is ");
    puts(str1);
    return 0;
}
