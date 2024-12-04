#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <iostream>

class Scoreboard {
public:
    void display();
    void addScore(int num_bricks);
private:
    int score = 0;
};

#endif  
