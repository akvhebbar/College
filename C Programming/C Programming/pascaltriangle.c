#include <stdio.h>

// Function to print Pascal's Triangle
void printPascal(int n) {
    for (int line = 0; line < n; line++) {
        int coef = 1; // Used to represent C(line, i)
        for (int space = 1; space <= n - line; space++)
            printf("  "); // Print spaces for alignment

        for (int i = 0; i <= line; i++) {
            printf("%4d", coef); // Print the coefficient
            coef = coef * (line - i) / (i + 1); // Update the coefficient
        }
        printf("\n"); // Move to the next line
    }
}

int main() {
    int n = 5; // Number of rows
    printPascal(n);
    return 0;
}
