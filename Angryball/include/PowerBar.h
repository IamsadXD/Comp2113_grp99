#ifndef POWERBAR_H
#define POWERBAR_H

// Power Bar structure with a constructor
struct PowerBar {
    int length;    // Length of the power bar
    int maxLength; // Maximum length of the bar
    int x, y;      // Position of the bar

    // Constructor for initializing the power bar
    PowerBar(int length, int maxLength, int x, int y)
        : length(length), maxLength(maxLength), x(x), y(y) {}
};

// Power bar renderer class declaration
class PowerBarRenderer {
public:
    PowerBar bar;

    PowerBarRenderer(int length, int maxLength, int x, int y)
        : bar(length, maxLength, x, y) {}

    void draw() const; // Draw the power bar
    void update(int delta); // Update the power bar's length
    bool isFull() const; // Check if the bar is full
    void reset(); // Reset the power bar
};

#endif // POWERBAR_H
