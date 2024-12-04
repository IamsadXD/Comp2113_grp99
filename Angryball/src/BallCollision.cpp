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



    endwin(); // End ncurses mode
}
