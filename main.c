#include <stdio.h>
#include "game.h"

int main(void)
{
    Game game;

    game_init(&game);
    printf("Welcome to Dots and Boxes!\n");
    game_run(&game);

    return 0;
}
