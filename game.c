
#include <stdio.h>
#include "game.h"

void initializeGame(Game *game) {
    int i, j;

    for (i = 0; i <= ROWS; i++)
        for (j = 0; j < COLS; j++)
            game->horizontal[i][j] = 0;

    for (i = 0; i < ROWS; i++)
        for (j = 0; j <= COLS; j++)
            game->vertical[i][j] = 0;

    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++)
            game->boxes[i][j] = 0;

    game->scores[0] = 0;
    game->scores[1] = 0;
    game->currentPlayer = 1;
    game->moves = 0;
}

void displayBoard(const Game *game) {
    int i, j;

    printf("\n");

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf(".");
            printf("%s", game->horizontal[i][j] ? "---" : "   ");
        }
        printf(".\n");

        for (j = 0; j < COLS; j++) {
            printf("%c   ", game->vertical[i][j] ? '|' : ' ');
        }
        printf("%c\n", game->vertical[i][COLS] ? '|' : ' ');
    }

    for (j = 0; j < COLS; j++)
        printf(".%s", game->horizontal[ROWS][j] ? "---" : "   ");

    printf(".\n\n");
    printf("Player 1: %d | Player 2: %d\n",
           game->scores[0], game->scores[1]);
}

int checkBox(Game *game, int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS)
        return 0;

    if (game->boxes[row][col] != 0)
        return 0;

    if (game->horizontal[row][col] &&
        game->horizontal[row + 1][col] &&
        game->vertical[row][col] &&
        game->vertical[row][col + 1]) {

        game->boxes[row][col] = game->currentPlayer;
        game->scores[game->currentPlayer - 1]++;
        return 1;
    }

    return 0;
}

int makeMove(Game *game, char direction, int row, int col) {
    int completed = 0;

    if (direction == 'H' || direction == 'h') {
        if (row < 0 || row > ROWS || col < 0 || col >= COLS)
            return -1;

        if (game->horizontal[row][col])
            return -1;

        game->horizontal[row][col] = 1;

    } else if (direction == 'V' || direction == 'v') {
        if (row < 0 || row >= ROWS || col < 0 || col > COLS)
            return -1;

        if (game->vertical[row][col])
            return -1;

        game->vertical[row][col] = 1;

    } else {
        return -1;
    }

    game->moves++;

    if (direction == 'H' || direction == 'h') {
        if (row > 0)
            completed += checkBox(game, row - 1, col);
        if (row < ROWS)
            completed += checkBox(game, row, col);
    } else {
        if (col > 0)
            completed += checkBox(game, row, col - 1);
        if (col < COLS)
            completed += checkBox(game, row, col);
    }

    if (completed == 0)
        game->currentPlayer = 3 - game->currentPlayer;

    return completed;
}

int isGameOver(const Game *game) {
    return game->moves == ROWS * (COLS + 1) + COLS * (ROWS + 1);
}

void displayWinner(const Game *game) {
    printf("\nFinal score:\n");
    printf("Player 1: %d\n", game->scores[0]);
    printf("Player 2: %d\n", game->scores[1]);

    if (game->scores[0] > game->scores[1])
        printf("Player 1 wins!\n");
    else if (game->scores[1] > game->scores[0])
        printf("Player 2 wins!\n");
    else
        printf("It's a tie!\n");
}

