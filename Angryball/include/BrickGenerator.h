#ifndef BRICKGENERATOR_H
#define BRICKGENERATOR_H

#include <vector>

// Brick structure
struct Brick {
    int x, y;    // Position of the brick
    bool active; // Whether the brick is active or destroyed
    bool isSpecial; // Whether the brick is special (e.g., power-up or power-down)
    
    // Constructor to initialize the brick
    Brick(int x, int y, bool active, bool isSpecial);
};

// Brick generator and renderer
class BrickGenerator {
public:
    int rows, cols;
    int startX, startY, spacingX, spacingY;
    std::vector<Brick> bricks;

    BrickGenerator(int rows, int cols, int startX, int startY, int spacingX, int spacingY);
    void generateBricks();
    void drawBricks() const;
};

#endif
