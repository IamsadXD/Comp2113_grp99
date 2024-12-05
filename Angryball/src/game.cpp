#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include "../include/BallCollision.h"
#include "../include/BrickGenerator.h"
#include "../include/PowerUp.h"
#include "../include/PowerDown.h"
#include "../include/Scoreboard.h"
#include "../include/Menu.h" // Include Menu for title screen

void displayGameOver() {
    clear();
    mvprintw(LINES / 2, (COLS - 10) / 2, "Game Over"); // Center the message
    refresh();
    usleep(2000000); // Sleep for 2 seconds
}

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
    int barX = 10;      
    int barLength = 15; 
    int lives = 3;     
    int brickType = 0; 
    string lastEffect = "None";
    bool outofbounds = false;
    bool reset = false;
    bool ballOnBar = true; // Track if the ball is on the bar
    Ball ball;
    initializeBall(ball, barX, barLength);
    //int rows, int cols, int startX, int startY, int spacingX, int spacingY
    BrickGenerator brickGen(5, COLS, 0, 8, 1, 1); 
    brickGen.generateBricks(); // Generate bricks
    PowerUp powerUp(PowerUp::Type::RegenLives);
    PowerDown powerDown(PowerDown::Type::ExtremeSpeeds);
    Scoreboard scoreboard;

    while (true) {
        clear(); 
        // Draw the bar
        for (int i = 0; i < COLS; ++i) {
            mvaddch(5, i, '=');
        } // Draw '=' at row 5 (change this if your scoreboard is higher)
        brickGen.drawBricks();
        for (int i = 0; i < barLength; ++i) {
            mvaddch(LINES - 1, barX + i, '#'); 
        }

        // Move and draw the ball
        if (ballOnBar) {
            ball.x = barX + barLength / 2; 
            mvaddch(ball.y, ball.x, 'O'); 
        } else {
            moveBall(ball, barX, barLength, brickGen, outofbounds, brickType, scoreboard);
            mvaddch(ball.y, ball.x, 'O'); 
        }

        scoreboard.display(lives, player_name, lastEffect); 

        refresh(); 

        if (outofbounds) {
            lives--; // Decrease lives if ball falls below the screen
            outofbounds = false;
            refresh();
            ballOnBar = true; // Reset the ball to be on the bar
            initializeBall(ball, barX, barLength);
        }

        // Checking for powerups and powerdowns
         switch(brickType) {
            case 1:
                powerUp.applyPowerUp(lives, barLength, reset);
                brickType = 0;
                if (reset){
                    ballOnBar = true; 
                    initializeBall(ball, barX, barLength);
                    reset = false;
                    lastEffect = powerUp.getPowerUp();
                    scoreboard.display(lives, player_name, lastEffect);
                }
                break;
            case 2:
                powerDown.applyPowerDown(speed, barLength);
                brickType = 0;
                lastEffect = powerDown.getPowerDown();
                scoreboard.display(lives, player_name, lastEffect);
                break;
            default:
                break;
        }

        // Check game over condition
        if (lives <= 0) {
            scoreboard.store_score(player_name);
            displayGameOver(); // Show Game Over message
            break; 
        }

        // Handle user input
        int ch = getch(); // Get user input
        if (ch == KEY_LEFT) {
            if (barX > 0) barX -= 5; // Move left by 5 steps
        } else if (ch == KEY_RIGHT) {
            if (barX + barLength < COLS) barX += 5; // Move right by 5 steps
        } else if (ch == KEY_UP && ballOnBar) {
            ball.dirX = 0; 
            ball.dirY = -1;
            ballOnBar = false; // Ball is now in motion
        } else if (ch == 'q') {
            scoreboard.store_score(player_name);
            clear();
            endwin(); // End ncurses mode before returning
            return; 
        }

        usleep(speed); // Sleep for a short time (default 10ms)
    }

    endwin(); // End ncurses mode
    return;
}
