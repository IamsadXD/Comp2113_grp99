#include "../include/BrickGenerator.h"
#include <cstdlib>
#include <ncurses.h>
#include <vector>

// Constructor to initialize the brick generator
BrickGenerator::BrickGenerator(int rows, int cols, int startX, int startY, int spacingX, int spacingY)
    : rows(rows), cols(cols), startX(startX), startY(startY), spacingX(spacingX), spacingY(spacingY) {}

void BrickGenerator::generateBricks() {
    bricks.clear();
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            bool isSpecialBrick = false;
            char specialType = '\0';

            // 70% chance for a normal brick
            if (rand() % 10 < 7) {
                // Inside the normal brick, 10% chance for it to be special (either + or -)
                if (rand() % 10 < 10) {
                    isSpecialBrick = true;
                    specialType = (rand() % 2 == 0) ? '+' : '-'; // Randomly assign + or -
                }
            }

            // Add the brick with active set to true (always active initially)
            bricks.push_back({startX + col * spacingX, startY + row * spacingY, true, isSpecialBrick, specialType});
        }
    }
}

// Draw the bricks on the screen
void BrickGenerator::drawBricks() const {
    for (const auto& brick : bricks) {
        if (brick.active) {
            if (brick.isSpecialBrick) {
                // Draw special bricks ('+' for power-ups and '-' for power-downs)
                mvaddch(brick.y, brick.x, brick.specialType);
            } else {
                // Draw normal bricks
                mvaddch(brick.y, brick.x, '#');
            }
        }
    }
}

// Check if all bricks are destroyed (inactive)
bool BrickGenerator::areAllBricksDestroyed() const {
    for (const auto& brick : bricks) {
        if (brick.active) {
            return false; // If any brick is active, return false
        }
    }
    return true; // If all bricks are inactive, return true
}
