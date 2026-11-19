#include <stdio.h>
#include "game.h"

void game_init(Game *g)
{
    board_init(&g->board);
    g->currentPlayer = 0;
}

int game_move(Game *g, int r1, int c1, int r2, int c2)
{
    int result = make_move(&g->board, r1, c1, r2, c2, g->currentPlayer);

    if (result == 0)
        g->currentPlayer = 1 - g->currentPlayer;

    return result;
}

int game_is_over(const Game *g)
{
    return board_is_full(&g->board);
}

void game_print_scores(const Game *g)
{
    printf("***************************************************************************\n");
    printf("Player A score: %d\n", g->board.score[0]);
    printf("Player B score: %d\n", g->board.score[1]);
    printf("***************************************************************************\n");
}

void game_print_winner(const Game *g)
{
    printf("\nFinal scores:\n");
    printf("Player A: %d\n", g->board.score[0]);
    printf("Player B: %d\n", g->board.score[1]);

    if (g->board.score[0] > g->board.score[1])
        printf("Player A wins!\n");
    else if (g->board.score[1] > g->board.score[0])
        printf("Player B wins!\n");
    else
        printf("It's a tie!\n");
}

void game_run(Game *g)
{
    int r1, c1, r2, c2, result;

    while (!game_is_over(g)) {
        board_print(&g->board);

        printf("Player %c's turn. Enter the row and column of the first dot (e.g., A0 -> 0 0) and second dot: \n",
               'A' + g->currentPlayer);

        if (scanf("%d %d %d %d", &r1, &c1, &r2, &c2) != 4) {
            printf("Invalid input!\n");
            return;
        }

        result = game_move(g, r1, c1, r2, c2);

        if (result < 0) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        if (result > 0)
            game_print_scores(g);
    }

    board_print(&g->board);
    game_print_winner(g);
}
