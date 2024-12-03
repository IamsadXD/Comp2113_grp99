#include "BrickGenerator.h"
#include <cstdlib>
#include <ncurses.h>

// Constructor to initialize the brick generator
BrickGenerator::BrickGenerator(int rows, int cols, int startX, int startY, int spacingX, int spacingY)
    : rows(rows), cols(cols), startX(startX), startY(startY), spacingX(spacingX), spacingY(spacingY) {}

// Generate the bricks, with a 70% chance to create a normal brick and a 30% chance for a special brick
void BrickGenerator::generateBricks() {
    bricks.clear();
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            bool isSpecialBrick = rand() % 10 < 3; // 30% chance for special bricks
            bool isActive = rand() % 2 == 0;       // 50% chance for each brick to be active
            bricks.push_back({startX + col * spacingX, startY + row * spacingY, isActive, isSpecialBrick});
        }
    }
}

// Draw the bricks on the screen
void BrickGenerator::drawBricks() const {
    for (const auto& brick : bricks) {
        if (brick.active) {
            if (brick.isSpecialBrick) {
                // Draw special bricks ('+' for power-ups and '-' for power-downs)
                mvaddch(brick.y, brick.x, brick.isSpecialBrick ? (rand() % 2 == 0 ? '+' : '-') : '#');
            } else {
                // Draw normal bricks
                mvaddch(brick.y, brick.x, '#');
            }
        }
    }
}
