#include <ncurses.h>
#include <unistd.h>
#include <cstdlib> 
#include <ctime>   

struct Ball {
    int x, y;         
    int dirX, dirY;  
};

void initializeBall(Ball &ball) {
    ball.x = 20;          
    ball.y = 1;           
    ball.dirX = 1;       
    ball.dirY = 1;        
}

void moveBall(Ball &ball, int barX, int barLength) {
   
    ball.x += ball.dirX;
    ball.y += ball.dirY;

    
    if (ball.x <= 0 || ball.x >= COLS - 1) {
        ball.dirX *= -1; 
    }

   
    if (ball.y <= 0) {
        ball.dirY *= -1; 
    }

    
    if (ball.y == LINES - 1 && ball.x >= barX && ball.x < barX + barLength) {
        ball.dirY *= -1; 

        
        int randomAngle = rand() % 3; 
        if (randomAngle == 0) {
            ball.dirX = -1; 
        } else if (randomAngle == 1) {
            ball.dirX = 0;
        } else {
            ball.dirX = 1; 
        }

        ball.y--;
    }

    if (ball.y >= LINES - 1) {
        ball.dirY = 0; 
    }
}

void drawBar(int barX, int barLength) {
    for (int i = 0; i < barLength; ++i) {
        mvaddch(LINES - 1, barX + i, '#'); 
    }
}

// Game function
void runGame() {
    srand(static_cast<unsigned int>(time(0))); 

    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
    nodelay(stdscr, TRUE);
    timeout(30); 

    int barX = 10;     
    int barLength = 10; 
    Ball ball;
    initializeBall(ball);

    while (true) {
        clear(); 

        
        drawBar(barX, barLength);

       
        moveBall(ball, barX, barLength);
        mvaddch(ball.y, ball.x, 'O');

        refresh(); 

        int ch = getch(); 
        if (ch == KEY_LEFT) {
            if (barX > 0) barX -= 5;
        } else if (ch == KEY_RIGHT) {
            if (barX + barLength < COLS) barX += 5; 
        } else if (ch == 'q') {
            break;
        }

        usleep(10000); 
    }

    endwin(); // End ncurses mode
}
