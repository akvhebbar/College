/*Write a C program to read the size of a one-dimensional array from the user and read 10 elements into the array (positive integers) and
1. print alternate numbers starting from index value 1.
2. Reverse the array elements and print the same.*/
#include <stdio.h>
int main()
{
    int size, a[100];
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    if (size < 10)
    {
        printf("Please enter a size of at least 10.\n");
        return 1;
    }
    printf("Enter %d positive integers:\n", size);
    for (int i = 0; i < size; ++i)
        scanf("%d", &a[i]);

    printf("\nAlternate numbers starting from index 1:\n");
    for (int i = 1; i < size; i += 2)
        printf("%d ", a[i]);
    printf("\n");

    printf("\nReversed array elements:\n");
    for (int i = size - 1; i >= 0; --i)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
