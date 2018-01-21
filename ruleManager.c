//
// Created by Andrew Eeckman on 1/12/18.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "struct.h"
#include "ruleManager.h"

void readInRules(char * argv, struct rulesProperties *rules) {
    //Creates the file variable for containing stream and the declaring the delim character and creating the temp string
    FILE *fp;

    //opens the file and sets it to the stream
    fp = fopen(argv, "r");

    //Checks to see if file opening was SUCCess and andrew is a hoe
    if(fp == NULL) {
        printf("Unable to open file: %s", argv);
        exit(0);
    }

    char tempString[100];

    fscanf(fp, "Starting Cash: %d\n", &rules->startingCash);

    fscanf(fp, "Turn Limit (-1 for no turn limit): %d\n", &rules->turnLimit);

    fscanf(fp, "Number of Players Left To End Game: %d\n", &rules->numOfPlayerToEndGame);

    fscanf(fp, "Property Set Multiplier: %d\n", &rules->propertySetMultiplier);

    fscanf(fp, "Number of Houses Before Hotels: %d\n", &rules->numHousesBeforeHotels);

    fscanf(fp, "Must Build Houses Evenly: %s\n", tempString);

    rules->buildHousesEvenly =  changeToBool(tempString);

    fscanf(fp, "Put Money In Free Parking: %s\n", tempString);

    rules->putMoneyInFreeParking = changeToBool(tempString);

    fscanf(fp, "Auction Properties: %s\n", tempString);

    rules->auctionProperties = changeToBool(tempString);

    fscanf(fp, "Salary Multiplier For Landing On Go: %d\n", &rules->salMultiLandingOnGo);

    fclose(fp);
}

bool changeToBool(char * string){
    if (strcmp((string), "Yes") == 0 ) {
        return true;
    }
    else if (strcmp(string, "No") == 0) {
        return false;
    }
    return false;
}

bool gameIsOver(struct boardManager board, int turnLimit, int currentTurnNumber, int numPlayersToWin, int numOfPlayers, int numOfPlayersLeft) {

    if(turnLimit == currentTurnNumber){
        return true;
    } else if (numPlayersToWin == numOfPlayersLeft) {
        return true;
    } else {
        return false;
    }
}

void whoWins(struct boardManager board, struct rulesProperties rules, int numPlayers, int numOfPlayersLeft, int numOfProperties) {

    int arrayOfPlayersLeft[numOfPlayersLeft-1];
    int arrayCounter = 0;

    for(int i = 0; i < numPlayers; i++) {
        if(board.player[i].inGame == true) {
            arrayOfPlayersLeft[arrayCounter] = board.player[i].numIdentifier;
            arrayCounter++;
        }
    }

    if(numOfPlayersLeft == 1) {

        printf("The winner is Player %d", arrayOfPlayersLeft[0]);
        return;

    } else {


        for(int j = 0; j < numOfPlayersLeft; j++) {
            board.player[arrayOfPlayersLeft[j]].netWorth += board.player[arrayOfPlayersLeft[j]].cashAmount;
        }

        int numOfWinners = 1;

        int maxPlayer = 0;

        for(int k = 1; k < numOfPlayersLeft; k++) {
            if(board.player[arrayOfPlayersLeft[k]].netWorth > board.player[arrayOfPlayersLeft[maxPlayer]].netWorth) {
                maxPlayer = board.player[arrayOfPlayersLeft[k]].numIdentifier;
            } else if(board.player[arrayOfPlayersLeft[k]].netWorth == board.player[arrayOfPlayersLeft[k-1]].netWorth) {
                numOfWinners++;
            }
        }

        if(numOfWinners == 1) {
            printf("The winner is Player %d", board.player[maxPlayer].numIdentifier);
        } else {
            int arrayOfWinners[numOfWinners];
            for(int k = 1; k < numOfPlayersLeft; k++) {
                if(board.player[arrayOfPlayersLeft[k]].netWorth == board.player[arrayOfPlayersLeft[k-1]].netWorth) {
                    arrayOfWinners[k] = board.player[arrayOfPlayersLeft[k]].numIdentifier;
                    arrayOfWinners[k-1] = board.player[arrayOfPlayersLeft[k-1]].numIdentifier;
                }
            }
            printf("The winners are ");

            for(int i = 0; i < numOfWinners; i++) {
                printf("Player %d ", arrayOfWinners[i]);
            }
            printf("\n");
        }

        printf("\n");

        for(int i = 0; i < numPlayers; i++) {
            printf("%d: $%d\n", i, board.player[i].netWorth);
        }

    }
}

    //Check what players are still in
    //Print the top three



