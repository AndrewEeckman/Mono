#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "boardManager.h"
#include "ruleManager.h"

//argv[1] = Rules;
//argv[2] = Board;
//argv[3] = Random

int main(int argc, char** argv) {

    int numOfSpaces;

    struct rulesProperties rules;

    /* FIXME: FIX READ IN FUNCTIONS
    readInBoard(argv[2], &numOfSpaces);
    readInRules(argv[1], &rules);

    printf("\n-----RULES-----\n\n");

    printf("Starting Cash: %d\n", rules.startingCash);
    printf("Turn Limit (-1 for no turn limit): %d\n", rules.turnLimit);
    printf("Number of Players Left To End Game: %d\n", rules.numOfPlayerToEndGame);
    printf("Property Set Multiplier: %d\n", rules.propertySetMultiplier);
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
    numOfSpaces = 5;

    struct properties spacesOnBoard[numOfSpaces];

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

    spacesOnBoard[0].type = "Go";
    spacesOnBoard[0].setID = 0;
    spacesOnBoard[0].intraID = atoi("Go");

    spacesOnBoard[1].type = "Property";
    spacesOnBoard[1].setID = 0;
    spacesOnBoard[1].intraID = 0;
    spacesOnBoard[1].name = "Redwood";
    spacesOnBoard[1].cost = 100;
    spacesOnBoard[1].houseCost = 50;
    spacesOnBoard[1].hotelCost = 50;
    spacesOnBoard[1].rent = 20;
    spacesOnBoard[1].rentWHouse = 60;
    spacesOnBoard[1].rentWHotel = 100;

    spacesOnBoard[2].type = "Property";
    spacesOnBoard[2].setID = 0;
    spacesOnBoard[2].intraID = 1;
    spacesOnBoard[2].name = "Cottonwood";
    spacesOnBoard[2].cost = 150;
    spacesOnBoard[2].houseCost = 50;
    spacesOnBoard[2].hotelCost = 50;
    spacesOnBoard[2].rent = 25;
    spacesOnBoard[2].rentWHouse = 75;
    spacesOnBoard[2].rentWHotel = 150;

    spacesOnBoard[3].type = "Property";
    spacesOnBoard[3].setID = 1;
    spacesOnBoard[3].intraID = 0;
    spacesOnBoard[3].name = "Potter";
    spacesOnBoard[3].cost = 200;
    spacesOnBoard[3].houseCost = 75;
    spacesOnBoard[3].hotelCost = 75;
    spacesOnBoard[3].rent = 40;
    spacesOnBoard[3].rentWHouse = 120;
    spacesOnBoard[3].rentWHotel = 200;

    spacesOnBoard[4].type = "Property";
    spacesOnBoard[4].setID = 1;
    spacesOnBoard[4].intraID = 1;
    spacesOnBoard[4].name = "Wall";
    spacesOnBoard[4].cost = 250;
    spacesOnBoard[4].houseCost = 100;
    spacesOnBoard[4].hotelCost = 100;
    spacesOnBoard[4].rent = 70;
    spacesOnBoard[4].rentWHouse = 150;
    spacesOnBoard[4].rentWHotel = 250;

    int numOfPlayers = 3;

    char **board = createBoard(numOfPlayers, numOfSpaces, spacesOnBoard);

    return 0;
}
