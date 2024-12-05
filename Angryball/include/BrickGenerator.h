#ifndef BRICKGENERATOR_H
#define BRICKGENERATOR_H
#include <vector>

struct Brick {
    int x, y;         
    bool active;        
    bool isSpecialBrick; // Special Brick: + or -)
    char specialType; // '+' for power-up, '-' for power-down, '\0' for normal brick
};

class BrickGenerator {
public:
    int rows, cols;
    int startX, startY, spacingX, spacingY;
    std::vector<Brick> bricks;
    BrickGenerator(int rows, int cols, int startX, int startY, int spacingX, int spacingY);
    void generateBricks();
    void drawBricks() const;
    bool areAllBricksDestroyed() const;
};

#endif // BRICKGENERATOR_H
