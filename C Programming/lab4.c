// Write a C Program to print the fibonacci series
#include <stdio.h>
int main()
{
    int num, first = 0, second = 1, next;
    printf("Enter the number of terms in the fibonacci series: ");
    scanf("%d", &num);
    if (num <= 0)
    {
        printf("Enter a positive integer for number of terms in the fibonacci series");
        return 1;
    }
    else
        printf("Fibonacci Series of first %d numbers: \n", num);
    for (int i = 0; i < num; i++)
    {
        printf("%d,", first);
        next = first + second;
        first = second;
        second = next;
    }

    return 0;
}
