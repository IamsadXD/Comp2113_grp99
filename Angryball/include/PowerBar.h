#ifndef POWERBAR_H
#define POWERBAR_H

// Structure for PowerBar
struct PowerBar {
    int length;    // Current length of the power bar
    int maxLength; // Maximum length of the power bar
    int x, y;      // Position of the power bar

    // Constructor for initializing the power bar
    PowerBar(int length, int maxLength, int x, int y);
    void update(int delta);  // Update the power bar's length
    bool isFull() const;     // Check if the power bar is full
    void reset();            // Reset the power bar to 0
};

#endif // POWERBAR_H
