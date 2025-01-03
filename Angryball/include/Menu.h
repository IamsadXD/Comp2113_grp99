#ifndef MENU_H
#define MENU_H
#include <string>  
#include <ncurses.h> // access to ncurses lib which allows programmers to create textual user interfaces

using namespace std;
class Menu {
private:
    WINDOW * menuwin;  
     // height and width of menu are defined here 

    string title[5] = { // ASCII Art of title name to be displayed in menu 
        " _______                          __           __ __ ", 
        "|   _   |.-----.-----.----.--.--.|  |--.---.-.|  |  |",
        "|       ||     |  _  |   _|  |  ||  _  |  _  ||  |  |",
        "|___|___||__|__|___  |__| |___  ||_____|___._||__|__|",
        "              |_____|    |_____|                     ",       
    };

public:
    Menu(); 
    ~Menu(); 
    int display_options();  
    string input_name();
    void game_info(int y_max, int x_max); 
    void play_instructions(int y_max, int x_max); 
    void custom_draw(WINDOW* win); 
};

#endif
