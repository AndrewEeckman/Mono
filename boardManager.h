//
// Created by Andrew Eeckman on 1/12/18.
//

#ifndef HOARDING_BOARDMANAGER_H
#define HOARDING_BOARDMANAGER_H

#include <stdbool.h>
#include "structs.h"


void readInBoard(char* boardFile, int *numOfSpaces);
void readInSpaces(char* boardFile, struct properties spacesOnBoard[], const int numOfSpaces);

struct boardManagement createBoard(int numOfPlayers, int numOfSpaces, struct properties spacesOnBoard[], struct playerManager players[]);
void displayBoard(struct boardManagement board, int numOfPlayers, int numOfSpaces, struct properties spacesOnBoard[], struct playerManager players[]);

#endif //HOARDING_BOARDMANAGER_H
