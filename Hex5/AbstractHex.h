#ifndef ABSTRACTHEX_H_
#define ABSTRACTHEX_H_

#include <iostream>
#include "Location.h"
#include <list>

using namespace std;

enum class CellState: char										//enum for cellstate
{
    nope = ' '
    , user1 = 'o'
    , user2 = 'x'
    , dot = '.'
};

class AbstractHex
{
public:
    AbstractHex(string user1, string user2);
    virtual void print();
    virtual bool readFromFile(string fileName);
    virtual bool writeToFile(string fileName);
    virtual void reset() = 0;
    virtual void setSize(int size) = 0; //throw exception 5 ile 32 arasý;
    virtual void play() = 0;
    virtual void play(Location location) = 0;
    virtual bool isEnd();
    virtual CellState& operator()(int i,int j) = 0;
    Location lastMove();    // throw exception("There is no last move.") = 0;
    int numberOfMoves();

protected:
    void clearScreen();
    short playerTurn;
    Location lastLocation;
    int boardSize;
    string username1, username2;
    int numberOfSteps;
    bool isEnded;
    virtual bool pTest(Location current, std::list<Location>& scannedLocations);		                           	// for testing recursively if current user is completed the path from the given location;
    virtual bool isUserLocationOwner(const Location myLocation);
    virtual bool isLocationCorrect(const Location myLocation) const;												// check if given Location is correct (if its on the matrix or not)
    virtual list<Location> findConnections(const Location myLocation) const;		                            	// finds the Locations around a Location (neighbours)

};

#endif