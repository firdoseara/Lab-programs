#include <stdio.h>
#include <stdbool.h>

#define N 4

void printsolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

bool issafe(int board[N][N], int row, int col) {
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solvenqutil(int board[N][N], int col) {
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (issafe(board, i, col)) {
            board[i][col] = 1;

            if (solvenqutil(board, col + 1))
                return true;

            board[i][col] = 0; 
        }
    }

    return false;
}

void solvenq() {
    int board[N][N] = {0};

    if (solvenqutil(board, 0) == false) {
        printf("No solution exists");
        return;
    }

    printsolution(board);
}

int main() {
    solvenq();
    return 0;
}
