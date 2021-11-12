#include "funkcii.h"
#include <stdio.h>
#include <malloc.h>

void print_sudoku(const int puzzle[SUDOKU_H][SUDOKU_W]) {
    for (int i=0; i<SUDOKU_H; i++) {
        for (int j=0; j<SUDOKU_W; j++) {
            printf("%d ",puzzle[i][j]);
        }
        printf("\n");
    }
}
int possible_move(const int puzzle[SUDOKU_H][SUDOKU_W],int y, int x, int input) {
    for (int i=0; i<SUDOKU_H; i++) {
        if (puzzle[i][x] == input)
            return 0;
    }
    for (int j=0; j<SUDOKU_W; j++) {
        if (puzzle[y][j] == input)
            return 0;
    }
    const int base_y = y/SUBGRID_H*SUBGRID_H;
    const int base_x = x/SUBGRID_W*SUBGRID_W;
    for (int k=0; k<SUBGRID_H*SUBGRID_W; k++) {
        if (puzzle[base_y + k/SUBGRID_H][base_x + k%SUBGRID_W] == input)
            return 0;
    }
    return 1;
}
void push_move(int y, int x) {
    struct Move* old = (struct Move*) malloc(sizeof(struct Move));
    *old = *top;
    top->y = y;
    top->x = x;
    top->move_prior = old;
}
void pop_move() {
    if (top->move_prior != NULL) {
        struct Move **topptr = &top;
        struct Move *next = (*topptr)->move_prior;
        free(*topptr);
        *topptr = next;
    }
}
struct Move first = {-1,-1,NULL};
struct Move* top = &first;