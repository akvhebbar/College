/*Write a C program to find the power of number using while loop,
base number>0 and exponent>=0 taken from test cases*/
#include <stdio.h>
int main() 
{
    double base, result = 1;
    int exponent;
    printf("Enter the base number: ");
    scanf("%lf", &base);
    printf("Enter a non-negative integer exponent: ");
    scanf("%d", &exponent);
    int i = 0;
    while (i < exponent)
    {
        result *= base;
        i++;
    }
    printf("%.2lf raised to the power of %d is %.2lf.\n", base, exponent, result);
    return 0;
}
