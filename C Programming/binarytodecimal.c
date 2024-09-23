//write a C program to convet binary number to decimal number
#include <stdio.h>
#include <math.h>
int main() 
{
long long n;
int dec=0,i=0,rem;
printf("Enter a binary number: ");
scanf("%lld", &n);
while (n != 0) 
{
	rem = n % 10;
    	dec =dec+ rem * pow(2, i);
    	++i;
	n=n/10;
}
printf("%lld in binary = %d in decimal", n,dec);
return 0;
}