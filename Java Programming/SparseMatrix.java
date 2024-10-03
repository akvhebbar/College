/**Write a java program to check whether the given matrix is sparse matrix or not. And
also find sum of all the elements of the sparse matrix.**/
import java.util.Scanner;
public class SparseMatrix
{
public static void main(String[] args){
// declare variables
int m,n;
// To take input from the user
Scanner sc = new Scanner(System.in);
System.out.println("Enter the number of rows ");
// Initialize the number of rows
m = sc.nextInt();
System.out.println("Enter the number of columns ");
// Initialize the number of columns
n = sc.nextInt();
// declare a mxn order array
int a[][] = new int[m][n];
System.out.println("Enter all the values of matrix ");
// Initialize the matrix elements
for (int i = 0; i < m; i++)
{
for (int j = 0; j < n; j++)
{
a[i][j] = sc.nextInt();
}
}
System.out.println("Matrix:");
for (int i = 0; i < m; i++)
{
for (int j = 0; j < n; j++)
{
System.out.print(a[i][j] + " ");
}
System.out.println("");
}
int size= m*n; //Stores the size of the matrix
int count=0; //Variable to check for the number of 0 elements
int sum = 0; //calculate sum if the element is non-zero
//Loop to count all zero element present in matrix
for(int i = 0; i < m; i++)
{
for(int j = 0; j < n; j++)
{
if(a[i][j] == 0) //Check if element is 0 or not
count++; //Increment the count if 0 element is found
else sum = sum + a[i][j]; //calculate sum
}
}
if(count>(size/2))
System.out.println("It is a sparse matrix and sum is "+ sum);
else
System.out.println("It is not a sparse matrix");
sc.close();
}
}