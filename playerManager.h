//
// Created by Andrew Eeckman on 1/16/18.
//

#ifndef HOARDING_PLAYERMANAGER_H
#define HOARDING_PLAYERMANAGER_H

#include "boardManager.h"
#include "structs.h"

void getMove(struct boardManager board, struct rulesProperties rules, int numOfPlayers, int numOfSpaces, int player, int ** randNum, int *numOfPlayersLeft, int * numInRandArray);
void movePlayer(struct boardManager board, struct rulesProperties rules, int player, int numOfSpaces, int ** randNum, int *numOfPlayersLeft, int * numInRandArray);
void inspectPlayer(struct boardManager board, struct rulesProperties rules, int numOfPlayers, int numOfSpaces, int player);
void leaveGame(struct boardManager board, struct rulesProperties rules, int numOfSpaces, int player, int *numOfPlayersLeft);
int readInRand(char * argv, int ** randNum);

#endif //HOARDING_PLAYERMANAGER_H