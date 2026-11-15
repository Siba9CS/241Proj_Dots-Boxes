
#ifndef GAME_H
#define GAME_H

#define ROWS 4
#define COLS 5

typedef struct {
    int horizontal[ROWS + 1][COLS];
    int vertical[ROWS][COLS + 1];
    int boxes[ROWS][COLS];
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

