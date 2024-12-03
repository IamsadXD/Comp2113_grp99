#ifndef BRICKGENERATOR_H
#define BRICKGENERATOR_H

#include <vector>

// Structure for Brick
struct Brick {
    int x, y;    // Position of the brick
    bool active; // Whether the brick is active or destroyed
    char type;   // Brick type: '#' for normal, '+' for power-up, '-' for power-down
};

// Class for Brick Generator
class BrickGenerator {
public:
    int rows, cols; // Number of rows and columns of bricks
    int startX, startY; // Starting position of the brick grid
    int spacingX, spacingY; // Spacing between bricks
    std::vector<Brick> bricks; // Vector of bricks

    BrickGenerator(int rows, int cols, int startX, int startY, int spacingX, int spacingY);
    void generateBricks(); // Generate the bricks with normal and special types
    void drawBricks() const; // Render bricks on the screen
};

#endif // BRICKGENERATOR_H
