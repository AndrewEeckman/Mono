//
// Created by Andrew Eeckman on 1/16/18.
//

#ifndef HOARDING_PLAYERMANAGER_H
#define HOARDING_PLAYERMANAGER_H

#include "boardManager.h"
#include "structs.h"

<<<<<<< HEAD
void getMove(struct boardManager board, struct rulesProperties rules, int numOfPlayers, int numOfSpaces, int player);
void movePlayer(struct boardManager board, struct rulesProperties rules, int player, int numOfSpaces);
void inspectPlayer(struct boardManager board, struct rulesProperties rules, int numOfPlayers, int numOfSpaces, int player);
void leaveGame(struct boardManager board, struct rulesProperties rules, int numOfPlayers, int numOfSpaces, int player);
=======
void getMove(struct boardManager board, int numOfPlayers, int numOfSpaces, int player, int ** randNum);
void movePlayer(struct boardManager board, int player, int numOfSpaces, int ** randNum);
void readInRand(char * argv, int ** randNum);
void inspectPlayer(struct boardManager board, int numOfPlayers, int numOfSpaces, int player);
>>>>>>> 9c1681dc78e7f410e4c99fb5c7e027d0f4203c7d

#endif //HOARDING_PLAYERMANAGER_H