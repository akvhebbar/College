/*Problem Statement: Dynamic Memory Allocation, Arrays, and Structures: Tic-Tac-Toe Game
In this programming assignment, you will implement a Tic-Tac-Toe game in C that utilizes dynamic memory
allocation, arrays, and structures. The game will be played between two players, 'X' and 'O', on a 3x3 grid. The
program will dynamically allocate memory for the grid and use structures to represent the players and their moves.
1. Create a structure named Player with the following attributes:
a. char symbol: To store the player's symbol ('X' or 'O').
b. int score: To store the player's score (1 for win, 0 for loss).
2. Implement a function named initializeGrid that dynamically allocates memory for a 3x3 grid. Initialize the grid
with empty spaces (' ').
3. Implement a function named printGrid that takes the dynamically allocated grid as input and prints the current
state of the Tic-Tac-Toe grid.
4. Implement a function named checkWin that checks if a player has won the game. It should take the grid and the
current player's symbol as input and return 1 if the player has won, 0 otherwise.
5. Implement the main function:
a. Initialize two instances of the Player structure, one for 'X' and one for 'O'.
b. Use a loop to alternate between players and allow them to make moves.
c. For each move, prompt the current player to enter their row and column choices.
d. Validate the inputs to ensure they are within the valid range and the chosen cell is not already occupied.
e. After each move, update the grid and print its current state.
f. Check if the current player has won using the checkWin function.
g. If a player wins, update their score and display the winner.
h. If the grid is full and no one has won, display a tie message.
6. Properly deallocate the dynamically allocated memory for the grid at the end of the program.
7. Use proper error handling and input validation to handle incorrect user inputs gracefully.*/

#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char symbol; // 'X' or 'O'
    int score;   // 1 for win, 0 for loss
} Player;
char **initializeGrid()
{
    char **grid = (char **)malloc(3 * sizeof(char *));
    for (int i = 0; i < 3; i++)
    {
        grid[i] = (char *)malloc(3 * sizeof(char));
        for (int j = 0; j < 3; j++)
        {
            grid[i][j] = ' ';
        }
    }
    return grid;
}
void printGrid(char **grid)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c ", grid[i][j]);
            if (j < 2)
                printf("| ");
        }
        printf("\n");
        if (i < 2)
            printf("---------\n");
    }
}
int checkWin(char **grid, char symbol)
{
    // Check rows and columns
    for (int i = 0; i < 3; i++)
    {
        if ((grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol) ||
            (grid[0][i] == symbol && grid[1][i] == symbol && grid[2][i] == symbol))
        {
            return 1;
        }
    }
    // Check diagonals
    if ((grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol) ||
        (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol))
    {
        return 1;
    }
    return 0;
}
int main()
{
    Player playerX = {'X', 0};
    Player playerO = {'O', 0};
    char **grid = initializeGrid();
    int moves = 0;
    Player *currentPlayer = &playerX;

    while (moves < 9)
    {
        int row, col;
        printGrid(grid);
        printf("Player %c, enter your move (row and column): ", currentPlayer->symbol);
        scanf("%d %d", &row, &col);

        if (row < 1 || row > 3 || col < 1 || col > 3 || grid[row - 1][col - 1] != ' ')
        {
            printf("Invalid move. Try again.\n");
            continue;
        }

        grid[row - 1][col - 1] = currentPlayer->symbol;
        moves++;

        if (checkWin(grid, currentPlayer->symbol))
        {
            printGrid(grid);
            printf("Player %c wins!\n", currentPlayer->symbol);
            currentPlayer->score = 1;
            break;
        }

        currentPlayer = (currentPlayer == &playerX) ? &playerO : &playerX;
    }

    if (moves == 9)
    {
        printGrid(grid);
        printf("It's a tie!\n");
    }

    for (int i = 0; i < 3; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
