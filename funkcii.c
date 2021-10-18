//
// Created by Aleksandar on 17-Oct-21.
//

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
bool possible_move(const int puzzle[SUDOKU_H][SUDOKU_W],int y, int x, int input) {
    for (int l=0; l<9; l++) {
        if (puzzle[y][l] == input || puzzle[l][x] == input || puzzle[(y/3)*3 + l/3][(x/3)*3 + l%3] == input)
            return false;
    }
    return true;
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
