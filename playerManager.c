//
// Created by Andrew Eeckman on 1/16/18.
//

#include "playerManager.h"
#include <stdlib.h>
#include <stdio.h>
#include "structs.h"

void getMove(struct boardManager board, int numOfPlayers, int numOfSpaces, int player, int ** randNum) {
    int playerAction = 0;

    printf("\nPlayer %d please choose an action\n", player);
    printf("1: Roll Dice\n2: Inspect Player\n3: Leave Game\nYour action: ");
    scanf("%d", &playerAction);

    if(playerAction == 1) {
        movePlayer(board, player, numOfSpaces, randNum);

    } else if(playerAction == 2) {
        inspectPlayer(board, numOfPlayers, numOfSpaces, player);

    } else if(playerAction == 3) {

    }
}

void readInRand(char * argv, int ** randNum) {
    FILE *fp;
    int i = 0;
    int tempNum;

    *randNum = (int *) malloc(sizeof(int) * 10000);

    fp = fopen(argv, "r");

    if (fp == NULL) {
        printf("Unable to open file: %s", argv);
        exit(0);
    }

    while (!(feof(fp))) {
        fscanf(fp, "%d", &tempNum);
        (*randNum)[i] = tempNum;
        i++;
    }

    *randNum = realloc(*randNum, i * sizeof(int));
}

void inspectPlayer(struct boardManager board, int numOfPlayers, int numOfSpaces, int player) {
    int playerToBeInspected = 0;

    printf("Which player would you like to inspect?\n");

    for(int i = 0; i < numOfPlayers; i++) {
        printf("%d for Player %d\n", i, i);
    }

    printf("Your choice: ");
    scanf("%d", &playerToBeInspected);

    printf("\n");
    printf("Player %d\n", playerToBeInspected);
    printf(" Cash: %d\n", board.player[playerToBeInspected].cashAmount);
    printf(" Properties Owned: \n");
    for(int i = 0; i < numOfSpaces/3; i++) {
        printf("  %d:%s\n", i, board.player[i].propertiesOwned[i]);
    }
}

void movePlayer(struct boardManager board, int player, int numOfSpaces, int ** randNum) {
    int diceRoll1 = ((*randNum)[0] % 6) + 1;
    for(int i = 0; i < sizeof((*randNum)); i ++){
        (*randNum)[i]= (*randNum)[i+1];
    }
    *randNum = realloc(*randNum, (sizeof(*randNum)-1) * sizeof(int));

    int diceRoll2 = ((*randNum)[0] % 6) + 1;
    //Delete the random number just used from the array
    for(int i = 0; i < sizeof((*randNum)); i ++){
        (*randNum)[i]= (*randNum)[i+1];
    }
    *randNum = realloc(*randNum, (sizeof(*randNum)-1) * sizeof(int));

    int diceRoll = diceRoll1 + diceRoll2;

    printf("You rolled a %d\n", diceRoll);

    /*
    if(diceRoll + board.player[player].boardPosition < numOfSpaces) {
        board.player[player].boardPosition = board.player[player].boardPosition + diceRoll;

    } else if(diceRoll + board.player[player].boardPosition >= numOfSpaces) {
        board.player[player].boardPosition = (diceRoll + board.player[player].boardPosition) % numOfSpaces;
        board.player[player].cashAmount += board.boardSpace[board.player[player].boardPosition].spaceType.goType.earnings;

    } else {
        board.player[player].boardPosition = numOfSpaces-1;
    }

    if(board.player[player].boardPosition == 0) {
        board.player[player].cashAmount;
    }
     */
}