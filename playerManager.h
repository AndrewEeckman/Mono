//
// Created by Andrew Eeckman on 1/16/18.
//

#ifndef HOARDING_PLAYERMANAGER_H
#define HOARDING_PLAYERMANAGER_H

#include "boardManager.h"
#include "structs.h"

//struct playerManager createPlayer(int cashAmount, int netWorth, int boardPosition, char* propertiesOwned[], const int NUM_OF_PLACEHOLDERS);

void createPlayers(struct boardManager *board, int *numOfPlayers);

#endif //HOARDING_PLAYERMANAGER_H
