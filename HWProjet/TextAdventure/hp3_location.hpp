/*
DON'T MODIFY THIS FILE
*/

#ifndef _LOCATION_HPP
#define _LOCATION_HPP

#include <iostream>
#include <string>
using namespace std;

class Location
{
    public:
    Location()
    {
        ptrToNorth =
            ptrToSouth =
            ptrToEast =
            ptrToWest =
            nullptr;
    }

    string name;
    string description;

    Location* ptrToNorth;
    Location* ptrToSouth;
    Location* ptrToEast;
    Location* ptrToWest;
};

#endif
