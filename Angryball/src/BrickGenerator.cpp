#include "BrickGenerator.h"
#include <cstdlib>
#include <ctime>

// Brick constructor
Brick::Brick(int x, int y, bool active, bool isSpecial)
    : x(x), y(y), active(active), isSpecial(isSpecial) {}

// BrickGenerator constructor
BrickGenerator::BrickGenerator(int rows, int cols, int startX, int startY, int spacingX, int spacingY)
    : rows(rows), cols(cols), startX(startX), startY(startY), spacingX(spacingX), spacingY(spacingY) {}

// Generate bricks with a 70% chance for regular and 30% chance for special
void BrickGenerator::generateBricks() {
    bricks.clear();
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            bool isSpecialBrick = rand() % 10 < 3;  // 30% chance for special brick
            if (rand() % 10 < 7) {  // 70% chance to create a regular brick
                bricks.push_back(Brick(startX + col * spacingX, startY + row * spacingY, true, isSpecialBrick));
            }
        }
    }
}

// Draw bricks, use special characters for special bricks
void BrickGenerator::drawBricks() const {
    for (const auto& brick : bricks) {
        if (brick.active) {
            if (brick.isSpecial) {
                mvaddch(brick.y, brick.x, brick.isSpecial ? (rand() % 2 == 0 ? '+' : '-') : ' ');
            } else {
                mvaddch(brick.y, brick.x, '#'); // Regular bricks with '#'
            }
        }
    }
}
