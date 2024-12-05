#include "PowerBar.h"
#include <ncurses.h>

void PowerBarRenderer::draw() const {
    mvaddch(bar.y, bar.x, '['); // Fixed starting bracket

    for (int i = 1; i <= bar.maxLength; ++i) {
        if (i <= bar.length) {
            mvaddch(bar.y, bar.x + i, '=');
        } else {
            mvaddch(bar.y, bar.x + i, ' '); // Empty space inside brackets
        }
    }

    mvaddch(bar.y, bar.x + bar.maxLength + 1, ']'); // Fixed closing bracket
}

// Update the power bar's length
void PowerBarRenderer::update(int delta) {
    bar.length += delta;

    if (bar.length > bar.maxLength) {
        bar.length = 2; 
    }
    if (bar.length < 0) {
        bar.length = 2;
    }
}

void PowerBarRenderer::reset() {
    bar.length = 2;
}
