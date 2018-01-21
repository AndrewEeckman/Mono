//
// Created by Andrew Eeckman on 1/12/18.
//

#ifndef HOARDING_BOARDMANAGER_H
#define HOARDING_BOARDMANAGER_H

#include <stdbool.h>
#include "structs.h"

<<<<<<< HEAD
void readInBoard(struct boardManager *board, char* fileName, int *numOfProperties, int *numOfSpaces);
void displayBoard(struct boardManager board, int numOfSpaces, int numOfPlayers);
=======
void readInBoard(char* boardFile, int *numOfSpaces);

void readInSpaces(char* boardFile, const int numOfSpaces);


void displayBoard(struct boardManager board, int numOfSpaces, int numOfPlayers);
//void readInBoard(struct boardManager *board, char* fileName, int *numOfProperties, int *numOfSpaces);
>>>>>>> 9c1681dc78e7f410e4c99fb5c7e027d0f4203c7d

#endif //HOARDING_BOARDMANAGER_H
