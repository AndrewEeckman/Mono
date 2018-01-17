//
// Created by Andrew Eeckman on 1/12/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ruleManager.h"

void readInRules(char *argv, struct rulesProperties *rules) {
    FILE *fp;

    fp = fopen(argv, "r");

    if(fp == NULL) {
        printf("Unable to open file: %s", argv);
        exit(0);
    }
    
    fscanf(fp, "Starting Cash: %d", &rules->startingCash);

    fscanf(fp, "Turn Limit (-1 for no turn limit): %d", &rules->turnLimit);

    fscanf(fp, "Number of Players Left To End Game: %d", &rules->numOfPlayerToEndGame);

    fscanf(fp, "Property Set Multiplier: %d", &rules->propertySetMultiplier);

    fscanf(fp, "Number of Houses Before Hotels: %d", &rules->numHousesBeforeHotels);

    fscanf(fp, "Must Build Houses Evenly: %s", rules->buildHousesEvenly);

    fscanf(fp, "Put Money In Free Parking: %s", rules->putMoneyInFreeParking);

    fscanf(fp, "Auction Properties: %s", rules->auctionProperties);

    fscanf(fp, "Salary Multiplier For Landing On Go: %d", &rules->salMultiLandingOnGo);
}