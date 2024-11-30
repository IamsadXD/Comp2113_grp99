#ifndef POWERBAR_H
#define POWERBAR_H

#include <ncurses.h>

class PowerBar {
public:
    int length;    // Length of the power bar
    int maxLength; // Maximum length of the bar
    int x, y;      // Position of the bar

    PowerBar(int length, int maxLength, int x, int y);

    void draw() const;

    void update(int delta);

    bool isFull() const;

    void reset();
};

#endif // POWERBAR_H
