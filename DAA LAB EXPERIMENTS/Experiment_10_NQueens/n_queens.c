#include <stdio.h>

#define N 4

int board[N][N] = {0};

int safe(int row, int col) {
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    for (i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

int solve(int col) {
    if (col == N)
        return 1;

    for (int row = 0; row < N; row++) {
        if (safe(row, col)) {
            board[row][col] = 1;

            if (solve(col + 1))
                return 1;

            board[row][col] = 0;
        }
    }

    return 0;
}

int main() {
    if (solve(0)) {
        printf("Solution:\n");

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                printf("%d ", board[i][j]);

            printf("\n");
        }
    } else {
        printf("No solution");
    }

    return 0;
}