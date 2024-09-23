//Write a C Program to replace all 0s with 1s in a given integer
#include<stdio.h>
int main()
{
int num,num2=0;
printf("Enter number: ");
scanf("%d", &num);
if(num == 0)
num2=1;
while(num>0)
{
int rem = num%10;
if(rem == 0)
rem = 1;
num = num/10;
num2=num2*10+rem;
}
num = 0 ; // Store the reverse of num2
while(num2>0)
{
int r = num2%10;
num= num*10 + r;
num2 /= 10;
}
printf("Converted number is: %d" ,num);
return 0;
}