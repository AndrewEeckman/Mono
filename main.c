#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "boardManager.h"
#include "ruleManager.h"
#include "playerManager.h"
#include "structs.h"

#include "structs.h"

//argv[1] = Rules;
//argv[2] = Board;
//argv[3] = Random


int main(int argc, char** argv) {

    struct rulesProperties rules;

    struct boardManager board;

    readInRules(argv[1], &rules);

    int *randNum;
    readInRand(argv[3], &randNum);

    int numOfSpaces = 0;
    int numOfProperties = 0;

    readInBoard(&board, argv[2], &numOfProperties, &numOfSpaces);

    int numOfPlayers = 0;
    int propertyRatio = numOfSpaces/3;

    printf("How many players will be playing: ");
    scanf("%d", &numOfPlayers);

    board.player = malloc(numOfPlayers * sizeof(struct player));

    for(int a = 0; a < numOfPlayers; a++) {
        board.player[a].propertySlots = (char **) malloc(propertyRatio * sizeof(char *));
        for (int b = 0; b < propertyRatio; b++) {
            board.player[a].propertySlots[b] = (char *) malloc(10 * sizeof(char));

        }
    }

    for(int i = 0; i < numOfPlayers; i++) {
        board.player[i].cashAmount = rules.startingCash;
        board.player[i].netWorth = rules.startingCash;
        board.player[i].boardPosition = 0;
        board.player[i].numIdentifier = i;
        board.player[i].inGame = true;

        for(int j = 0; j < propertyRatio; j++) {
            board.player[i].propertySlots[j] = " ";
        }
    }
    int i = 0;

    while(i < rules.turnLimit && rules.turnLimit != -1) {
        if(board.player[i % numOfPlayers].inGame == true) {
            getMove(board, rules, numOfPlayers, numOfSpaces, i % numOfPlayers, &randNum);
        }
        i++;
    }
    return 0;
}
