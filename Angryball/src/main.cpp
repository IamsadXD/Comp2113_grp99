int main() {
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
        for (int i = 0; i < barLength; ++i) {
            mvaddch(LINES - 1, barX + i, '#'); // Draw the bar at the bottom
        }

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
    return 0;
}
