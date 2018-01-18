//
// Created by Andrew Eeckman on 1/12/18.
//

#include "boardManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readInBoard(char* boardFile, int *numOfSpaces) {
    FILE *fp = fopen(boardFile, "r");
    char delim = ',';     //Maybe only used for board file parsing
    char *parsedString;   //Maybe only used for board file parsing

    if(fp == NULL) {
        printf("%s", boardFile);
        return;
    }

    //Begin of StrTok Parsing [maybe only used for the board file parsing because of the excess of delim characters]

    fscanf(fp, "Number of Spaces,%d", (numOfSpaces));

    parsedString = strtok(fp, delim); // get parsedString from the stream

    while( parsedString != NULL ) {     // parsing strings through the stream
        parsedString = strtok(NULL, delim);
        parsedString = *parsedString;
        if( parsedString == "Type" || parsedString == "SetId" || parsedString == "IntrasetId" || parsedString =="Name" || parsedString =="PropertyCost" || parsedString =="HouseCost" || parsedString =="Hotel" || parsedString == "Cost" || parsedString == "Rent" || parsedString == "Rent with House" || parsedString =="Rent With Hotel") {

        } else {

        }

    }


}



void readInSpaces(char *boardFile, struct properties spacesOnBoard[], const int numOfSpaces) {
    FILE *fp = fopen(boardFile, "r");

    if(fp == NULL) {
        printf("%s", boardFile);
        return;
    }

    /*
        Type, Set Id, Intraset Id, Name, Property Cost, House Cost, Hotel Cost, Rent, Rent with House, Rent With Hotel

        Property, 0, 0, Asia, 100, 50, 50, 20, 60, 100

     */


    for(int i = 0; i < numOfSpaces; i++) {
        if(i == 0) {
            spacesOnBoard[i].type = "Go";
            fscanf(fp, "Go,%d,%s", &spacesOnBoard[i].setID, spacesOnBoard[i].intraID);
        }

        spacesOnBoard[i].type = "Property";
        fscanf(fp, "Property,%d,%s,%s,%d,%d,%d,%d,%d,%d", &spacesOnBoard[i].setID, spacesOnBoard[i].intraID, spacesOnBoard[i].name, &spacesOnBoard[i].cost,
               &spacesOnBoard[i].houseCost, &spacesOnBoard[i].hotelCost, &spacesOnBoard[i].rent,
               &spacesOnBoard[i].rentWHouse, &spacesOnBoard[i].rentWHotel);

    }
}

struct boardManagement createBoard(int numOfPlayers, int numOfSpaces, struct properties spacesOnBoard[], struct playerManager players[]) {
    struct boardManagement board;

    board.boardSpace[numOfSpaces].occupiedBy[numOfPlayers + (numOfPlayers - 1)];

    for(int i = 0; i < numOfSpaces; i++) {
        board.boardSpace[i].position = i;
        board.boardSpace[i].name = *spacesOnBoard[i].name;
        if(i == 0) {
            board.boardSpace[i].occupied = true;
            for (int j = 0; j < numOfPlayers; j++) {
                board.boardSpace[i].occupiedBy[j] = players->numIdentifier + " ";
            }
        }
    }

    return board;
}

void displayBoard(struct boardManagement board, int numOfPlayers, int numOfSpaces, struct properties spacesOnBoard[], struct playerManager players[]) {
    for(int i = 0; i < numOfSpaces; i++) {

    }
}