#include "PowerBar.h"
#include <ncurses.h>

// Draw the power bar on the screen
void PowerBarRenderer::draw() const {
    // Draw the minimum point of the power bar with '[' at a fixed position
    mvaddch(bar.y, bar.x, '[');

    // Draw the power bar itself with '=' between the fixed positions
    for (int i = 0; i < bar.length; ++i) { // Start drawing after the minimum point
        mvaddch(bar.y, bar.x + i + 1, '=');
    }

    // Draw the maximum point of the power bar with ']' at a fixed position
    mvaddch(bar.y, bar.x + bar.maxLength + 1, ']');
}

// Update the power bar's length based on the input (delta)
void PowerBarRenderer::update(int delta) {
    bar.length += delta;

    // If the bar exceeds the max length, reset it to 2
    if (bar.length > bar.maxLength) {
        bar.length = 2;
    }

    // Ensure the bar length doesn't go below 0
    if (bar.length < 0) {
        bar.length = 0;
    }
}

// Check if the power bar is full
bool PowerBarRenderer::isFull() const {
    return bar.length == bar.maxLength; // Check if the bar is full
}

// Reset the power bar to 0
void PowerBarRenderer::reset() {
    bar.length = 0; // Reset the bar to 0 when used
}
