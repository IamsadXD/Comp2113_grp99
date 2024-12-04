#ifndef BRICKGENERATOR_H
#define BRICKGENERATOR_H

#include <vector>

// Brick structure with added isSpecialBrick flag
struct Brick {
    int x, y;           // Position of the brick
    bool active;        // Whether the brick is active or destroyed
    bool isSpecialBrick; // Whether the brick is special (e.g., + or -)
    char specialType; // '+' for power-up, '-' for power-down, '\0' for normal brick
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

    // Check if all bricks are destroyed
    bool areAllBricksDestroyed() const;
};

#endif // BRICKGENERATOR_H
