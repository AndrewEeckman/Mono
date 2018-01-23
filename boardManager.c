//
// Created by Andrew Eeckman on 1/12/18.
//

#include "boardManager.h"
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FIXME: REWORK FILE

void readInBoard(struct boardManager *board, char* fileName, int *numOfProperties, int *numOfSpaces) {
    // Array of chars large enough to take in the entirety of the file
    char charStorage[10000];

    // Variables for file reading
    FILE *fp;
    int i = 0;

    // Attempt to open file
    fp = fopen(fileName, "r");

    if(fp == NULL) {
        printf("Failed to open file: %s", fileName);
        return;
    }

    // If file is opened, scan through the file until the end is detected
    while (!feof(fp)) {
        fscanf(fp, "%c", &charStorage[i]);
        i++;
    }

    //Declare secondary array of chars to take in file contents
    char *arrayOfFile[10000];
    char *tokenScanned = strtok(charStorage, ",");
    i = 0;

    //Cut up file into tokens
    while (tokenScanned != NULL) {
        arrayOfFile[i++] = tokenScanned;
        tokenScanned = strtok(NULL, ",");
    }

    // Define initial location of all necessary variables in struct boardSpace
    //int typeIDPos = 7;
    int setIDPos = 8;
    int intraSetIDPos = 9;
    int namePos = 10;
    int costPos = 11;
    int houseCostPos = 12;
    int hotelCostPos = 13;
    int rentPos = 14;
    int rentWHousePos = 15;
    int rentWHotelPos = 16;

    // Find number of spaces and properties existing within the file
    *numOfProperties = atoi(arrayOfFile[1]) - 1; // Number of properties without GO.
    *numOfSpaces = *numOfProperties + 1;

    // Allocate space for the board based on the number of spaces and properties within the board file
    (*board).boardSpace = malloc(*numOfSpaces * sizeof(struct boardSpace));

    // Storing
    for (i = 0; i <= *numOfProperties; i++) {

        if(i == 0) {
            (*board).boardSpace[0].goType.name = arrayOfFile[15];
            (*board).boardSpace[0].goType.earnings = atoi(arrayOfFile[14]);
        } else {
            (*board).boardSpace[i].propertyType.setID = atoi(arrayOfFile[setIDPos]);
            (*board).boardSpace[i].propertyType.intraID = atoi(arrayOfFile[intraSetIDPos]);
            (*board).boardSpace[i].propertyType.name = arrayOfFile[namePos];
            (*board).boardSpace[i].propertyType.cost = atoi(arrayOfFile[costPos]);
            (*board).boardSpace[i].propertyType.houseCost = atoi(arrayOfFile[houseCostPos]);      //NOT USING / WORKING
            (*board).boardSpace[i].propertyType.hotelCost = atoi(arrayOfFile[hotelCostPos]);      //NOT USING / WORKING
            (*board).boardSpace[i].propertyType.rent = atoi(arrayOfFile[rentPos]);
            (*board).boardSpace[i].propertyType.rentWHouse = atoi(arrayOfFile[rentWHousePos]);    //NOT USING / WORKING
            (*board).boardSpace[i].propertyType.rentWHotel = atoi(arrayOfFile[rentWHotelPos]);    //NOT USING / WORKING

            (*board).boardSpace[i].propertyType.owned = false;
            (*board).boardSpace[i].propertyType.ownedBy = -1;
        }
        // Increase values inside file
        namePos += 9;
        costPos += 9;
        rentPos += 9;

        // Increase values for property ID and setID
        setIDPos += 9;
        intraSetIDPos += 9;
    }

    fclose(fp);
}

void displayBoard(struct boardManager board, int numOfSpaces, int numOfPlayers) {
    for(int i = 0; i < numOfSpaces; i++) {
        printf("%d ", i);
        if(i == 0){
            printf("| %s |\t\t\t", board.boardSpace[i].goType.name);
        } else {
            printf("| %s |\t\t", board.boardSpace[i].propertyType.name);
        }


        for(int j = 0; j < numOfPlayers; j++) {
            if (i == board.player[j].boardPosition && board.player[j].inGame == true) {
                printf("%d ", board.player[j].numIdentifier);
            }
        }
        printf("\n");
    }
}
