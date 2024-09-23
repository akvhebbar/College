//Write a C program to find the roots of the quadratic equation
#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c;
	float d,root1,root2;
	printf("Enter the coeffficients of the quadratic equation a,b,c: ");
	scanf("%d %d %d",&a,&b,&c);
	d=b*b-4*a*c;
	if(d>0)
	{
		printf("The roots are real and distinct");
		root1=(-b-sqrt(d))/(2*a);
		root2=(-b+sqrt(d))/(2*a);
		printf("\nThe roots of the quadratic equation is %f and %f",root1,root2);
		
	}
	else if(d==0)
	{
		printf("The roots are real and equal");
		root1=root2=(-b)/(2*a);
		printf("\nThe roots of the quadratic equation is %f and %f",root1,root2);
		
	}
	else if(d<0)
	{
		printf("The roots are complex and imaginary");
		root1=(-b)/(2*a);
		root2=sqrt(-d)/(2*a);
		printf("\nThe roots of the quadratic equation is %f and %f",root1,root2);
	}
	return 0;
}