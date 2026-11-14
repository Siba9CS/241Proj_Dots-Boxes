#include <stdio.h>
#include "game.h"

int main(void) {
    Game game;
    char direction;
    int row, col;
    int result;

    initializeGame(&game);

    printf("Welcome to Dots and Boxes!\n");
    printf("Board size: 3 x 3 boxes\n");
    printf("Enter H for horizontal or V for vertical.\n");

    while (!isGameOver(&game)) {
        displayBoard(&game);

        printf("\nPlayer %d's turn\n", game.currentPlayer);
        printf("Enter direction, row and column: ");

        if (scanf(" %c %d %d", &direction, &row, &col) != 3) {
            printf("Invalid input!\n");
            return 1;
        }

        result = makeMove(&game, direction, row, col);

        if (result == -1) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        if (result > 0)
            printf("You completed %d box(es)! Play again.\n", result);
    }

    displayBoard(&game);
    displayWinner(&game);

    return 0;
}
