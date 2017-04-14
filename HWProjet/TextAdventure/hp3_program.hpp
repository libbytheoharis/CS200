/*
DON'T MODIFY THIS FILE
*/

#ifndef _PROGRAM_HPP	// Don't allow duplicates
#define _PROGRAM_HPP	// Don't allow duplicates

#include "hp3_location.hpp"

#include <iostream>
#include <string>
using namespace std;

class Program
{
public:
    Program();
    ~Program();

    void Main();

    void Setup();
    void Cleanup();

    void DisplayCurrentLocation();
    string GetUserInput();


private:
    Location* ptrCurrentLocation;
    Location* ptrEndLocation;
    Location* locationList;
};

#endif
