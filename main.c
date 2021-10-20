#include <stdio.h>
#include <stdbool.h>
#include "funkcii.h"
int main() {
    int sudoku[SUDOKU_H][SUDOKU_W] = {0};
    printf("Enter the incomplete sudoku puzzle:\n");
    for (int i=0; i<SUDOKU_H; i++) {
        for (int j=0; j<SUDOKU_W; j++) {
            scanf("%d",&sudoku[i][j]);
        }
    }
    bool error = false;
    bool solvable = true;
    while (solvable) {
        for (int i = 0; solvable && i < SUDOKU_H; i++) {
            for (int j = 0; solvable && j < SUDOKU_W; j++) {
                if (error) {
                    if (top->move_prior == NULL) {
                        solvable = false;
                    } else {
                        i = top->y;
                        j = top->x;
                        pop_move();
                    }
                }
                if (sudoku[i][j] == 0 || error) {
                    int k = sudoku[i][j] + 1;
                    sudoku[i][j] = 0;
                    while (k <= ENTRY_MAX) {
                        sudoku[i][j] = 0;
                        if (possible_move(sudoku, i, j, k)) {
                            sudoku[i][j] = k;
                            push_move(i, j);
                            error = false;
                            break;
                        }
                        k++;
                    }
                    if (sudoku[i][j] == 0) {
                        error = true;
                    }
                }
            }
        }
        if (solvable && !error) {
            printf("\n");
            print_sudoku(sudoku);
            error = true;
        }
    }
    printf("Tolku od resenijata majstore.\n");
    return 0;
}