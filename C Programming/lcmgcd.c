//Write a c program to find gcd and lcm of two integers
#include<stdio.h>
int main()
{
    int n1,n2,gcd,lcm;
    printf("Enter any two integers: ");
    scanf("%d %d",&n1,&n2);
    //To find GCD of two integers
    int a=n1,b=n2;
    while(b!=0)
    {
        int temp=b;
        b=a%b;
        a=temp;
    }
    gcd=a;
    //To find the LCM of two integers
    lcm=(n1*n2)/gcd;
    printf("The GCD and LCM of %d and %d is %d and %d",n1,n2,gcd,lcm);
    return 0;
}  