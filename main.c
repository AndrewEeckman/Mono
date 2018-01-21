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

    /* FIXME: FIX READ IN FUNCTIONS
    readInBoard(argv[2], &numOfSpaces);
    readInRules(argv[1], &rules);
    */
    /*
   struct rulesProperties {
    int startingCash;
    int turnLimit;
    int numOfPlayerToEndGame;
    int propertySetMultiplier;
    int numHousesBeforeHotels;
    bool buildHousesEvenly;         //NOT USING
    bool putMoneyInFreeParking;     //NOT USING
    bool auctionProperties;         //NOT USING
    int salMultiLandingOnGo;
};
    */
    /*
    printf("\n-----RULES-----\n\n");

    printf("Starting Cash: %d\n", rules.startingCash);
    printf("Turn Limit (-1 for no turn limit): %d\n", rules.turnLimit);
    printf("Number of Players Left To End Game: %d\n", rules.numOfPlayerToEndGame);
    printf("Property Set Multiplier: %d\n", rules.propertyTypeSetMultiplier);
    printf("Number of Houses Before Hotels: %d\n", rules.numHousesBeforeHotels);
    printf("Must Build Houses Evenly: %s\n", rules.buildHousesEvenly);
    printf("Put Money In Free Parking: %s\n", rules.putMoneyInFreeParking);
    printf("Auction Properties: %s\n", rules.auctionProperties);
    printf("Salary Multiplier For Landing On Go: %d\n", rules.salMultiLandingOnGo);

    printf("\n");

    struct properties spacesOnBoard[numOfSpaces];

    readInSpaces(argv[2], &spacesOnBoard, numOfSpaces);

    printf("-----BOARD-----\n\n");
    printf("Number of Spaces: %d\n", numOfSpaces);

    for(int i = 0; i < numOfSpaces; i++) {
        if (i == 0) {
            printf("%s,%d,%s", &*spacesOnBoard[i].type, &spacesOnBoard[i].setID, &*spacesOnBoard[i].intraID);
        }

        printf("%s,%d,%s,%s,%d,%d,%d,%d,%d,%d", spacesOnBoard[i].type, spacesOnBoard[i].setID, spacesOnBoard[i].intraID,
               spacesOnBoard[i].name, spacesOnBoard[i].cost,
               spacesOnBoard[i].houseCost, spacesOnBoard[i].hotelCost, spacesOnBoard[i].rent,
               spacesOnBoard[i].rentWHouse, spacesOnBoard[i].rentWHotel);
    } FIXME: TEMPORARY TEST CASES LISTED BELOW
    */


    //TEST CASES FOR WHEN FILE READING ISN'T WORKING PROPERLY


    //int numOfSpaces = 5;

    struct rulesProperties rules;

    //struct boardManager board;

    readInRules(argv[1], &rules);

    int *randNum;
    readInRand(argv[3], &randNum);

    /*
    rules.startingCash = 1500;
    rules.turnLimit = 10;
    rules.numOfPlayerToEndGame = 1;
    rules.propertySetMultiplier = 2;
    rules.numHousesBeforeHotels = 4;
    rules.buildHousesEvenly = true;
    rules.putMoneyInFreeParking = false;
    rules.auctionProperties = true;
    rules.salMultiLandingOnGo = 1;
     */

    /*

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

    while(i < rules.turnLimit) {
<<<<<<< HEAD
        if(board.player[i % numOfPlayers].inGame == true) {
            getMove(board, rules, numOfPlayers, numOfSpaces, i % numOfPlayers);
        }
=======
        displayBoard(board, numOfSpaces, numOfPlayers);
        getMove(board, numOfPlayers, numOfSpaces, i % numOfPlayers, &randNum);
>>>>>>> 9c1681dc78e7f410e4c99fb5c7e027d0f4203c7d
        i++;
    }

    return 0;
    */
}
