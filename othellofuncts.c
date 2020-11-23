#include "othellofuncts.h"
#include <windows.h>


board startGame(){
    board game;
    for (int i = 0; i < 8; i++){
        game.board[i] = (position*)malloc(8*sizeof(position));
    }
    game.blacks = 0;
    game.whites = 0;
    game.unflips = 0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            game.board[i][j].full = 0;
            game.board[i][j].color = -1;
            game.board[i][j].flippable = -1;
        }
    }
    return game;
}

int swapTurn(int currPlayer){
    return !(currPlayer);
}

int gameOver(board* game){
    if(availableTurn(0,game)==0 && availableTurn(1,game)==0){
        if(game->blacks > game->whites){
            //black win condition
            return 0; // black
            printf("black win");
        }
        else if(game->blacks < game->whites){
            //white win condition
            return 1; //white
            printf("white win");
        }
        else if(game->blacks == game->whites){
            //tie condition
            return 2; //tie
            printf("tie game");
        }
    }
    return -1;
}

position* pickMoveAI(position* moves, int numMoves){
    int moveIndex = rand()%numMoves;
    return &moves[moveIndex];
}

 int playerTurn(int player, board* game){
    //when player clicks with mouse
    int mouseX = 0; // initialize x
    int mouseY = 0; // initialize y
    position* play;
    do{
        //wait for player click;
        mouseX = 1; // where click;
        mouseY = 1; // where click;
        play = whichPosition(mouseX,mouseY);
    }while (!checkPosition(play,game));
    return 0;
}