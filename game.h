#ifndef GAME_H
#define GAME_H

#include "board.h"

typedef struct {
    Board board;
    int currentPlayer;   /* 0 = A, 1 = B */
} Game;

void game_init(Game *g);
int  game_move(Game *g, int r1, int c1, int r2, int c2);
int  game_is_over(const Game *g);
void game_print_scores(const Game *g);
void game_print_winner(const Game *g);
void game_run(Game *g);

#endif
