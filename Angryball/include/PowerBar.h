#ifndef POWERBAR_H
#define POWERBAR_H

struct PowerBar {
    int length;    
    int maxLength; 
    int x, y;      
    PowerBar(int length, int maxLength, int x, int y)
        : length(length), maxLength(maxLength), x(x), y(y) {}
};

class PowerBarRenderer {
public:
    PowerBar bar;
    PowerBarRenderer(int length, int maxLength, int x, int y)
        : bar(length, maxLength, x, y) {}

    void draw() const; 
    void update(int delta); // Update the power bar's length
    void reset(); // Reset the power bar
};
#endif // POWERBAR_H
