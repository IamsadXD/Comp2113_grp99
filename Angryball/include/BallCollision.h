#ifndef BALL_GAME_H
#define BALL_GAME_H
#include <ncurses.h>
#include "BrickGenerator.h"
#include "Scoreboard.h"
struct Ball {
    int x, y;         
    int dirX, dirY;   
};
void initializeBall(Ball &ball, int barX, int barLength); // Updated function signature
void moveBall(Ball &ball, int barX, int barLength, BrickGenerator &brickGen, bool &outofbounds, int& brickType, Scoreboard &scoreboard);
void drawBar(int barX, int barLength);
#endif