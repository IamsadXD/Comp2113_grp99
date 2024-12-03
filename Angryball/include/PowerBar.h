#ifndef POWERBAR_H
#define POWERBAR_H

// PowerBar class declaration
class PowerBar {
public:
    int length;    // Length of the power bar
    int maxLength; // Maximum length of the bar
    int x, y;      // Position of the bar

    // Constructor
    PowerBar(int length, int maxLength, int x, int y);

    // Draw the power bar
    void draw() const;

    // Update the power bar's length
    void update(int delta);

    // Check if the power bar is full
    bool isFull() const;

    // Reset the power bar
    void reset();
};

#endif // POWERBAR_H
