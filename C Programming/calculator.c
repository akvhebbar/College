//Write a C Program to perform basic calculator operation using switch case
#include<stdio.h>
int main()
{
	int n1,n2,sum,diff,p,result;
	char op;
	printf("Enter the operation '+,-,*,/'");
	scanf("%c",&op);
	printf("Enter any two Integers: ");
	scanf("%d %d",&n1,&n2);
	switch(op)
	{
		case '+':
			printf("The operation is addition");
			sum=n1+n2;
			printf("\nThe sum of %d and %d is %d",n1,n2,sum);
			break;
		case '-':
			printf("The operation is Subtraction");
			diff=n1-n2;
			printf("The Difference of %d and %d is %d",n1,n2,diff);
			break;
		case '*':
			p=n1*n2;
			printf("The product of %d and %d is %d",n1,n2,p);
			break;
		case '/':
			if(n2!=0)
			{
				
				result=(float)n1/n2;
				printf("The quotient of %d divided by %d is %f",n1,n2,result);
			}
			else
				printf("Any number cannot be divided by 0");
				break;
			default:
				printf("Operator not  defined");
			
			return 0;	
	}
}
