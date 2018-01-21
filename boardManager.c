//
// Created by Andrew Eeckman on 1/12/18.
//

#include "boardManager.h"
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readInBoard(struct boardManager *board, char* fileName, int *numOfProperties, int *numOfSpaces) {
    char charStorage[10000];
    char characterPlaceholder;
    FILE *fp;
    int i = 0;
    int j = 0;

    fp = fopen(fileName, "r");

    while (!feof(fp)) {
        fscanf(fp, "%c", &characterPlaceholder);
        charStorage[i] = characterPlaceholder;
        i++;
    }

    char *tokenScanned = strtok(charStorage, ",");
    char *arrayOfFile[10000];
    i = 0;

    while (tokenScanned != NULL) {
        arrayOfFile[i++] = tokenScanned;
        tokenScanned = strtok(NULL, ",");
        j++;
    }

    int setIDPos = 8;
    int intraSetIDPos = 9;

    int namePos = 10;
    int costPos = 11;
    int houseCostPos = 12;
    int hotelCostPos = 13;
    int rentPos = 14;
    int rentWHousePos = 15;
    int rentWHotelPos = 16;

    // Storing total number of properties
    //*numOfProperties = atoi(array[1]) - 1; // Number of properties without GO.
    *numOfProperties = atoi(arrayOfFile[1]) - 1; // Number of properties without GO.
    *numOfSpaces = *numOfProperties + 1;

    (*board).boardSpace = malloc(*numOfSpaces * sizeof(struct boardSpace));

    // Storing GO-Name
     // FIXME - Will the *name pointer store whats in array[15].

    // Storing other values
    for (i = 0; i <= *numOfProperties; i++) {
        // Storing names

        if(i == 0) {
            (*board).boardSpace[0].spaceType.goType.name = arrayOfFile[15];
            (*board).boardSpace[0].spaceType.goType.earnings = atoi(arrayOfFile[14]);
        } else {
            (*board).boardSpace[i].spaceType.propertyType.setID = atoi(arrayOfFile[setIDPos]);
            (*board).boardSpace[i].spaceType.propertyType.intraID = atoi(arrayOfFile[intraSetIDPos]);
            (*board).boardSpace[i].spaceType.propertyType.name = arrayOfFile[namePos];
            (*board).boardSpace[i].spaceType.propertyType.cost = atoi(arrayOfFile[costPos]);
            (*board).boardSpace[i].spaceType.propertyType.houseCost = atoi(arrayOfFile[houseCostPos]);      //NOT USING / WORKING
            (*board).boardSpace[i].spaceType.propertyType.hotelCost = atoi(arrayOfFile[hotelCostPos]);      //NOT USING / WORKING
            (*board).boardSpace[i].spaceType.propertyType.rent = atoi(arrayOfFile[rentPos]);
            (*board).boardSpace[i].spaceType.propertyType.rentWHouse = atoi(arrayOfFile[rentWHousePos]);    //NOT USING / WORKING
            (*board).boardSpace[i].spaceType.propertyType.rentWHotel = atoi(arrayOfFile[rentWHotelPos]);    //NOT USING / WORKING

            (*board).boardSpace[i].spaceType.propertyType.owned = false;
            (*board).boardSpace[i].spaceType.propertyType.ownedBy = NULL;
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
            printf("| %s |\t\t\t", board.boardSpace[i].spaceType.goType.name);
        } else {
            printf("| %s |\t\t", board.boardSpace[i].spaceType.propertyType.name);
        }


        for(int j = 0; j < numOfPlayers; j++) {
            if (i == board.player[j].boardPosition && board.player[j].inGame == true) {
                printf("%d ", board.player[j].numIdentifier);
            }
        }
        printf("\n");
    }
}