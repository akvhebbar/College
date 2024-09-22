#include<stdio.h>
#include<stdlib.h>
typedef struct {
    char symbol; // 'X' or 'O'
    int score;   // 1 for win, 0 for loss
} Player;
char** initializeGrid() {
    char** grid = (char**)malloc(3 * sizeof(char*));
    for (int i = 0; i < 3; i++) {
        grid[i] = (char*)malloc(3 * sizeof(char));
        for (int j = 0; j < 3; j++) {
            grid[i][j] = ' ';
        }
    }
    return grid;
}
void printGrid(char** grid) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", grid[i][j]);
            if (j < 2) printf("| ");
        }
        printf("\n");
        if (i < 2) printf("---------\n");
    }
}
int checkWin(char** grid, char symbol) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol) ||
            (grid[0][i] == symbol && grid[1][i] == symbol && grid[2][i] == symbol)) {
            return 1;
        }
    }
    // Check diagonals
    if ((grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol) ||
        (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol)) {
        return 1;
    }
    return 0;
}
int main() {
    Player playerX = {'X', 0};
    Player playerO = {'O', 0};
    char** grid = initializeGrid();
    int moves = 0;
    Player* currentPlayer = &playerX;

    while (moves < 9) {
        int row, col;
        printGrid(grid);
        printf("Player %c, enter your move (row and column): ", currentPlayer->symbol);
        scanf("%d %d", &row, &col);

        if (row < 0 || row >= 3 || col < 0 || col >= 3 || grid[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        grid[row][col] = currentPlayer->symbol;
        moves++;

        if (checkWin(grid, currentPlayer->symbol)) {
            printGrid(grid);
            printf("Player %c wins!\n", currentPlayer->symbol);
            currentPlayer->score = 1;
            break;
        }

        currentPlayer = (currentPlayer == &playerX) ? &playerO : &playerX;
    }

    if (moves == 9) {
        printGrid(grid);
        printf("It's a tie!\n");
    }

    for (int i = 0; i < 3; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
