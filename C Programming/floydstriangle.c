// Write a C program to print the Floyd's Triangle
#include <stdio.h>
int main() 
{
   int n,i,j,k = 1;
   printf("Enter the number of rows for for Floyd's Triangle ");
   scanf("%d",&n);
   for(i = 1; i <= n; i++)
   {
      for(j = 1;j <= i; j++)
         printf("%3d", k++);

      printf("\n");
   }

   return 0;
}