#ifndef SUDOKU_FUNKCII_H
#define SUDOKU_FUNKCII_H

//PARAMETRI

#define SUDOKU_H 9
#define SUDOKU_W 9
#define SUBGRID_H 3
#define SUBGRID_W 3
#define ENTRY_MAX 9

//STRUKTURI

struct Move {
    int y;
    int x;
    struct Move* move_prior;
};

//FUNKCII

void print_sudoku(const int puzzle[SUDOKU_H][SUDOKU_W]);
void push_move(int y, int x);
void pop_move();
int possible_move(const int puzzle[SUDOKU_H][SUDOKU_W],int y, int x, int input);

//PROMENLIVI

extern struct Move* top;

#endif //SUDOKU_FUNKCII_H
