// Write a program to perform matrix multiplication
#include <stdio.h>
int main()
{
    int a[50][50], b[50][50], r[20][20], r1, r2, c1, c2, i, j, k;
    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d%d", &r1, &c1);
    printf("Enter the number of rows and columns of the second matrix ");
    scanf("%d%d", &r2, &c2);

    if (c1 == r2)
    {
        printf("Enter the first matrix elements\n");
        for (i = 0; i < r1; i++)
            for (j = 0; j < c1; j++)
                scanf("%d", &a[i][j]);
        printf("Enter the second matrix elements\n");
        for (i = 0; i < r2; i++)
            for (j = 0; j < c2; j++)
                scanf("%d", &b[i][j]);
    }

    else if (c1 != r2)
    {
        printf("Matrix multiplication is not possible due to incompatible dimensions.");
        return 0;
    }

    for (i = 0; i < r1; ++i)
    {
        for (j = 0; j < c2; ++j)
        {
            r[i][j] = 0;
            for (k = 0; k < c1; ++k)
            {
                r[i][j] = r[i][j] + a[i][k] * b[k][j];
            }
        }
    }
    printf("\nResultant Matrix\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            printf("%d\t", r[i][j]);
        }
        printf("\n");
    }
    return 1;
}
