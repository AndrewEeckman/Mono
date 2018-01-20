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


    int numOfSpaces = 5;

    struct rulesProperties rules;

    struct boardManager board;


    rules.startingCash = 1500;
    rules.turnLimit = 10;
    rules.numOfPlayerToEndGame = 1;
    rules.propertySetMultiplier = 2;
    rules.numHousesBeforeHotels = 4;
    rules.buildHousesEvenly = true;
    rules.putMoneyInFreeParking = false;
    rules.auctionProperties = true;
    rules.salMultiLandingOnGo = 1;

    //Type,Set Id,Intraset Id,Name,Property Cost,House Cost,Hotel Cost,Rent,Rent with House,Rent With Hotel
    //Property,0,0,Asia,100,50,50,20,60,100
    
    board.boardSpace = malloc(numOfSpaces * sizeof(struct boardSpace));
    

    board.boardSpace[0].spaceType.goType.type = "Go";
    board.boardSpace[0].spaceType.goType.setID = 0;
    board.boardSpace[0].spaceType.goType.intraID = "Go"; //FIXME: REPLACE WITH TYPE/NAME

    board.boardSpace[1].spaceType.propertyType.type = "Property";
    board.boardSpace[1].spaceType.propertyType.setID = 0;
    board.boardSpace[1].spaceType.propertyType.intraID = 0;
    board.boardSpace[1].spaceType.propertyType.name = "Redwood";
    board.boardSpace[1].spaceType.propertyType.cost = 100;
    board.boardSpace[1].spaceType.propertyType.houseCost = 50;
    board.boardSpace[1].spaceType.propertyType.hotelCost = 50;
    board.boardSpace[1].spaceType.propertyType.rent = 20;
    board.boardSpace[1].spaceType.propertyType.rentWHouse = 60;
    board.boardSpace[1].spaceType.propertyType.rentWHotel = 100;

    board.boardSpace[2].spaceType.propertyType.type = "Property";
    board.boardSpace[2].spaceType.propertyType.setID = 0;
    board.boardSpace[2].spaceType.propertyType.intraID = 1;
    board.boardSpace[2].spaceType.propertyType.name = "Cottonwood";
    board.boardSpace[2].spaceType.propertyType.cost = 150;
    board.boardSpace[2].spaceType.propertyType.houseCost = 50;
    board.boardSpace[2].spaceType.propertyType.hotelCost = 50;
    board.boardSpace[2].spaceType.propertyType.rent = 25;
    board.boardSpace[2].spaceType.propertyType.rentWHouse = 75;
    board.boardSpace[2].spaceType.propertyType.rentWHotel = 150;

    board.boardSpace[3].spaceType.propertyType.type = "Property";
    board.boardSpace[3].spaceType.propertyType.setID = 1;
    board.boardSpace[3].spaceType.propertyType.intraID = 0;
    board.boardSpace[3].spaceType.propertyType.name = "Potter";
    board.boardSpace[3].spaceType.propertyType.cost = 200;
    board.boardSpace[3].spaceType.propertyType.houseCost = 75;
    board.boardSpace[3].spaceType.propertyType.hotelCost = 75;
    board.boardSpace[3].spaceType.propertyType.rent = 40;
    board.boardSpace[3].spaceType.propertyType.rentWHouse = 120;
    board.boardSpace[3].spaceType.propertyType.rentWHotel = 200;

    board.boardSpace[4].spaceType.propertyType.type = "Property";
    board.boardSpace[4].spaceType.propertyType.setID = 1;
    board.boardSpace[4].spaceType.propertyType.intraID = 1;
    board.boardSpace[4].spaceType.propertyType.name = "Wall";
    board.boardSpace[4].spaceType.propertyType.cost = 250;
    board.boardSpace[4].spaceType.propertyType.houseCost = 100;
    board.boardSpace[4].spaceType.propertyType.hotelCost = 100;
    board.boardSpace[4].spaceType.propertyType.rent = 70;
    board.boardSpace[4].spaceType.propertyType.rentWHouse = 150;
    board.boardSpace[4].spaceType.propertyType.rentWHotel = 250;

    int numOfPlayers = 0;
    int propertyRatio = numOfSpaces/3;

    printf("How many players will be playing: ");
    scanf("%d", &numOfPlayers);

    board.player = malloc(numOfPlayers * sizeof(struct player));

    for(int a = 0; a < numOfPlayers; a++) {
        board.player[a].propertiesOwned = (char **) malloc(propertyRatio * sizeof(char *));
        for (int b = 0; b < propertyRatio; b++) {
            board.player[a].propertiesOwned[b] = (char *) malloc(5 * sizeof(char));

        }
    }

    for(int i = 0; i < numOfPlayers; i++) {
        board.player[i].cashAmount = rules.startingCash;
        board.player[i].netWorth = rules.startingCash;
        board.player[i].boardPosition = 0;
        board.player[i].numIdentifier = i;

        for(int j = 0; j < propertyRatio; j++) {
            board.player[i].propertiesOwned[j] = " ";
        }
    }
    int i = 0;

    while(i < 10) {
        displayBoard(board, numOfSpaces, numOfPlayers);
        getMove(board, numOfPlayers, numOfSpaces);
        i++;
    }

    return 0;
}
