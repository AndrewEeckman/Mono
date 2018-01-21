//
// Created by Andrew Eeckman on 1/12/18.
//

#ifndef HOARDING_BOARDMANAGER_H
#define HOARDING_BOARDMANAGER_H

#include <stdbool.h>
#include "structs.h"

void readInBoard(char* boardFile, int *numOfSpaces);

void readInSpaces(char* boardFile, const int numOfSpaces);


void displayBoard(struct boardManager board, int numOfSpaces, int numOfPlayers);
void readInBoard(struct boardManager *board, char* fileName, int *numOfProperties, int *numOfSpaces);

#endif //HOARDING_BOARDMANAGER_H
