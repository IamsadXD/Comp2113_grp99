#include <ncurses.h>
#include <iostream>
#include <string>
 
#include "Menu.h"

using namespace std; 

Menu::Menu() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
}


int Menu::display_options() {

    // to display the ascii art
    menuwin = newwin(menu_h, menu_w, 1, 1);
    box(menuwin, 0, 0);
    
    for (int i = 0; i < 5; i++) {
        mvwprintw(menuwin, i + 5, 3, title[i].c_str());
    }   

    wrefresh(menuwin);

    keypad(menuwin,true);

    string options[4] = {"Start Game", "Game Info", "How to Play", "Exit Game"};
    int option;
    int highlight  = 0;
    
    while (true) {
        for (int i = 0; i < 4; i++) {
            if (i == highlight) {
                wattron(menuwin, A_REVERSE); 
            }
            // display options
            mvwprintw(menuwin, i + 15, 3, options[i].c_str());  
            wattroff(menuwin, A_REVERSE);
        }

        option = wgetch(menuwin);
        switch (option) {
            case KEY_UP:
                highlight--;
                if (highlight < 0) {
                    highlight = 3; // wrap around to go to last option
                }
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight > 3) {
                    highlight = 0; // wrap around to go to first option
                }
                break;
            case 10: // return key has been pressed
                if(highlight == 0) {
                    string player_name = input_name(menu_w, menu_h);
                    //new Game(name);
                } else if(highlight == 1) {
                    int y_max, x_max;
                    getmaxyx(stdscr, y_max, x_max);
                    game_info(y_max, x_max);
                } else if(highlight == 2) {
                    int y_max, x_max;
                    getmaxyx(stdscr, y_max, x_max);
                    play_instructions(y_max, x_max);
                } else if(highlight == 3) {
                    wclear(menuwin);
                    wrefresh(menuwin);
                    delwin(menuwin);
                    return 1;
                }
                break;
            default:
                break;

        }
        
        wrefresh(menuwin);
    }

}


void Menu::game_info(int y_max, int x_max) {
    WINDOW* game_info_win = newwin(15, 70, (y_max - 50) / 2, (x_max - 40) / 2);
    box(game_info_win, 0, 0);
    mvwprintw(game_info_win, 2, 3, "About the game:");
    mvwprintw(game_info_win, 4, 3, "Welcome to Angryball!");
    mvwprintw(game_info_win, 5, 3, "Version: 1.0");
    mvwprintw(game_info_win, 6, 3, "An arcade game inspired by DX-Ball");
    mvwprintw(game_info_win, 7, 3, "Developed by: Group 99");
    mvwprintw(game_info_win, 9, 3, "Press any key to return.");
   

    wgetch(game_info_win); 

    werase(game_info_win); 
    wrefresh(game_info_win);

    delwin(game_info_win);  
}

void Menu::play_instructions(int y_max, int x_max) {
    WINDOW* play_instructions_win = newwin(15, 70, (y_max - 50) / 2, (x_max - 40) / 2);
    box(play_instructions_win, 0, 0);
    mvwprintw(play_instructions_win, 2, 3, "Game Instructions:");
    mvwprintw(play_instructions_win, 4, 3, "1. Navigate the power bar using the arrow keys");
    mvwprintw(play_instructions_win, 5, 3, "2. Strike the bricks to earn points");
    mvwprintw(play_instructions_win, 6, 3, "3. Aim to gather power-ups that can improve control");
    mvwprintw(play_instructions_win, 7, 3, "4. Avoid power downs that may hinder your progress");
    mvwprintw(play_instructions_win, 9, 3, "Press any key to return to main menu");
    
    wgetch(play_instructions_win); 

    werase(play_instructions_win); 
    wrefresh(play_instructions_win);

    delwin(play_instructions_win);  
}



string Menu::input_name(int menu_w, int menu_h) {
    char player_name[50];  
    WINDOW* input_name_win = newwin(5, 70, (menu_h) / 2, (menu_w - 70) / 2);
    keypad(input_name_win,true);
    box(input_name_win, 0, 0);
    mvwprintw(input_name_win, 2, 3, "Enter player name to start: ");
    wrefresh(input_name_win);

    echo();
    
    wgetnstr(input_name_win, player_name, sizeof(player_name) - 1);  


    noecho();
   
    werase(input_name_win); 
    wrefresh(input_name_win);

    delwin(input_name_win);  
    
    return string(player_name);  
}
