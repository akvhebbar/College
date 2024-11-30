/* Problem Statement:
You are working on a genetics research project and have been tasked with creating a C program to analyze genetic
sequences. Genetic sequences are represented as strings of characters (A: Adenine, T: Thymine, C: Cytosine, and G:
Guanine), where each character represents a nucleotide in the DNA sequence.
You need to develop a C program that performs basic analysis on genetic sequences provided by the user. The program
will use dynamic memory allocation to store the genetic sequences and arrays to store the analysis results. The program
will have the following functionalities:
1. Input Genetic Sequences: The program should prompt the user to input a number of genetic sequences. Each
sequence should be stored dynamically in memory.
2. Analysis Functions:
a. Count Nucleotides: Write a function that takes a genetic sequence as input and counts the occurrences of
each nucleotide (A, C, G, and T) in that sequence. Store the counts in an array.
b. Calculate GC Content: Write a function that calculates the GC content (the percentage of G and C
nucleotides) of a genetic sequence. Store the GC content in an array. The GC content of a DNA sequence
is calculated using the following formula:
𝐺𝐶 𝐶𝑜𝑛𝑡𝑒𝑛𝑡 =(𝑁𝑢𝑚𝑏𝑒𝑟 𝑜𝑓 𝐺 𝑎𝑛𝑑 𝐶 𝑛𝑢𝑐𝑙𝑒𝑜𝑡𝑖𝑑𝑒𝑠/𝑇𝑜𝑡𝑎𝑙 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜𝑓 𝑛𝑢𝑐𝑙𝑒𝑜𝑡𝑖𝑑𝑒𝑠)× 𝟏𝟎𝟎
3. Display Results: After analyzing all the input sequences, display the analysis results for each sequence.
Display the counts of each nucleotide and the calculated GC content.
Requirements:
Use dynamic memory allocation to store genetic sequences.
Use arrays to store the analysis results (nucleotide counts and GC content) for each sequence.
Implement separate functions for counting nucleotides and calculating GC content.
Use appropriate data types and structures to store the information.*/

#include <stdio.h>
#include <stdlib.h>
// Function to count nucleotides in a genetic sequence
void countNucleotides(char *sequence, int *counts)
{
    for (int i = 0; sequence[i] != '\0'; i++)
    {
        switch (sequence[i])
        {
        case 'A':
            counts[0]++;
            break;
        case 'C':
            counts[1]++;
            break;
        case 'G':
            counts[2]++;
            break;
        case 'T':
            counts[3]++;
            break;
        }
    }
}
// Function to calculate GC content of a genetic sequence
double calculateGCContent(char *sequence)
{
    int totalNucleotides = 0;
    int gcCount = 0;
    for (int i = 0; sequence[i] != '\0'; i++)
    {
        if (sequence[i] == 'G' || sequence[i] == 'C')
        {
            gcCount++;
        }
        totalNucleotides++;
    }
    return ((double)gcCount / totalNucleotides) * 100.0;
}
// Main function
int main()
{
    int numSequences;
    printf("Genetic Sequence Analyzer\n\n");
    printf("Enter the number of genetic sequences: ");
    scanf("%d", &numSequences);
    char **sequences = (char **)malloc(numSequences * sizeof(char *));
    int **nucleotideCounts = (int **)malloc(numSequences * sizeof(int *));
    double *gcContent = (double *)malloc(numSequences * sizeof(double));
    for (int i = 0; i < numSequences; i++)
    {
        sequences[i] = (char *)malloc(100 * sizeof(char));   // Assuming max sequence length of 100 characters
        nucleotideCounts[i] = (int *)calloc(4, sizeof(int)); // Initialize counts to zero
        gcContent[i] = 0.0;
        printf("Enter genetic sequence %d: ", i + 1);
        scanf("%s", sequences[i]);
        countNucleotides(sequences[i], nucleotideCounts[i]);
        gcContent[i] = calculateGCContent(sequences[i]);
    }
    printf("\nAnalysis Results:\n");
    for (int i = 0; i < numSequences; i++)
    {
        printf("Sequence %d:\n", i + 1);
        printf("A: %d\n", nucleotideCounts[i][0]);
        printf("C: %d\n", nucleotideCounts[i][1]);
        printf("G: %d\n", nucleotideCounts[i][2]);
        printf("T: %d\n", nucleotideCounts[i][3]);
        printf("GC Content: %.2f%%\n", gcContent[i]);
        printf("\n");
    }
    // Free allocated memory
    for (int i = 0; i < numSequences; i++)
    {
        free(sequences[i]);
        free(nucleotideCounts[i]);
    }
    free(sequences);
    free(nucleotideCounts);
    free(gcContent);
    return 0;
}