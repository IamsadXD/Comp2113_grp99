#include <ncurses.h>
#include "../include/Scoreboard.h"
#include <string>
#include <fstream>
#include <sstream>
#include <map>

void Scoreboard::display(int lives, std::string player_name, std::string lastEffect) {
    // Draw the top border of the scoreboard
    mvprintw(0, 0, "----------- Scoreboard -----------");

    // Display player information
    mvprintw(1, 0, "Player: %s | Score: %d | Lives: %d", player_name.c_str(), score, lives);

    // Display the last effect
    mvprintw(2, 0, "Last Effect: %s", lastEffect.c_str());
    
    // Display the highest score on the next line
    display_highest_score();

    // Draw the bottom border of the scoreboard
    mvprintw(4, 0, "----------------------------------");
}

void Scoreboard::inc_score(int num_bricks) {
    score += num_bricks;
}

void Scoreboard::store_score(std::string player_name) {
    std::ifstream infile("Angryball/data/highestScore.txt");
    if (!infile) {
        mvprintw(5, 0, "Error opening file for reading!");
        return;
    }

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
    std::ofstream outfile("Angryball/data/highestScore.txt");
    if (!outfile) {
        mvprintw(5, 0, "Error opening file for writing!");
        return;
    }

    for (const auto& entry : scores) {
        outfile << entry.first << " " << entry.second << std::endl;
    }
    outfile.close();
}

void Scoreboard::display_highest_score() {
    std::ifstream infile("Angryball/data/highestScore.txt");

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

    // Display the highest score on the next line
    if (highest_score_player.empty()) {
        mvprintw(3, 0, "Highest Score: NA");
    } else {
        mvprintw(3, 0, "Highest Score: %s - %d", highest_score_player.c_str(), highest_score);
    }
}
