//
// Created by Andrew Eeckman on 1/16/18.
//

#ifndef HOARDING_PLAYERMANAGER_H
#define HOARDING_PLAYERMANAGER_H

#include "boardManager.h"
#include "structs.h"

void getMove(struct boardManager board, int numOfPlayers, int numOfSpaces, int player);
void movePlayer(struct boardManager board, int player, int numOfSpaces);

#endif //HOARDING_PLAYERMANAGER_H
