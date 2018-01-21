//
// Created by Andrew Eeckman on 1/16/18.
//

#include "playerManager.h"
#include <stdlib.h>
#include <stdio.h>
#include "structs.h"

void getMove(struct boardManager board, struct rulesProperties rules, int numOfPlayers, int numOfSpaces, int player, int ** randNum) {
    int playerAction = 0;

    bool turnOver = false;
    bool rolled = false;

    while(turnOver == false) {
        displayBoard(board, numOfSpaces, numOfPlayers);

        printf("\nPlayer %d please choose an action\n", player);
        if(rolled == false) printf("1: Roll Dice\n2: Inspect Player\n3: Leave Game\nYour action: ");
        if(rolled == true)  printf("1: End Turn\n2: Inspect Player\n3: Leave Game\nYour action: ");

        scanf("%d", &playerAction);

        if (playerAction == 1 && rolled == false) {
            movePlayer(board, rules, player, numOfSpaces, randNum);
            rolled = true;

        } else if(playerAction == 1 && rolled == true) {
            turnOver = true;

        } else if (playerAction == 2) {
            inspectPlayer(board, rules, numOfPlayers, numOfSpaces, player);

        } else if (playerAction == 3) {
            leaveGame(board, rules, numOfPlayers, numOfSpaces, player);
            turnOver = true;
        }
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

void movePlayer(struct boardManager board, struct rulesProperties rules, int player, int numOfSpaces, int ** randNum) {

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

    if(diceRoll + board.player[player].boardPosition < numOfSpaces) {
        board.player[player].boardPosition = board.player[player].boardPosition + diceRoll;

    } else if(diceRoll + board.player[player].boardPosition >= numOfSpaces) {
        board.player[player].boardPosition = (diceRoll + board.player[player].boardPosition) % numOfSpaces;

        if(board.player[player].boardPosition == 0) {
            board.player[player].cashAmount += (board.boardSpace[0].spaceType.goType.earnings * rules.salMultiLandingOnGo);
        } else {
            board.player[player].cashAmount += board.boardSpace[0].spaceType.goType.earnings;
        }

    } else {
        board.player[player].boardPosition = numOfSpaces-1;
    }
}

void inspectPlayer(struct boardManager board, struct rulesProperties rules, int numOfPlayers, int numOfSpaces, int player) {

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
        printf("  %d:%s\n", i, board.player[i].propertySlots[i]);
    }
}

void leaveGame(struct boardManager board, struct rulesProperties rules, int numOfPlayers, int numOfSpaces, int player) {
    board.player[player].inGame = false;

    board.player[player].numIdentifier = NULL;
    board.player[player].boardPosition = NULL;
    board.player[player].netWorth = 0;
    board.player[player].cashAmount = 0;
    board.player[player].propertySlots = NULL;

    //FIXME: ADD IN NULLIFIER FOR OWNED PROPERTIES

}