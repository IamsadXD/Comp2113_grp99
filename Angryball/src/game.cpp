#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include "../include/BallCollision.h"
#include "../include/BrickGenerator.h"
#include "../include/PowerUp.h"
#include "../include/PowerDown.h"
#include "../include/Scoreboard.h"

void game(const std::string& player_name) {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
    nodelay(stdscr, TRUE);
    timeout(30); // Set a timeout for getch()

    // Initialization
    double speed = 20000; // Adjust speed of ball by sleep time
    int barX = 10;      // Initial position of the bar
    int barLength = 30; // Length of the bar
    int lives = 3;     // Number of lives
    int brickType = 0; // Type of brick (0=normal, 1=power-up, 2=power-down)
    bool outofbounds = false;
    bool reset = false;
    bool ballOnBar = true; // Track if the ball is on the bar
    Ball ball;
    initializeBall(ball, barX, barLength);
    BrickGenerator brickGen(10, COLS, 70, 10, 1, 1); 
    brickGen.generateBricks(); // Generate bricks
    PowerUp powerUp(PowerUp::Type::RegenLives);
    PowerDown powerDown(PowerDown::Type::ExtremeSpeeds);
    Scoreboard scoreboard;
    while (true) {
        clear(); // Clear the screen
        // Draw the bar
        brickGen.drawBricks();
        for (int i = 0; i < barLength; ++i) {
            mvaddch(LINES - 1, barX + i, '#'); // Draw the bar at the bottom
        }

        // Move and draw the ball
        if (ballOnBar) {
            ball.x = barX + barLength / 2; // Keep the ball on the bar
            mvaddch(ball.y, ball.x, 'O'); // Draw the ball
        } else {
            moveBall(ball, barX, barLength, brickGen, outofbounds, brickType);
            mvaddch(ball.y, ball.x, 'O'); // Draw the ball
        }

        refresh(); // Refresh the screen to show changes
        if (outofbounds) {
            lives--; // Decrease lives if ball falls below the screen
            outofbounds = false;
            ballOnBar = true; // Reset the ball to be on the bar
            initializeBall(ball, barX, barLength);
        }
        switch(brickType) {
            case 1:
                powerUp.applyPowerUp(lives, barLength, reset);
                brickType = 0;
                if (reset){
                    ballOnBar = true; // Reset the ball to be on the bar
                    initializeBall(ball, barX, barLength);
                    reset = false;
                }
                break;
            case 2:
                powerDown.applyPowerDown(speed, barLength);
                brickType = 0;
                break;
        }

        int ch = getch(); // Get user input
        if (ch == KEY_LEFT) {
            if (barX > 0) barX -= 5; // Move left by 5 steps
        } else if (ch == KEY_RIGHT) {
            if (barX + barLength < COLS) barX += 5; // Move right by 5 steps
        } else if (ch == KEY_UP && ballOnBar) {
            ball.dirX = 0; // Set initial direction to straight up
            ball.dirY = -1;
            ballOnBar = false; // Ball is now in motion
        } else if (ch == 'q') {
            clear();
            return; // Quit on 'q'
        }

        usleep(speed); // Sleep for a short time (default 10ms)
        
        if (lives <= 0) {
            break; // End the game if no lives left
        }
    }

    endwin(); // End ncurses mode
    return;
}