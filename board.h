#ifndef BOARD_H
#define BOARD_H

#define BOX_ROWS 4
#define BOX_COLS 5

typedef struct {
    int hLine[BOX_ROWS + 1][BOX_COLS];
    int vLine[BOX_ROWS][BOX_COLS + 1];
    char owner[BOX_ROWS][BOX_COLS];
    int score[2];
    int boxesTaken;
} Board;

void board_init(Board *b);
void board_print(const Board *b);

#endif
