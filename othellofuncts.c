#include "othellofuncts.h"
#include <windows.h>

 
board startGame(){
    printf("\t\tcalled startGame\n");
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
    printf("\t");
    checkStatus(&game); 
    return game;
}

int swapTurn(int currPlayer){
    printf("\t\tcalled swapTurn\n");
    return !(currPlayer);
}
/*
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
*/

position* pickMoveAI(position* moves, int numMoves){
    printf("\t\tcalled pickMoveAI\n");
    int moveIndex = rand()%numMoves;
    return &moves[moveIndex];
}
/*
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
*/
int checkPosition(int player, position* play,board* game){
    printf("\t\tcalled checkposition\n");
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
    /* for(int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if(flippable(game,&game->board[i][j])){
                numUnflip += 1;
                game->board[i][j].flippable = 0;
            }
        }
    } */
    printf("\t\tcalled checkFlip\n");
    printf("\t");
    flippable(game,&game->board[0][0]);
    game->unflips = numUnflip;
    return numUnflip;
}

int flippable(board* game, position* pos){
    printf("\t\tcalled flippable\n");
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
    printf("\t\tcalled flips\n");
    pos->color = player;
    position** flippers;
    int flipperIndex = 0;
    int vertCheck = 0;
    int horzCheck = 0;
    int topDcheck = 0;
    int botUcheck = 0;
    int alreadyIn = 0;
    for(int i =0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            //check up and down to see if its surrounded or in a surrounded line
            vertCheck = 0;
            horzCheck = 0;
            topDcheck = 0;
            botUcheck = 0;
            alreadyIn = 0;
            for(int k = i+1; k < 8;k++){
                if(game->board[k][j].color < 0){break;}
                if(game->board[k][j].color == !(game->board[i][j].color)){
                    vertCheck = 1;
                }
            }
            if(vertCheck){
                for(int l = i-1; l > -1;l--){
                    if(game->board[l][j].color < 0){break;}
                    if(game->board[l][j].color == !(game->board[i][j].color)){
                        flippers[flipperIndex] = &game->board[i][j];
                        flipperIndex++;
                    }
                }
            }

            //||check left anad right to see if its surrounded or in a surrounded line
            for(int k = i+1; k < 8;k++){
                if(game->board[i][k].color < 0){break;}
                if(game->board[i][k].color == !(game->board[i][j].color)){
                    horzCheck = 1;
                }
            }
            if(horzCheck){
                for(int l = i-1; l > -1;l--){
                    if(game->board[i][l].color < 0){break;}
                    if(game->board[i][l].color == !(game->board[i][j].color)){
                        for(int m = 0; m < flipperIndex; m++){
                            if(flippers[m] = &game->board[i][j]){
                                alreadyIn = 1;
                            }
                        }
                        if(!alreadyIn){
                            flippers[flipperIndex] = &game->board[i][j];
                            flipperIndex++;
                        }
                    }
                }
            }
            //||check top left to bottom right diagonal to see if its surrounded or in a surrounded line
            for(int k = i+1, l = j-1; (k < 8) && (l > -1);k++,l--){
                if(game->board[k][l].color < 0){break;}
                if(game->board[k][l].color == !(game->board[i][j].color)){
                    topDcheck = 1;
                }
            }
            if(topDcheck){
                for(int m = i-1, n = j+1; (m > -1) && (n < 8);m--,n++){
                    if(game->board[m][n].color < 0){break;}
                    if(game->board[m][n].color == !(game->board[i][j].color)){
                        for(int o = 0; o < flipperIndex; o++){
                            if(flippers[o] = &game->board[i][j]){
                                alreadyIn = 1;
                            }
                        }
                        if(!alreadyIn){
                            flippers[flipperIndex] = &game->board[i][j];
                            flipperIndex++;
                        }
                    }
                }
            }
            //||check bottom left to top right diagonal to see if its surrounded or in a surrounded line
            for(int k = i+1, l = j+1; (k < 8) && (l < 8);k++,l++){
                if(game->board[k][l].color < 0){break;}
                if(game->board[k][l].color == !(game->board[i][j].color)){
                    botUcheck = 1;
                }
            }
            if(botUcheck){
                for(int m = i-1, n = j-1; (m > -1) && (n > -1);m--,n--){
                    if(game->board[m][n].color < 0){break;}
                    if(game->board[m][n].color == !(game->board[i][j].color)){
                        for(int o = 0; o < flipperIndex; o++){
                            if(flippers[o] = &game->board[i][j]){
                                alreadyIn = 1;
                            }
                        }
                        if(!alreadyIn){
                            flippers[flipperIndex] = &game->board[i][j];
                            flipperIndex++;
                        }
                    }
                }
            }
        }
    }
    //flips all the colors, uses pointers so this should be pretty obvious
    for(int i = 0; i < flipperIndex; i++){
        flippers[i]->color = !(flippers[i]->color);
    } 
    return flipperIndex;
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
    printf("\t\tcalled moveAI\n");
    printf("\t");
    flips(0,move,game);
}
/*
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
*/
int checkWhites(board* game){
    printf("\t\tcalled checkWhites\n");
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
    printf("\t\tcalled checkBlacks\n");
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
    printf("\t\tcalled checkStatus\n");
    printf("\t");
    game->unflips = checkFlip(game);
    printf("\t");
    game->whites = checkWhites(game);
    printf("\t");
    game->blacks = checkBlacks(game);
    //updateBoard(game);
    return 0;
} 