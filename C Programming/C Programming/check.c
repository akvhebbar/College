/*Write a C program to find whether a triangle can be formed or not by considering length
of the three sides as input and display the output accordingly*/
#include <stdio.h>
int main() 
{
    float side1, side2, side3;
    printf("Enter the lengths of three sides (separated by spaces): ");
    scanf("%f %f %f", &side1, &side2, &side3);
    if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1) 
        printf("A triangle can be formed with these side lengths.\n");
    else
        printf("These side lengths do not form a valid triangle.\n");
    return 0;
}
