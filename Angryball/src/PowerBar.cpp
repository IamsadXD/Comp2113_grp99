#include "PowerBar.h"
#include <ncurses.h>

// Draw the power bar on the screen
void PowerBarRenderer::draw() const {
    // Draw the minimum point of the power bar with '[' at a fixed position
    mvaddch(bar.y, bar.x, '[');

    // Draw the power bar itself with '=' between the fixed positions
    for (int i = 1; i <= bar.length; ++i) { // Start drawing after the minimum point
        mvaddch(bar.y, bar.x + i, '=');
    }

    // Draw the maximum point of the power bar with ']' at a fixed position
    mvaddch(bar.y, bar.x + bar.maxLength, ']');
}

// Update the power bar's length based on the input (delta)
void PowerBarRenderer::update(int delta) {
    bar.length += delta;

    if (bar.length > bar.maxLength) {
        bar.length = bar.maxLength; // Cap the bar at the maximum length
    }
    if (bar.length < 1) {
        bar.length = 0; // Minimum bar length set to 0
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
