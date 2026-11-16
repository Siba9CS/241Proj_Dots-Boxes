
void board_print(const Board *b)
{
    int r, c;

   
    printf("  ");
    for (c = 0; c <= BOX_COLS; c++)
        printf("%-2d", c);
    printf("\n");

    for (r = 0; r < BOX_ROWS; r++) {

    
        printf("%d ", r);

        for (c = 0; c < BOX_COLS; c++) {
            printf(".");
            printf("%c", b->hLine[r][c] ? '-' : ' ');
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
        printf("%c", b->hLine[BOX_ROWS][c] ? '-' : ' ');
    }

    printf(".\n");
}

