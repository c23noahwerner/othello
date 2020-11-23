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
            game.board[i][j].row = i;
            game.board[i][j].col = j;
        }
    }
    game.board[4][4].color = 1;
    game.board[5][5].color = 1;
    game.board[4][5].color = 0;
    game.board[5][4].color = 0;
    checkStatus(&game);
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
    }while (!checkPosition(player, play,game));
    flips(player,play,game);
    return 0;
}
int checkPosition(int player, position* play,board* game){
    //if all 4 surrounding position are same color as player
    return 0;
    //check directly above if not on edge: if finds opposite color, then same color
    return 1;
    //check directly below if not on edge: if finds opposite color, then same color
    return 1;
    //check directly to the left if not on edge: if finds opposite color, then same color
    return 1;
    //check to the right, same as above:
    return 1;
    //check up left diagonal if 2 away from edge for same condition
    return 1;
    //check up right diagonal, same as above:
    return 1;
    //check down left diagonal, same as above:
    return 1;
    //check down right diagonal, same as above:
    return 1;
    //if none of the above,
    return 0;
}
int checkFlip(board* game){
    int numUnflip = 0;
    for(int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if(flippable(game,&game->board[i][j])){
                numUnflip += 1;
                game->board[i][j].flippable = 0;
            }
        }
    }
    game->unflips = numUnflip;
    return numUnflip;
}
int flippable(board* game, position* pos){
    //if corner
    return 0;
    //if edge and edge is full
    return 0;
    //if surrounded by 4 of opposite color
    return 0;
    //if row/col/diagonal all filled
    return 0;
    //else
    return 1;
}
int flips(int player, position* pos, board* game){
    pos->color = player;
    position* flippers;
    int flipperIndex = 0;
    for(int i =0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            //check up and down to see if its surrounded or in a surrounded line
            //||check left anad right to see if its surrounded or in a surrounded line
            //||check top left to bottom right diagonal to see if its surrounded or in a surrounded line
            //||check bottom left to top right diagonal to see if its surrounded or in a surrounded line
                flippers[flipperIndex] = game->board[i][j];
                flipperIndex++;
        }
    }
    //flips all the colors, uses pointers so this should be pretty obvious
    for(int i = 0; i < flipperIndex; i++){
        flippers[i].color = !(flippers[i].color);
    }
}
int availableTurn(int player, board* game){
    for(int i = 0; i < 8;i++){
        for(int j = 0; j < 8; j++){
            if(game->board[i][j].color < 0 && checkPosition(player, &game->board[i][j],game)){
                return 1;
            }
        }
    }
    return 0;
}
void moveAI(position* move, board* game){
    flips(0,move,game);
}
position* movesAI(board* game){
    position* moves;
    int movesIndex = 0;
    for(int i = 0; i < 8;i++){
        for(int j = 0; j < 8; j++){
            if(game->board[i][j].color < 0 && checkPosition(0, &game->board[i][j],game)){
                moves[movesIndex] = game->board[i][j];
                movesIndex++;
            }
        }
    }
    return moves;
}
int checkWhites(board* game){
    int numWhite = 0;
    for(int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if(game->board[i][j].color == 1){
                numWhite += 1;
            }
        }
    }
    game->whites = numWhite;
    return numWhite;
}
int checkBlacks(board* game){
    int numBlack = 0;
    for(int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if(game->board[i][j].color == 0){
                numBlack += 1;
            }
        }
    }
    game->blacks = numBlack;
    return numBlack;
}
int checkStatus(board* game){
    checkFlip(game);
    checkWhites(game);
    checkBlacks(game);
    updateBoard(game);
    return 0;
}