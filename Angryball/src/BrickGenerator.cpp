#include "BrickGenerator.h"
#include <ncurses.h>
#include <cstdlib>

// Constructor for initializing the brick generator
BrickGenerator::BrickGenerator(int rows, int cols, int startX, int startY, int spacingX, int spacingY)
    : rows(rows), cols(cols), startX(startX), startY(startY), spacingX(spacingX), spacingY(spacingY) {}

// Generate bricks with a 70% chance for normal bricks and 30% for special bricks
void BrickGenerator::generateBricks() {
    bricks.clear();
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            int brickChance = rand() % 10; // Generate a random number between 0 and 9

            if (brickChance < 7) {
                // 70% chance for normal brick
                bricks.push_back({startX + col * spacingX, startY + row * spacingY, true, '#'});
            } else {
                // 30% chance for special brick
                char brickType = (rand() % 2 == 0) ? '+' : '-'; // Equal chance for '+' or '-'
                bricks.push_back({startX + col * spacingX, startY + row * spacingY, true, brickType});
            }
        }
    }
}

// Render bricks on the screen
void BrickGenerator::drawBricks() const {
    for (const auto& brick : bricks) {
        if (brick.active) {
            mvaddch(brick.y, brick.x, brick.type); // Render the brick based on its type
        }
    }
}
