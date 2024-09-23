// write a C Program to print multiplication table of 5
#include <stdio.h>
int main()
{

	int N = 5;
	for(int i=1;i<=10;i++)
	{
		printf("%d\tx\t%d\t=\t%d\n", N, i, N * i);
	} 
	return 0;
}