//
// Created by Andrew Eeckman on 1/12/18.
//

#include "boardManager.h"
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readInBoard(char* boardFile, int *numOfSpaces) {
    FILE *fp = fopen(boardFile, "r");
    const char delim[2] = ",";     //Maybe only used for board file parsing
    char *parsedString;   //Maybe only used for board file parsing

    if(fp == NULL) {
        printf("%s", boardFile);
        return;
    }

    char *boardString = fgets(boardString, EOF, fp);    //used to convert the FILE* type to a char* for strtok compatability
    fscanf(boardString, "Number of Spaces, %d", (numOfSpaces)); //Gets the first string and data out of the way

    //Begin of StrTok Parsing [maybe only used for the board file parsing because of the excess of delim characters]
    parsedString = strtok(boardString, delim); // get parsedString from the stream
    while( parsedString != NULL ) {     // parsing 7strings through the stream
        parsedString = strtok(NULL, delim);
        if( parsedString == "Type" || parsedString == "SetId" || parsedString == "IntrasetId" || parsedString =="Name" || parsedString =="PropertyCost" || parsedString =="HouseCost" || parsedString =="Hotel" || parsedString == "Cost" || parsedString == "Rent" || parsedString == "Rent with House" || parsedString =="Rent With Hotel") {
            //F'IN NOTHIN XD
            break;
        } else if (parsedString == "Go") {

        } else if (parsedString == "Property") {

        }

    }
}

void displayBoard(struct boardManager board, int numOfSpaces, int numOfPlayers) {
    for(int i = 0; i < numOfSpaces; i++) {
        printf("%d ", i);
        if(i == 0){
            printf("| %s |\t\t\t", board.boardSpace[i].spaceType.goType.intraID);
        } else {
            printf("| %s |\t\t", board.boardSpace[i].spaceType.propertyType.name);
        }


        for(int j = 0; j < numOfPlayers; j++) {
            if (i == board.player[j].boardPosition) {
                printf("%d ", board.player[j].numIdentifier);
            }
        }
        printf("\n");
    }
}