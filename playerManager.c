//
// Created by Andrew Eeckman on 1/16/18.
//

#include "playerManager.h"
#include <stdlib.h>
#include <stdio.h>
#include "structs.h"

void getMove(struct boardManager board, int numOfPlayers, int numOfSpaces, int player) {
    int playerAction = 0;

    printf("\nPlayer %d please choose an action\n", player);
    printf("1: Roll Dice\n2: Inspect Player\n3: Leave Game\nYour action: ");
    scanf("%d", &playerAction);

    if(playerAction == 1) {
        movePlayer(board, player, numOfSpaces);

    } else if(playerAction == 2) {

    } else if(playerAction == 3) {

    }
}

void readInRand(char * argv, int ** randNum){
    FILE *fp;
    int i = 0;
    int tempNum;

    *randNum = (int*)malloc(sizeof(int)*10000);

    fp = fopen(argv, "r");

    if (fp == NULL) {
        printf("Unable to open file: %s", argv);
        exit(0);
    }

    while(!(feof(fp))) {
        fscanf(fp, "%d", &tempNum);
        (*randNum)[i] = tempNum;
        i ++;
    }

    *randNum = realloc(*randNum, i * sizeof(int));


}

void movePlayer(struct boardManager board, int player, int numOfSpaces) {
    int diceRoll = (rand() % 12) + 1;
    printf("You rolled a %d\n", diceRoll);

    if(diceRoll + board.player[player].boardPosition < numOfSpaces) {
        board.player[player].boardPosition = board.player[player].boardPosition + diceRoll;
    } else if(diceRoll + board.player[player].boardPosition >= numOfSpaces) {
        board.player[player].boardPosition = (diceRoll + board.player[player].boardPosition) % numOfSpaces;
    } else {
        board.player[player].boardPosition = numOfSpaces-1;
    }
}