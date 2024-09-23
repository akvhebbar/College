//Write a C program to calculate the standard deviation
#include <stdio.h>
#include<math.h>
int main() 
{
    float a[50],sum=0,sum1=0,mean,v,sd;
    int n,i;
    printf("enter the number of observation:");
    scanf("%d",&n);
    printf("Enter each observation:");
    for(i=0;i<n;i++)/*accepting in array*/
    {
        scanf("%f",&a[i]);
    }
    for(i=0;i<n;i++)/*sum of each value*/
    {
        sum=sum+a[i];
    }
    mean=sum/n;/*mean*/
    for(i=0;i<n;i++)
    {
        sum1=sum1+(mean*a[i]);/*variance*/
    }
    v=sum1/n;
    sd=sqrt(v);/*std.dev*/
    printf("mean is %f",mean);
    printf("\n mean is %f",mean);
    printf ("\n standard deviation is %f",sd);
    return 0;
}