#include "PowerBar.h"

// Constructor for initializing the power bar
PowerBar::PowerBar(int length, int maxLength, int x, int y)
    : length(length), maxLength(maxLength), x(x), y(y) {}

// Update the power bar's length
void PowerBar::update(int delta) {
    length += delta;

    if (length > maxLength) {
        length = maxLength; // Cap the length at the maximum
    }
    if (length < 0) {
        length = 0; // Minimum length is 0
    }
}

// Check if the power bar is full
bool PowerBar::isFull() const {
    return length == maxLength;
}

// Reset the power bar to 0
void PowerBar::reset() {
    length = 0;
}
