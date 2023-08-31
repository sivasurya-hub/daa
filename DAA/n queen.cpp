#include <stdio.h>
#include <stdbool.h>

#define N 10 // Maximum board size

int board[N][N];

void initializeBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }
}

void printBoard(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", board[i][j] == 1 ? 'Q' : '-');
        }
        printf("\n");
    }
}

bool isSafe(int row, int col, int n) {
    for (int i = 0; i < col; i++) {
        if (board[row][i])
            return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j])
            return false;
    }

    return true;
}

bool solveNQueens(int col, int n) {
    if (col >= n)
        return true;

    for (int i = 0; i < n; i++) {
        if (isSafe(i, col, n)) {
            board[i][col] = 1;

            if (solveNQueens(col + 1, n))
                return true;

            board[i][col] = 0; // Backtrack
        }
    }

    return false;
}

int main() {
    int n;
    printf("Enter the value of N for N-Queens: ");
    scanf("%d", &n);

    if (n <= 0 || n > N) {
        printf("Invalid board size.\n");
        return 1;
    }

    initializeBoard();

    if (solveNQueens(0, n)) {
        printf("Solution found:\n");
        printBoard(n);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}

