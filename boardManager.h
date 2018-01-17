//
// Created by Andrew Eeckman on 1/12/18.
//

#ifndef HOARDING_BOARDMANAGER_H
#define HOARDING_BOARDMANAGER_H

#include <stdbool.h>

struct properties {
    char *type;
    int setID;
    int intraID;
    char *name;
    int cost;
    int houseCost;
    int hotelCost;
    int rent;
    int rentWHouse;
    int rentWHotel;
};



void readInBoard(char* boardFile, int *numOfSpaces);
void readInSpaces(char* boardFile, struct properties spacesOnBoard[], const int numOfSpaces);

char** createBoard(int numOfPlayers, int numOfSpaces, struct properties spacesOnBoard[]);
void displayBoard(int numOfPlayers, int numOfSpaces, struct properties spacesOnBoard[]);

#endif //HOARDING_BOARDMANAGER_H
