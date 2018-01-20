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


void readInSpaces(char *boardFile, struct properties spacesOnBoard[], const int numOfSpaces) {
    FILE *fp = fopen(boardFile, "r");

    if(fp == NULL) {
        printf("%s", boardFile);
        return;
    }

    /*
        Type, Set Id, Intraset Id, Name, Property Cost, House Cost, Hotel Cost, Rent, Rent with House, Rent With Hotel

        Property, 0, 0, Asia, 100, 50, 50, 20, 60, 100

     *//*


    for(int i = 0; i < numOfSpaces; i++) {
        if(i == 0) {
            spacesOnBoard[i].type = "Go";
            fscanf(fp, "Go,%d,%s", &spacesOnBoard[i].setID, spacesOnBoard[i].intraID);
        }

        spacesOnBoard[i].type = "Property";
        fscanf(fp, "Property,%d,%s,%s,%d,%d,%d,%d,%d,%d", &spacesOnBoard[i].setID, spacesOnBoard[i].intraID, spacesOnBoard[i].name, &spacesOnBoard[i].cost,
               &spacesOnBoard[i].houseCost, &spacesOnBoard[i].hotelCost, &spacesOnBoard[i].rent,
               &spacesOnBoard[i].rentWHouse, &spacesOnBoard[i].rentWHotel);

    }
}
*/

int read_board(struct boardManager board, char* BOARD_FILENAME, int *totalNumOfProperties) {
    char storage[10000];
    char c;
    FILE *fp;
    int i = 0, counter = 0;

    fp = fopen(BOARD_FILENAME, "r"); // FIXME - Get the board_file name from command line.

    while (!feof(fp)) {
        fscanf(fp, "%c", &c);
        storage[i] = c;
        i++;
    }

    char *tokens = strtok(storage, ",");
    char *array[10000];
    i = 0;
    while (tokens != NULL) {
        array[i++] = tokens;
        tokens = strtok(NULL, ",");
        counter++;
    }

    int propertyID_forName = 17;
    int propertySetID_forName = 18;

    int arrayPosition_forName = 19;
    int arrayPosition_forPropertyCost = 20;
    int arrayPosition_forRent = 23;

    // Storing total number of properties
    board.space->spaceType.property.inTotal = atoi(array[1]) - 1; // Number of properties without GO.
    *totalNumOfProperties = atoi(array[1]) - 1; // Number of properties without GO.

    board.boardSpace = malloc(numOfSpaces * sizeof(struct boardSpace));

    // Storing GO-Name
    board.space[0].spaceType.GO.name = array[15]; // FIXME - Will the *name pointer store whats in array[15].

    // Storing other values
    for (i = 0; i < *totalNumOfProperties; i++) {
        // Storing names
        board.space[atoi(array[propertyID_forName])].spaceType.property.setID[atoi(array[propertySetID_forName])].name = array[arrayPosition_forName];

        // Storing Property Costs
        board.space[atoi(array[propertyID_forName])].spaceType.property.setID[atoi(array[propertySetID_forName])].cost = atoi(array[arrayPosition_forPropertyCost]);

        // Storing rent
        board.space[atoi(array[propertyID_forName])].spaceType.property.setID[atoi(array[propertySetID_forName])].rent = atoi(array[arrayPosition_forRent]);

        // Increase values inside file
        arrayPosition_forName += 9;
        arrayPosition_forPropertyCost += 9;
        arrayPosition_forRent += 9;

        // Increase values for property ID and setID
        propertyID_forName += 9;
        propertySetID_forName += 9;
    }

    fclose(fp);
    return 0;
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