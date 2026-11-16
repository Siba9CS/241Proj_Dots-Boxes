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
        printf("%-3d ", c);
    printf("\n");

    for (r = 0; r < BOX_ROWS; r++) {
        printf("%d ", r);

        for (c = 0; c < BOX_COLS; c++) {
            printf(".");
            printf("%s", b->hLine[r][c] ? "---" : "   ");
        }
        printf(".\n");

        printf("  ");

        for (c = 0; c < BOX_COLS; c++) {
            printf("%c", b->vLine[r][c] ? '|' : ' ');
            printf("%c", b->owner[r][c] == ' ' ? ' ' : b->owner[r][c]);
        }

        printf("%c\n", b->vLine[r][BOX_COLS] ? '|' : ' ');
    }

    printf("%d ", BOX_ROWS);

    for (c = 0; c < BOX_COLS; c++) {
        printf(".");
        printf("%s", b->hLine[BOX_ROWS][c] ? "---" : "   ");
    }
    printf(".\n");
}


static int box_complete(const Board *b, int r, int c)
{
    return b->hLine[r][c] && b->hLine[r + 1][c] &&
           b->vLine[r][c] && b->vLine[r][c + 1];
}



static int try_claim(Board *b, int r, int c, int player)
{
    if (player < 0 || player > 1)
        return 0;

    if (b->owner[r][c] == ' ' && box_complete(b, r, c)) {
        b->owner[r][c] = (char)('A' + player);
        b->score[player]++;
        b->boxesTaken++;
        return 1;
    }

    return 0;
}



int make_move(Board *b, int r1, int c1, int r2, int c2, int player)
{
    int claimed = 0;
    int tmp;

    if (r1 < 0 || r1 > BOX_ROWS || r2 < 0 || r2 > BOX_ROWS ||
        c1 < 0 || c1 > BOX_COLS || c2 < 0 || c2 > BOX_COLS)
        return MOVE_OUT_OF_RANGE;
    if (r1 == r2 && c1 == c2)
        return MOVE_SAME_DOT;

    
    if (r1 > r2 || c1 > c2) {
        tmp = r1; r1 = r2; r2 = tmp;
        tmp = c1; c1 = c2; c2 = tmp;
    }

    if (r1 == r2 && c2 == c1 + 1) {              
        if (b->hLine[r1][c1])
            return MOVE_ALREADY_DRAWN;
        b->hLine[r1][c1] = 1;
        if (r1 > 0)        claimed += try_claim(b, r1 - 1, c1, player);
        if (r1 < BOX_ROWS) claimed += try_claim(b, r1, c1, player);     
    } else if (c1 == c2 && r2 == r1 + 1) {
        if (b->vLine[r1][c1])
            return MOVE_ALREADY_DRAWN;
        b->vLine[r1][c1] = 1;
        if (c1 > 0)        claimed += try_claim(b, r1, c1 - 1, player);
        if (c1 < BOX_COLS) claimed += try_claim(b, r1, c1, player);
    } else {
        return MOVE_NOT_ADJACENT;
    }
    return claimed;
}

int board_is_full(const Board *b)
{
    return b->boxesTaken == TOTAL_BOXES;
}
