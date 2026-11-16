
#include <stdio.h>
#include "board.h"

int main(void)
{
    Board board;
    int r1, c1, r2, c2;
    int player = 0;
    int result;

    board_init(&board);

    printf("Welcome to Dots and Boxes!\n");
    printf("Board size: 4 x 5 boxes\n");

    while (!board_is_full(&board)) {
        board_print(&board);

        printf("\nPlayer %c's turn\n", 'A' + player);
        printf("Enter the row and column of the first dot: ");

        if (scanf("%d %d", &r1, &c1) != 2) {
            printf("Invalid input!\n");
            return 1;
        }

        printf("Enter the row and column of the second dot: ");

        if (scanf("%d %d", &r2, &c2) != 2) {
            printf("Invalid input!\n");
            return 1;
        }

        result = make_move(&board, r1, c1, r2, c2, player);

        if (result < 0) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        if (result == 0)
            player = 1 - player;
    }

    board_print(&board);

    printf("\nFinal scores:\n");
    printf("Player A: %d\n", board.score[0]);
    printf("Player B: %d\n", board.score[1]);

    if (board.score[0] > board.score[1])
        printf("Player A wins!\n");
    else if (board.score[1] > board.score[0])
        printf("Player B wins!\n");
    else
        printf("It's a tie!\n");

    return 0;
}


    return 0;
}
