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
    struct boardSpace {
        struct spaceType {
            struct goType {
                char *type;
                int earnings;
                char *name;
            }goType;
            struct propertyType {
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

                bool owned;
                int ownedBy;
            }propertyType;

        }spaceType;

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
