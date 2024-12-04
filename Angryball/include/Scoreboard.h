#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <string>

class Scoreboard {
public:
    Scoreboard() : score(0) {}

    void display(int lives, std::string player_name);
    void inc_score(int num_bricks);
    void store_score(std::string player_name);
    void display_highest_score();
    int getScore() const; // Add this line

private:
    int score;
};

#endif