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
        inspectPlayer(board, numOfPlayers, numOfSpaces, player);

    } else if(playerAction == 3) {

    }
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

void movePlayer(struct boardManager board, int player, int numOfSpaces) {
    int diceRoll = (rand() % 12) + 1;
    printf("You rolled a %d\n", diceRoll);

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
}