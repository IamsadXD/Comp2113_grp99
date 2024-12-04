#include "scoreboard.h"

void Scoreboard::display() {
    std::cout << "Scoreboard:\n";
    std::cout << "Score: " << score << "\n";
}

void Scoreboard::addScore(int num_bricks) {
    score += num_bricks;
}
