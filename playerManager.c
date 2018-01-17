//
// Created by Andrew Eeckman on 1/16/18.
//

#include "playerManager.h"

struct playerManager createPlayer(int cashAmount, int netWorth, int boardPosition, char* propertiesOwned[], const int NUM_OF_PLACEHOLDERS) {
    struct playerManager player;
    player.cashAmount = cashAmount;
    player.netWorth = netWorth;
    player.boardPosition = boardPosition;

    for(int i = 0; i < NUM_OF_PLACEHOLDERS; i++) {
        propertiesOwned[i] = i + ": ";
    }

    return player;
}