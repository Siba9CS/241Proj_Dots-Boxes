#include <stdio.h>
#include "board.h"

void board_init(Board *b)
{
    int r, c;

    for (r = 0; r <= BOX_ROWS; r++)
        for (c = 0; c < BOX_COLS; c++)
            b->hLine[r][c] = 0;

    for (r = 0; r < BOX_ROWS; r++)
        for (c = 0; c <= BOX_COLS; c++)
            b->vLine[r][c] = 0;

    for (r = 0; r < BOX_ROWS; r++)
        for (c = 0; c < BOX_COLS; c++)
            b->owner[r][c] = ' ';

    b->score[0] = 0;
    b->score[1] = 0;
    b->boxesTaken = 0;
}

void board_print(const Board *b)
{
    int r, c;

    printf("  ");
    for (c = 0; c <= BOX_COLS; c++)
        printf("%d ", c);
    printf("\n");

    for (r = 0; r <= BOX_ROWS; r++) {
        printf("%d ", r);
        for (c = 0; c <= BOX_COLS; c++) {
            printf(".");
            if (c < BOX_COLS)
                printf("%c", b->hLine[r][c] ? '-' : ' ');
        }
        printf("\n");

        if (r < BOX_ROWS) {
            printf("  ");
            for (c = 0; c <= BOX_COLS; c++) {
                printf("%c", b->vLine[r][c] ? '|' : ' ');
                if (c < BOX_COLS)
                    printf("%c", b->owner[r][c]);
            }
            printf("\n");
        }
    }
}
