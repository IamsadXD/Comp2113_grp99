# Angryball

## Team members
- Ni Hong Hung
- Lee Cheuk Hang Jacob
- De Alwis Watuthanthrige Omaya Kavindi
- Rahman Rayan
  
## Application Description
- Angryball is an engaging arcade-style game where players control a power bar to manipulate a ball and break bricks. 
- The objective of the game is to score as many points by breaking bricks.
- Players can collect power-ups to enhance their gameplay or face power-downs that create obstacles. 

## List of Features
- Menu (Play, Save, Exit, Instructions) (Omaya)
- Scoreboard (Bricks destroyed) (Omaya)
- Brick generation (William)
- Power bar (Rayan and William)
- Powerups (Controlled movement, regenerate lost lives, longer power bar) (Jacob)
- Powerdowns (Extreme speeds, shorter power bar) (Jacob)
- Ball collision (Rayan)

## Code requirements
- Generation of random events: We have randomized the generation of bricks at the beginning of game play
- Data structures for storing data: These are essential to store and manage game entities such as bricks, ball, and player scores. 
- Dynamic memory management: Employed to create and delete instances of the ball at the beginning of each round.
- File input/output: This is used to maintain a record of the highest score. 
- Program codes in multiple files: Separate files are used to handle different aspects of the game (menu, scoreboard, brick generation, etc.) with main.cpp joining them together. 


## List of non-standard C/C++ libraries
- ncurses: enhances the user interface by providing text-based graphics and controls in a terminal environment 

## Compilation and Execution Instructions
export TERMINFO=Angryball/ncurses/share/terminfo
make -C Angryball
Angryball/angryball
