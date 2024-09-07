//Write a C program to find the factorial of a given number using while loop
#include <stdio.h>
int main() 
{
    int number;
    long long factorial = 1; 
    printf("Enter a non-negative integer: ");
    scanf("%d", &number);
    int i = 1;
    while (i <= number) 
    {
        factorial *= i;
        i++;
    }
    printf("Factorial of %d is %lld.\n", number, factorial);
    return 0;
}
