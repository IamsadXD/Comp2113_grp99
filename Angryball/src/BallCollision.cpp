#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include "../include/BallCollision.h"
#include "../include/BrickGenerator.h"

void initializeBall(Ball &ball, int barX, int barLength) {
    ball.x = barX + barLength / 2; // Place the ball in the middle of the bar
    ball.y = LINES - 2;            // Place the ball just above the bar
    ball.dirX = 0;                 // Initially, the ball is not moving
    ball.dirY = 0;                 // Initially, the ball is not moving
}

void moveBall(Ball &ball, int barX, int barLength, BrickGenerator &brickGen, bool& outofbounds, int& brickType) {
    ball.x += ball.dirX;
    ball.y += ball.dirY;

    // Check for wall collisions
    if (ball.x <= 0 || ball.x >= COLS - 1) {
        ball.dirX *= -1; 
    }

    if (ball.y <= 0) {
        ball.dirY *= -1; 
    }

    // Check for collision with the bar
    if (ball.y == LINES - 1 && ball.x >= barX && ball.x < barX + barLength) {
        ball.dirY *= -1; 
        int randomAngle = rand() % 3; 
        ball.dirX = (randomAngle == 0) ? -1 : (randomAngle == 1) ? 0 : 1;
        ball.y--;
    }

    // Check for collision with bricks
    for (auto it = brickGen.bricks.begin(); it != brickGen.bricks.end(); ) {
        if (it->active && ball.y == it->y && ball.x >= it->x && ball.x < it->x + 1) {
            ball.dirY *= -1; // Bounce off the brick
            if (it->isSpecialBrick) {
                if (it->specialType == '+') {
                    brickType = 1;
                } else if (it->specialType == '-') {
                    brickType = 2;
                }
            }
            it->active = false; // Remove the brick
            it = brickGen.bricks.erase(it); // Erase the brick from the vector
        } else {
            ++it; // Move to the next brick
        }
    }

    // Check if the ball falls below the screen
    if (ball.y >= LINES - 1) {
        ball.dirY = 0; 
        ball.dirX = 0; 
        outofbounds = true;
    }
}

void drawBar(int barX, int barLength) {
    for (int i = 0; i < barLength; ++i) {
        mvaddch(LINES - 1, barX + i, '#'); 
    }
}