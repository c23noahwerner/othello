/** othello.c
* ==============================================================
* Name: Noah Werner, Fall 2020
* Section: M6A
* Project: Final Project - Othello
* Description: The game runs using windows.h and is an interactive board game intended to function exactly like the othello board game
* Documentation Statement: I copied and pasted the function header for the main from the windowsline example after researching what each paramater
* was used for. 
* ==============================================================
* UserManual/Instructions:
*   Replace this paragraph with instructions on how to build, run,
*   and use your program.  If your program has "built-in" instructions
*   or a tutorial you should say that here and forgo a long description.
 *
 *  Bonus Features (upto 10 pts) - List here
 *  1)
 *  2)
 *  3)
 *
 *  Required Programming Skills (must have 5 of 6):
 *   1) Dynamic Memory Allocation
 *          What you did to meet this req: xxx
 *              File: (file where example is located)
 *              Line#: (line in file where it is located)
 *   2) Pointers
 *          What you did to meet this req: xxx
 *              File:
 *              Line#:
 *   3) File I/O
 *          What you did to meet this req: xxx
 *              File:
 *              Line#:
 *   4) Structs
 *          What you did to meet this req: xxx
 *              File:
 *              Line#:
 *
 *   5) String Manipulation
 *          What you did to meet this req: xxx
 *              File:
 *              Line#:
 *
 *   6) Processing of Array Data
 *          What you did to meet this req: xxx
 *              File:
 *              Line#:
 *
 *  Required Advanced Programming Skills (1 or more):
 *   1) Recursion
 *          What you did to meet this req: xxx
 *              File: (file where example is located)
 *              Line#: (line in file where it is located)
 *
 *   2) 2D Dynamic Memory
 *          What you did to meet this req: xxx
 *              File:
 *              Line#:
 *
 *   3) Graphics - Curses or Win32
 *          What you did to meet this req: xxx
 *              File:
 *              Line#:
 *
 *   List any changes or omissions from stated shall requirements (from
 *   your design) also describe any functionality that isn't working.
 *      Requirement changes/omissions:
 *          1)
 *          2)
 *          3)
 *
 *      Errors:
 *          1)
 *          2)
 *
 *   How many hours did you spend on this project: 3
 *   How many lines of code did you write in total: 28
 *
*/
#ifndef OTHELLOFUNCTS_H
#define OTHELLOFUNCTS_H
#include "Windows.h"
 
typedef struct position_struct{
    int full;
    int color;
    int flippable;
    int row;
    int col;
}position;

typedef struct board_struct{
    position* board[8];
    int blacks;
    int whites;
    int unflips;
}board;

void runUI();

board startGame();

int playerTurn(int player, board* game);
int swapTurn(int currPlayer);
int checkPosition(int player, position* play,board* game);
int flips(int player, position* pos, board* game);
int checkStatus(board* game);
int checkFlip(board* game);
int availableTurn(int player, board* game);
int updateBoard(board* game);
int movesAI(board* game, position* moves);
position* pickMoveAI(position* moves, int numMoves);
void moveAI(position* move);
int gameOver(board* game); //implemented, finished
position* whichPosition(int xcoord, int ycoord); 
int flippable(board* game, position* pos); //implemented, fixme
#endif