//
// Created by Andrew Eeckman on 1/12/18.
//

#include "boardManager.h"
#include <stdio.h>
#include <stdlib.h>

void readInBoard(char* boardFile, int *numOfSpaces) {
    FILE *fp = fopen(boardFile, "r");

    if(fp == NULL) {
        printf("%s", boardFile);
        return;
    }

    fscanf(fp, "Number of Spaces,%d",&(*numOfSpaces));
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

struct boardSpace* createBoard(int numOfPlayers, int numOfSpaces, struct properties spacesOnBoard[], struct playerManager players[]) {

    struct boardSpace board[numOfSpaces];

    for(int i = 0; i < numOfSpaces; i++) {
        board[i].position = i;
        board[i].placesOnBoard = spacesOnBoard[i];

        if(i == 0) {
            board[i].occupied = true;
            board[i].occupiedBy = "0, 1, 2"; //FIXME: ADD CHARACTER SLOTS
        } else {
            board[i].occupied = false;
            board[i].occupiedBy = "       "; //FIXME: ADD CHARACTER SLOTS
        }
    }

    return board;
}

void displayBoard(struct boardSpace board[], int numOfSpaces) {
    for(int i = 0; i < numOfSpaces; i++) {
        printf("%d\n ", board[i].position);
        printf("| %s | \t", board[i].placesOnBoard.name);
        printf("%s\n", board[i].occupiedBy);
    }
}