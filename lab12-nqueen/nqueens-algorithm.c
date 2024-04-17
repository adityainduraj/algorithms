#include <stdio.h>
#include <stdbool.h>

#define N 10 // Maximum board size

int board[N][N];

// Function to print the solution
void printSolution(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a queen can be placed on board[row][col]
bool isSafe(int row, int col, int n) {
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < n; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// Function to solve the n-Queens problem using backtracking
bool solveNQueensUtil(int col, int n) {
    if (col >= n) {
        return true; // All queens are placed successfully
    }

    // Try placing this queen in all rows one by one
    for (int i = 0; i < n; i++) {
        // Check if queen can be placed on board[i][col]
        if (isSafe(i, col, n)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place rest of the queens
            if (solveNQueensUtil(col + 1, n)) {
                return true;
            }

            // If placing queen in board[i][col] doesn't lead to a solution then remove queen from board[i][col]
            board[i][col] = 0; // BACKTRACK
        }
    }

    // If queen can't be placed in any row in this column col, then return false
    return false;
}

// Main function to solve n-Queens problem
void solveNQueens(int n) {
    // Initialize all values of board to 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }

    if (solveNQueensUtil(0, n) == false) {
        printf("Solution does not exist");
        return;
    }

    printSolution(n);
}

int main() {
    int n;
    printf("Enter the number of Queens: ");
    scanf("%d", &n);

    if (n <= 0 || n > N) {
        printf("Invalid input. Please enter a number between 1 and %d\n", N);
        return 1;
    }

    solveNQueens(n);

    return 0;
}
