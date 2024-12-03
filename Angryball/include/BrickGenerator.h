#ifndef BRICKGENERATOR_H
#define BRICKGENERATOR_H

#include <vector>

// Brick structure
struct Brick {
    int x, y;    // Position of the brick
    bool active; // Whether the brick is active or destroyed
};


class BrickGenerator {
public:
    int rows, cols;
    int startX, startY, spacingX, spacingY;
    std::vector<Brick> bricks;

    BrickGenerator(int rows, int cols, int startX, int startY, int spacingX, int spacingY);
    void generateBricks();
    void drawBricks() const;
};

#endif // BRICKGENERATOR_H
