#include <ncurses.h>
#include "../include/Scoreboard.h"
#include <string>
#include <fstream>
#include <sstream>
#include <map>

void Scoreboard::display(int lives, std::string player_name) {
    mvprintw(0, 0, "Scoreboard:");
    mvprintw(1, 0, "Player: %s", player_name.c_str());
    mvprintw(2, 0, "Score: %d", score);
    mvprintw(3, 0, "Lives: %d", lives);

    display_highest_score();
}

void Scoreboard::inc_score(int num_bricks) {
    score += num_bricks;
}

void Scoreboard::store_score(std::string player_name) {
    std::ifstream infile("../data/highestScore.txt");
    std::map<std::string, int> scores;
    std::string line;

    // Read existing scores
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string name;
        int stored_score;
        if (iss >> name >> stored_score) {
            scores[name] = stored_score;
        }
    }
    infile.close();

    // Compare and update the score if the current score is higher
    if (scores.find(player_name) == scores.end() || score > scores[player_name]) {
        scores[player_name] = score;
    }

    // Write updated scores back to the file
    std::ofstream outfile("../data/highestScore.txt");
    if (!outfile) {
        mvprintw(4, 0, "Error opening file!");
    } else {
        for (const auto& entry : scores) {
            outfile << entry.first << " " << entry.second << std::endl;
        }
        outfile.close();
    }
}

void Scoreboard::display_highest_score() {
    std::ifstream infile("../data/highestScore.txt");
    std::string line;
    std::string highest_score_player;
    int highest_score = 0;

    // Read existing scores and find the highest score
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string name;
        int stored_score;
        if (iss >> name >> stored_score) {
            if (stored_score > highest_score) {
                highest_score = stored_score;
                highest_score_player = name;
            }
        }
    }
    infile.close();

    mvprintw(4, 0, "Highest Score: %s-%d", highest_score_player.c_str(), highest_score);
}
