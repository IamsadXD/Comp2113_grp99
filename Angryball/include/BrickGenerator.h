#ifndef BRICKGENERATOR_H
#define BRICKGENERATOR_H

#include <vector>

// Brick structure with added isSpecialBrick flag
struct Brick {
    int x, y;              // Position of the brick
    bool active;           // Whether the brick is active or destroyed
    bool isSpecialBrick;   // Whether the brick is special (e.g., + or -)
};

// Brick generator class declaration
class BrickGenerator {
public:
    int rows, cols;
    int startX, startY, spacingX, spacingY;
    std::vector<Brick> bricks;

    BrickGenerator(int rows, int cols, int startX, int startY, int spacingX, int spacingY);

    // Generate the bricks
    void generateBricks();

    // Draw the bricks on the screen
    void drawBricks() const;
};

#endif // BRICKGENERATOR_H
