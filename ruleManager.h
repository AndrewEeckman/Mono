//
// Created by Andrew Eeckman on 1/12/18.
//

#ifndef HOARDING_RULEMANAGER_H
#define HOARDING_RULEMANAGER_H

#include <stdbool.h>
#include "structs.h"


void readInRules(char *argv, struct rulesProperties *rules);

bool changeToBool(char* string);

bool gameIsOver(struct boardManager board, int turnLimit, int currentTurnNumber, int numPlayersToWin, int numOfPlayers, int numOfPlayersLeft);

void whoWins(struct boardManager board, struct rulesProperties rules, int numPlayers, int numOfPlayersLeft, int numOfProperties);

#endif //HOARDING_RULEMANAGER_H
