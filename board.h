#ifndef BOARD_H
#define BOARD_H
#define BOX_ROWS 4
#define BOX_COLS 5
#define TOTAL_BOXES (BOX_ROWS * BOX_COLS)


#define MOVE_OUT_OF_RANGE  (-1)
#define MOVE_SAME_DOT      (-2)
#define MOVE_NOT_ADJACENT  (-3)
#define MOVE_ALREADY_DRAWN (-4)

typedef struct {
    int hLine[BOX_ROWS + 1][BOX_COLS];
    int vLine[BOX_ROWS][BOX_COLS + 1];
    char owner[BOX_ROWS][BOX_COLS];
    int score[2];
    int boxesTaken;
} Board;

void board_init(Board *b);
void board_print(const Board *b);
int  make_move(Board *b, int r1, int c1, int r2, int c2, int player);
int  board_is_full(const Board *b);

#endif
