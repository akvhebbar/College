//Write a C program to check the number of days in a given month
// C program for the above approach 
#include <stdio.h> 
void printNumberOfDays(int N) 
{ 

	// Check for 31 Days 
	if (N == 1 || N == 3 || N == 5 || N == 7 || N == 8 || N == 10 || N == 12)
	{ 
		printf("31 Days."); 
	} 

	// Check for 30 Days 
	else if (N == 4 || N == 6 || N == 9 || N == 11)
	{ 
		printf("30 Days."); 
	} 

	// Check for 28/29 Days 
	else if (N == 2) 
	{ 
		printf("28/29 Days."); 
	} 

	// Else Invalid Input 
	else 
	{ 
		printf("Invalid Month."); 
	} 
} 
int main() 
{ 
	// Input Month 
	int N = 4; 

	// Function Call 
	printNumberOfDays(N); 

	return 0; 
}