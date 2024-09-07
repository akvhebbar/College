//Write a C program to find the largest numbers among the three numbers using if and logical && operator
#include <stdio.h>

int main() 
{
    float num1, num2, num3;
    printf("Enter three numbers: ");
    scanf("%f %f %f", &num1, &num2, &num3);
    if (num1 >= num2 && num1 >= num3) 
        printf("%.2lf is the largest number.\n", num1);
    else if (num2 >= num1 && num2 >= num3) 
        printf("%.2lf is the largest number.\n", num2);
    else 
        printf("%.2lf is the largest number.\n", num3);
    return 0;
}
