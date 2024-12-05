#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <iostream>
#include <string>

class Scoreboard {
public:
    void display(int lives, std::string player_name);
    void inc_score(int num_bricks);
    void store_score(std::string player_name);
private:
    int score = 0;
    void display_highest_score();
};

#endif  
