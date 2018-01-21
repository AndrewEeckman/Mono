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

void readInRules(char * argv, struct rulesProperties *rules) {
    //Creates the file variable for containing stream and the declaring the delim character and creating the temp string
    FILE *fp;

    //opens the file and sets it to the stream
    fp = fopen(argv, "r");

    //Checks to see if file opening was SUCCess and andrew is a hoe
    if(fp == NULL) {
        printf("Unable to open file: %s", argv);
        exit(0);
    }

    char tempString[100];

    fscanf(fp, "Starting Cash: %d\n", &rules->startingCash);

    fscanf(fp, "Turn Limit (-1 for no turn limit): %d\n", &rules->turnLimit);

    fscanf(fp, "Number of Players Left To End Game: %d\n", &rules->numOfPlayerToEndGame);

    fscanf(fp, "Property Set Multiplier: %d\n", &rules->propertySetMultiplier);

    fscanf(fp, "Number of Houses Before Hotels: %d\n", &rules->numHousesBeforeHotels);

    fscanf(fp, "Must Build Houses Evenly: %s\n", tempString);

    rules->buildHousesEvenly =  changeToBool(tempString);

    fscanf(fp, "Put Money In Free Parking: %s\n", tempString);

    rules->putMoneyInFreeParking = changeToBool(tempString);

    fscanf(fp, "Auction Properties: %s\n", tempString);

    rules->auctionProperties = changeToBool(tempString);

    fscanf(fp, "Salary Multiplier For Landing On Go: %d\n", &rules->salMultiLandingOnGo);

    fclose(fp);
}

bool changeToBool(char * string){
    if (strcmp((string), "Yes") == 0 ) {
        return true;
    }
    else if (strcmp(string, "No") == 0) {
        return false;
    }
    return false;
}
