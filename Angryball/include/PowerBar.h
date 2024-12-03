#ifndef POWERBAR_H
#define POWERBAR_H

// Power Bar structure with a constructor
struct PowerBar {
    int length;    // Length of the power bar
    int maxLength; // Maximum length of the bar
    int x, y;      // Position of the bar

    // Constructor for initializing the power bar
    PowerBar(int length, int maxLength, int x, int y);
};

#endif
