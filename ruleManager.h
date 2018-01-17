//
// Created by Andrew Eeckman on 1/12/18.
//

#ifndef HOARDING_RULEMANAGER_H
#define HOARDING_RULEMANAGER_H

#include <stdbool.h>

struct rulesProperties {
    int startingCash;
    int turnLimit;
    int numOfPlayerToEndGame;
    int propertySetMultiplier;
    int numHousesBeforeHotels;
    bool buildHousesEvenly;
    bool putMoneyInFreeParking;
    bool auctionProperties;
    int salMultiLandingOnGo;
};

void readInRules(char *argv, struct rulesProperties *rules);

#endif //HOARDING_RULEMANAGER_H
