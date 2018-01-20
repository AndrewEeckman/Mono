//
// Created by Andrew Eeckman on 1/12/18.
//

#ifndef HOARDING_BOARDMANAGER_H
#define HOARDING_BOARDMANAGER_H

#include <stdbool.h>
#include "structs.h"


void readInBoard(char* boardFile, int *numOfSpaces);
void readInSpaces(char* boardFile, struct properties spacesOnBoard[], const int numOfSpaces);

struct boardSpace* createBoard(int numOfPlayers, int numOfSpaces, struct properties spacesOnBoard[], struct playerManager players[]);
void displayBoard(struct boardSpace board[], int numOfSpaces);

#endif //HOARDING_BOARDMANAGER_H
