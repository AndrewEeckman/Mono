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




struct boardManager {
    struct boardSpace { //array

        struct goType {
            char *type;         //NOT USING
            int earnings;
            char *name;
        }goType;

        struct propertyType {
            char *type;         //NOT USING
            int setID;
            int intraID;        //NOT USING
            char *name;
            int cost;
            int houseCost;      //NOT USING
            int hotelCost;      //NOT USING
            int rent;
            int rentWHouse;     //NOT USING
            int rentWHotel;     //NOT USING

            bool owned;
            int ownedBy;
        }propertyType;

    }*boardSpace;

    struct player {
        int numIdentifier;
        int cashAmount;
        int netWorth;
        int boardPosition;
        char **propertySlots;

        bool inGame;

    }*player;
}boardManager;


#endif //HOARDING_STRUCTS_H
