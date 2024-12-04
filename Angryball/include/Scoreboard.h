#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <iostream>

class Scoreboard {
public:
    void display();
    void inc_score(int num_bricks);
private:
    int score = 0;
};

#endif  
