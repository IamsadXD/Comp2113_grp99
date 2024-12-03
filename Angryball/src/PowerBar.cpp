#include "PowerBar.h"
#include <ncurses.h>

// Constructor for initializing the power bar
PowerBar::PowerBar(int length, int maxLength, int x, int y)
    : length(length), maxLength(maxLength), x(x), y(y) {}

// Draw the power bar on the screen
void PowerBar::draw() const {
    // Draw the minimum point of the power bar with '[' at a fixed position
    mvaddch(y, x, '[');

    // Draw the power bar itself with '=' between the fixed positions
    for (int i = 1; i <= length; ++i) { // Start drawing after the minimum point
        mvaddch(y, x + i, '=');
    }

    // Draw the maximum point of the power bar with ']' at a fixed position
    mvaddch(y, x + maxLength, ']');
}

// Update the length of the power bar by a delta value (positive or negative)
void PowerBar::update(int delta) {
    length += delta;

    if (length > maxLength) {
        length = maxLength; // Cap the bar at the maximum length
    }
    if (length < 1) {
        length = 0; // Minimum bar length set to 0
    }
}

// Check if the power bar is full (at its maximum length)
bool PowerBar::isFull() const {
    return length == maxLength; // Return true if the bar is full
}

// Reset the power bar to a length of 0
void PowerBar::reset() {
    length = 0; // Reset the bar to 0 when used
}
