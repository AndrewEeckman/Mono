//
// Created by Andrew Eeckman on 1/12/18.
//

#include <stdio.h>
#include <string.h>
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


    //Begin of StrTok Examople
        char str[80] = "This is - www.tutorialspoint.com - website";
        const char s[2] = "-";
        char *token;

        /* get the first token */
        token = strtok(str, s);

        /* walk through other tokens */
        while( token != NULL ) {
            printf( " %s\n", token );

            token = strtok(NULL, s);
        }

        return(0);
    //End of StrTok

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