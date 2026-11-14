#ifndef GAME_H
#define GAME_H

#define SIZE 3

typedef struct {
    int horizontal[SIZE + 1][SIZE];
    int vertical[SIZE][SIZE + 1];
    int boxes[SIZE][SIZE];
    int scores[2];
    int currentPlayer;
    int moves;
} Game;

void initializeGame(Game *game);
void displayBoard(const Game *game);
int makeMove(Game *game, char direction, int row, int col);
int checkBox(Game *game, int row, int col);
int isGameOver(const Game *game);
void displayWinner(const Game *game);

#endif
