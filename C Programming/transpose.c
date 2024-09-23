//Write a C program to compose the transpose of the matrix
#include <stdio.h>
int main() 
{
  int a[10][10], transpose[10][10], r, c;
  printf("Enter rows and columns: ");
  scanf("%d %d", &r, &c);

  // asssigning elements to the matrix
  printf("\nEnter matrix elements:\n");
  for (int i = 0; i < r; ++i)
  for (int j = 0; j < c; ++j) 
  {
    scanf("%d", &a[i][j]);
  }
  
  // computing the transpose
  for (int i = 0; i < r; ++i)
  for (int j = 0; j < c; ++j)
  {
    transpose[j][i] = a[i][j];
  }

  // printing the transpose
  printf("\nTranspose of the matrix:\n");
  for (int i = 0; i < c; ++i)
  for (int j = 0; j < r; ++j) 
  {
    printf("%d  ", transpose[i][j]);
    if (j == r - 1)
    printf("\n");
  }
  return 0;
}