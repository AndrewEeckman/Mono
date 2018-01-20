//
// Created by Andrew Eeckman on 1/17/18.
//

#ifndef HOARDING_STRUCTS_H
#define HOARDING_STRUCTS_H

struct rulesProperties {
    int startingCash;
    int turnLimit;
    int numOfPlayerToEndGame;
    int propertySetMultiplier;
    int numHousesBeforeHotels;
    bool buildHousesEvenly;         //NOT USING
    bool putMoneyInFreeParking;     //NOT USING
    bool auctionProperties;         //NOT USING
    int salMultiLandingOnGo;
};

struct properties {
    char *type;
    int setID;
    int intraID;
    char *name;
    int cost;
    int houseCost;
    int hotelCost;
    int rent;
    int rentWHouse;
    int rentWHotel;
};

struct boardSpace {
    int position;
    struct properties placesOnBoard;
    bool occupied;
    char *occupiedBy;
};

struct playerManager {
    int numIdentifier;
    int cashAmount;
    int netWorth;
    int boardPosition; //FIXME: MAY NOT BE USED OR ACCESSED LIKE EVER
    char *propertiesOwned[];
};



#endif //HOARDING_STRUCTS_H
