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
    
    //seed the time for rand pls 
    system("pause");
    return 0;
}