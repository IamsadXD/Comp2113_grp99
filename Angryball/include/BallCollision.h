#ifndef BALL_GAME_H
#define BALL_GAME_H

#include <ncurses.h>
#include "BrickGenerator.h"

struct Ball {
    int x, y;         
    int dirX, dirY;   
};

void initializeBall(Ball &ball);
void moveBall(Ball &ball, int barX, int barLength, BrickGenerator &brickGen); // Updated function signature
void drawBar(int barX, int barLength);

#endif