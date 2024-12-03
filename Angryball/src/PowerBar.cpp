#include "PowerBar.h"

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

// Update the length of the power bar by delta (positive or negative)
void PowerBar::update(int delta) {
    length += delta;

    // Cap the bar at the maximum length
    if (length > maxLength) {
        length = maxLength;
    }
    // Minimum bar length is 0
    if (length < 1) {
        length = 0;
    }
}

bool PowerBar::isFull() const {
    return length == maxLength;
}

void PowerBar::reset() {
    length = 0;
}
