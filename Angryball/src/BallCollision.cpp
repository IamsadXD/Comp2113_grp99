#include <ncurses.h>
#include <unistd.h>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

// Ball structure
struct Ball {
    int x, y;          // Position of the ball
    int dirX, dirY;   // Direction of the ball
};

void initializeBall(Ball &ball) {
    ball.x = 20;          // Initial horizontal position
    ball.y = 1;           // Initial vertical position at the top (1)
    ball.dirX = 1;        // Initial horizontal direction (1 = right)
    ball.dirY = 1;        // Initial vertical direction (1 = down)
}

void moveBall(Ball &ball, int barX, int barLength) {
    // Update the ball's position
    ball.x += ball.dirX;
    ball.y += ball.dirY;

    // Bounce off left and right walls
    if (ball.x <= 0 || ball.x >= COLS - 1) {
        ball.dirX *= -1; // Reverse horizontal direction
    }

    // Bounce off top wall
    if (ball.y <= 0) {
        ball.dirY *= -1; // Reverse vertical direction
    }

    // Bounce off the paddle (bar)
    if (ball.y == LINES - 1 && ball.x >= barX && ball.x < barX + barLength) {
        ball.dirY *= -1; // Reverse vertical direction

        // Randomly change horizontal direction
        int randomAngle = rand() % 3; // Generate a random number (0, 1, or 2)
        if (randomAngle == 0) {
            ball.dirX = -1; // Move left
        } else if (randomAngle == 1) {
            ball.dirX = 0; // Move straight
        } else {
            ball.dirX = 1; // Move right
        }

        ball.y--; // Move the ball back above the bar to avoid "sticking"
    }

    // Check if the ball hits the bottom wall (game over condition)
    if (ball.y >= LINES - 1) {
        ball.dirY = 0; // Stop the ball
    }
}

// Function to draw the bar
void drawBar(int barX, int barLength) {
    for (int i = 0; i < barLength; ++i) {
        mvaddch(LINES - 1, barX + i, '#'); // Draw the bar at the bottom
    }
}

// Game function
void runGame() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
    nodelay(stdscr, TRUE);
    timeout(30); // Set a timeout for getch()

    int barX = 10;      // Initial position of the bar
    int barLength = 10; // Length of the bar
    Ball ball;
    initializeBall(ball);

    while (true) {
        clear(); // Clear the screen

        // Draw the bar
        drawBar(barX, barLength);

        // Move and draw the ball
        moveBall(ball, barX, barLength);
        mvaddch(ball.y, ball.x, 'O'); // Draw the ball

        refresh(); // Refresh the screen to show changes

        int ch = getch(); // Get user input
        if (ch == KEY_LEFT) {
            if (barX > 0) barX -= 5; // Move left by 5 steps
        } else if (ch == KEY_RIGHT) {
            if (barX + barLength < COLS) barX += 5; // Move right by 5 steps
        } else if (ch == 'q') {
            break; // Quit on 'q'
        }

        usleep(10000); // Sleep for a short time (10ms)
    }

    endwin(); // End ncurses mode
}
