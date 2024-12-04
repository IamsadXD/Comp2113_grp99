#include "scoreboard.h"
using namespace std;

void Scoreboard::display() {
    cout << "Scoreboard:\n";
    cout << "Score: " << score << "\n";
}

void Scoreboard::inc_score(int num_bricks) {
    score += num_bricks;
}
