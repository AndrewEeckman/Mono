//
// Created by Andrew Eeckman on 1/12/18.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "struct.h"
#include "ruleManager.h"

void readInRules(char *argv, struct rulesProperties *rules) {
    //Creates the file variable for containing stream and the declaring the delim character and creating the temp string
    FILE *fp;

    //opens the file and sets it to the stream
    fp = fopen(argv, "r");
    //Checks to see if file opening was SUCCess and andrew is a hoe
    if(fp == NULL) {
        printf("Unable to open file: %s", argv);
        exit(0);
    }

    char tempString[100] = "Yes";

    fscanf(fp, "Starting Cash: %d", &rules->startingCash);

    fscanf(fp, "Turn Limit (-1 for no turn limit): %d", &rules->turnLimit);

    fscanf(fp, "Number of Players Left To End Game: %d", &rules->numOfPlayerToEndGame);

    fscanf(fp, "Property Set Multiplier: %d", &rules->propertySetMultiplier);

    fscanf(fp, "Number of Houses Before Hotels: %d", &rules->numHousesBeforeHotels);

    fscanf(fp, "Must Build Houses Evenly: %s", tempString);

    rules->buildHousesEvenly =  changeToBool(tempString);

    fscanf(fp, "Put Money In Free Parking: %s", tempString);

    rules->putMoneyInFreeParking = changeToBool(tempString);

    fscanf(fp, "Auction Properties: %s", tempString);

    rules->auctionProperties = changeToBool(tempString);

    fscanf(fp, "Salary Multiplier For Landing On Go: %d", &rules->salMultiLandingOnGo);


}

bool changeToBool(char * string){
    if (tolower(*string) == 'yes') {
        return true;
    }
    else if (tolower(*string) == 'no') {
        return false;
    }
    return false;
}