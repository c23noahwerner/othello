#include "othellofuncts.h"
#include <Windows.h>
#include <stdio.h>
#include <time.h>

int main(){
    srand(time(0));

    printf("startGame Testing: \n");
    printf("Expects statement from call: \n");
    board game = startGame();

    printf("\nswapTurn() testing: \n");
    printf("swapTurn(1), expects 0, returns: %d\n",swapTurn(1));
    printf("swapTurn(0), expects 1, returns: %d\n",swapTurn(0));

    
    printf("\npickMoveAI testing: \n");
    int pickmovetest = 5;
    position* pickMoveTest = (position*)malloc(sizeof(position)*pickmovetest);
    pickMoveAI(pickMoveTest,pickmovetest);

    printf("\nmoveAI testing: \n");
    position* moveAItest = (position*)malloc(sizeof(position));
    moveAI(moveAItest, &game);
    
    printf("\ncheckWhites testing: \n");
    printf("checkWhites(game), expects 2, returns: %d \n",checkWhites(&game));
    
    printf("\ncheckBlacks testing: \n");
    printf("checkBlacks(game), expects 2, returns: %d \n",checkBlacks(&game));

    printf("\nTesting available turn: \n");
    printf("availableTurn(1,&game), expect 40 calls to checkposition, return:\n");
    availableTurn(1,&game);

    printf("\ntesting flips: \n");
    //printf("flips(player,&game.board[3][4],game),expects 1, return: %d\n",flips(0,&game.board[4][6],&game));
    game.board[3][5].color = 0;
    printf("flips(player,&game.board[2][5],game, expects 2, return: %d\n",flips(1,&game.board[2][5],&game));
    printf("works for vertical flips, still working out the horizontal and diagonal algorithms.\n I also recognize that this is the same sort of checking for the other checkPosition and availableTurn functions!\n");
    printf("\ncheckWhites testing: \n");
    printf("checkWhites(game), expects 5, returns: %d \n",checkWhites(&game));
    
    game.board[5][5].color = 0;
    printf("flips(player,&game.board[1][5],game, expects 3, return: %d\n",flips(0,&game.board[1][5],&game)); 


    printf("\ncheckWhites testing: \n");
    printf("checkWhites(game), expects 1, returns: %d \n",checkWhites(&game));
    //seed the time for rand pls 
    system("pause");
    return 0;
}