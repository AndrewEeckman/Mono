//
// Created by Andrew Eeckman on 1/12/18.
//

#include "boardManager.h"
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readInBoard(struct boardManager *board, char* fileName, int *numOfProperties, int *numOfSpaces) {

    FILE *fp;

    // Attempt to open file
    fp = fopen(fileName, "r");

    if(fp == NULL) {
        printf("Failed to open file: %s", fileName);
        return;
    }

    // Array of chars large enough to take in the entirety of the file
    char fileCharacters[10000];

    int i = 0;

    // If file is opened, scan through the file until the end is detected
    while (!feof(fp)) {
        fscanf(fp, "%c", &fileCharacters[i]);
        i++;
    }

    i = 0;

    //Declare secondary array of chars to take in file contents
    char *fileConverted[10000];
    char *tokenScanned = strtok(fileCharacters, ",");

    i = 0;

    //Cut up file into tokens
    while (tokenScanned != NULL) {
        fileConverted[i++] = tokenScanned;
        tokenScanned = strtok(NULL, ",");
    }

    i = 0;

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

    int nextSpaceNum = 9;

    // Find number of spaces and properties existing within the file
    *numOfProperties = atoi(fileConverted[1]) - 1; // Number of properties without GO.
    *numOfSpaces = *numOfProperties + 1;

    // Allocate space for the board based on the number of spaces and properties within the board file
    (*board).boardSpace = malloc(*numOfSpaces * sizeof(struct boardSpace));

    // Storing
    while(i <= *numOfProperties) {

        if(i == 0) {
            // Reading Values for the Go Space
            (*board).boardSpace[0].goType.name = fileConverted[15];
            (*board).boardSpace[0].goType.earnings = atoi(fileConverted[14]);
        } else {
            // Reading Values for Property Spaces
            // Value reading for ID Sets
            (*board).boardSpace[i].propertyType.setID = atoi(fileConverted[setIDPos]);
            (*board).boardSpace[i].propertyType.intraID = atoi(fileConverted[intraSetIDPos]); // FIXME: CONVERT LATER TO ARRAY

            // Property Characteristics (Unique)
            (*board).boardSpace[i].propertyType.name = fileConverted[namePos];
            (*board).boardSpace[i].propertyType.cost = atoi(fileConverted[costPos]);
            (*board).boardSpace[i].propertyType.houseCost = atoi(fileConverted[houseCostPos]);      //NOT USING / WORKING
            (*board).boardSpace[i].propertyType.hotelCost = atoi(fileConverted[hotelCostPos]);      //NOT USING / WORKING
            (*board).boardSpace[i].propertyType.rent = atoi(fileConverted[rentPos]);
            (*board).boardSpace[i].propertyType.rentWHouse = atoi(fileConverted[rentWHousePos]);    //NOT USING / WORKING
            (*board).boardSpace[i].propertyType.rentWHotel = atoi(fileConverted[rentWHotelPos]);    //NOT USING / WORKING

            // Property Owned Characteristics
            (*board).boardSpace[i].propertyType.owned = false; // FIXME: TRY TO TRANSFER TO PLAYER STRUCT LATER
            (*board).boardSpace[i].propertyType.ownedBy = -1; //(int)NULL
        }

        // Increase values for next space
        //type += nextSpaceNum
        setIDPos += nextSpaceNum;
        intraSetIDPos += nextSpaceNum;
        namePos += nextSpaceNum;
        costPos += nextSpaceNum;
        houseCostPos += nextSpaceNum;
        hotelCostPos += nextSpaceNum;
        rentPos += nextSpaceNum;
        rentWHousePos += nextSpaceNum;
        rentWHotelPos += nextSpaceNum;

        i++;
    }

    //Close File
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
