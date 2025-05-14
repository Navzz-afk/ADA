#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void printSolution(int** board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%s", board[i][j] ? "Q " : ". ");
        printf("\n");
    }
    printf("\n");
}


bool isSafe(int** board, int row, int col, int N) {
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


bool solveNQueensUtil(int** board, int col, int N) {
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;

            if (solveNQueensUtil(board, col + 1, N))
                return true;


            board[i][col] = 0;
        }
    }

    return false;
}


bool solveNQueens(int N) {

    int** board = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        board[i] = (int*)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++)
            board[i][j] = 0;
    }

    if (!solveNQueensUtil(board, 0, N)) {
        printf("Solution does not exist for N = %d\n", N);

        for (int i = 0; i < N; i++)
            free(board[i]);
        free(board);
        return false;
    }

    printSolution(board, N);


    for (int i = 0; i < N; i++)
        free(board[i]);
    free(board);
    return true;
}


int main() {
    int N;
    printf("Enter the size of the board (N): ");
    scanf("%d", &N);

    if (N < 1) {
        printf("N must be at least 1.\n");
        return 1;
    }

    solveNQueens(N);
    return 0;
}
