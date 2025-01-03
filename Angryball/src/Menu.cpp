#include <ncurses.h>
#include <iostream>
#include <string>
#include "../include/Menu.h"
#include "../include/game.h"
using namespace std; 

//initialize the menu
Menu::Menu() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE); //enable reading of function keys and arrow keys  
}

Menu::~Menu() {
    endwin();  // Clean up ncurses and reset terminal
}

void draw_custom_border(WINDOW* win) {
    int max_y, max_x;
    getmaxyx(win, max_y, max_x); // Get the dimensions of the window

    // Draw top and bottom borders
    for (int x = 0; x < max_x; ++x) {
        mvwaddch(win, 0, x, 'X'); // Top border
        mvwaddch(win, max_y - 1, x, 'X'); // Bottom border
    }

    // Draw left and right borders
    for (int y = 0; y < max_y; ++y) {
        mvwaddch(win, y, 0, 'X'); // Left border
        mvwaddch(win, y, max_x - 1, 'X'); // Right border
    }
}

// to display menu options for user to navigate and select from
int Menu::display_options() {
    int menu_h = LINES - 1;  
    int menu_w = COLS - 1;
    menuwin = newwin(menu_h, menu_w, 1, 1);
    draw_custom_border(menuwin);

    // display the ascii art title from menu,h
    for (int i = 0; i < 5; i++) {
        mvwprintw(menuwin, i + 5, 3, "%s", title[i].c_str());
    }

    wrefresh(menuwin);
    keypad(menuwin, true);

    string options[4] = {"Start Game", "Game Info", "How to Play", "Exit Game"};
    int highlight = 0; // show which option is currently highlighted

    while (true) {
        for (int i = 0; i < 4; i++) {
            if (i == highlight) {
                wattron(menuwin, A_REVERSE);
            }
            //display options
            mvwprintw(menuwin, i + 15, 3, "%s", options[i].c_str());
            wattroff(menuwin, A_REVERSE);
        }
        wrefresh(menuwin);

        //wait for user input
        int ch = wgetch(menuwin); //wait for user input 
        switch (ch) {
            case KEY_UP: //if arrow up key is pressed
                highlight--;
                if (highlight < 0) {
                    highlight = 3;//wrap around to last option so user does not go out of bounds
                }
                break;
            case KEY_DOWN: //if arrow down key is pressed
                highlight++; 
                if (highlight > 3) {
                    highlight = 0;//wrap around to first option so user does not go out of bounds
                }
                break;
            case 10: // Enter key has been pressed
                // take action according to option selected
                if (highlight == 0) {
                    string player_name = input_name();
                    if (player_name.empty()) {
                        player_name = "Player";
                    }
                    game(player_name); // start game
                } else if (highlight == 1) {
                    int y_max, x_max;
                    getmaxyx(stdscr, y_max, x_max);
                    game_info(y_max, x_max);
                } else if (highlight == 2) {
                    int y_max, x_max;
                    getmaxyx(stdscr, y_max, x_max);
                    play_instructions(y_max, x_max);
                } else if (highlight == 3) {
                    wclear(menuwin);
                    wrefresh(menuwin);
                    delwin(menuwin);
                    return 1; // Exit the menu
                }
                break;
            default:
                break;
        }
        wrefresh(menuwin);
    }
}


void Menu::game_info(int y_max, int x_max) {
    WINDOW* game_info_win = newwin(15, 70, (y_max - 15) / 2, (x_max - 70) / 2); //create a new window for game info
    draw_custom_border(game_info_win);
    //display the game info
    mvwprintw(game_info_win, 2, 3, "About the game:");
    mvwprintw(game_info_win, 4, 3, "Welcome to Angryball!");
    mvwprintw(game_info_win, 5, 3, "Version: 1.0");
    mvwprintw(game_info_win, 6, 3, "An arcade game inspired by DX-Ball");
    mvwprintw(game_info_win, 7, 3, "Developed by: Group 99");
    mvwprintw(game_info_win, 9, 3, "Press any key to return.");

    wrefresh(game_info_win);

    wgetch(game_info_win);
    flushinp(); // Flush the input buffer
    
    werase(game_info_win);
    wrefresh(game_info_win);
    delwin(game_info_win);

    // Refresh the menu window
    touchwin(menuwin);
    wrefresh(menuwin);
}

void Menu::play_instructions(int y_max, int x_max) {
    WINDOW* play_instructions_win = newwin(15, 70, (y_max - 15) / 2, (x_max - 70) / 2); //create a new window for instructions 
    draw_custom_border(play_instructions_win);

    //display instructions 
    mvwprintw(play_instructions_win, 2, 3, "Game Instructions:");
    mvwprintw(play_instructions_win, 4, 3, "1. Navigate the power bar using the arrow keys");
    mvwprintw(play_instructions_win, 5, 3, "2. Strike the bricks to earn points");
    mvwprintw(play_instructions_win, 6, 3, "3. Aim to gather power-ups that can improve control");
    mvwprintw(play_instructions_win, 7, 3, "4. Avoid power downs that may hinder your progress");
    mvwprintw(play_instructions_win, 9, 3, "Press any key to return to the main menu");

    wrefresh(play_instructions_win);

    wgetch(play_instructions_win);
    flushinp(); // Flush the input buffer

    werase(play_instructions_win);
    wrefresh(play_instructions_win);
    delwin(play_instructions_win);

    // Refresh the menu window
    touchwin(menuwin);
    wrefresh(menuwin);
}


string Menu::input_name() {
    int menu_h = LINES - 1;  
    int menu_w = COLS - 1;
    char player_name[50];  
    WINDOW* input_name_win = newwin(5, 70, (menu_h) / 2, (menu_w - 70) / 2);
    draw_custom_border(input_name_win);
    mvwprintw(input_name_win, 2, 3, "Enter player name to start: ");
    wrefresh(input_name_win);

    echo();
    // to get the player name input by user 
    wgetnstr(input_name_win, player_name, sizeof(player_name) - 1);  
    
    noecho();
   
    werase(input_name_win); 
    wrefresh(input_name_win);

    delwin(input_name_win);  
    
    return string(player_name);  
}
