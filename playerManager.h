//
// Created by Andrew Eeckman on 1/16/18.
//

#ifndef HOARDING_PLAYERMANAGER_H
#define HOARDING_PLAYERMANAGER_H

#include "boardManager.h"

struct playerManager {
    int cashAmount;
    int netWorth;
    int boardPosition; //FIXME: MAY NOT BE USED OR ACCESSED LIKE EVER
    char *propertiesOwned[];
};

struct playerManager createPlayer(int cashAmount, int netWorth, int boardPosition, char* propertiesOwned[], const int NUM_OF_PLACEHOLDERS);

#endif //HOARDING_PLAYERMANAGER_H
