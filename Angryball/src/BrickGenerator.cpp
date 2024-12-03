#include "BrickGenerator.h"
#include <ncurses.h>
#include <cstdlib>

BrickGenerator::BrickGenerator(int rows, int cols, int startX, int startY, int spacingX, int spacingY)
    : rows(rows), cols(cols), startX(startX), startY(startY), spacingX(spacingX), spacingY(spacingY) {}

void BrickGenerator::generateBricks() {
    bricks.clear();
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (rand() % 2 == 0) {
                bricks.push_back({startX + col * spacingX, startY + row * spacingY, true});
            }
        }
    }
}

void BrickGenerator::drawBricks() const {
    for (const auto& brick : bricks) {
        if (brick.active) {
            mvaddch(brick.y, brick.x, '#'); // Render active brick with '#'
        }
    }
}
