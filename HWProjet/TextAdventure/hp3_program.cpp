/*
MODIFY THIS FILE
*/

#include "hp3_program.hpp"

#include <iostream>
using namespace std;

// CS 200 Text Adventure
// Libby Wichman 
// HW Project 3

/* Setup() - 	Create the list of locations
*              Allocate needed memory
* */
void Program::Setup()
{
	// This is called automatically when the program begins

	locationList = new Location[6];

	locationList[0].name = "Great Hall";
	locationList[0].description = "A long room with a vaulted ceiling, lined with tattered tapestries.";
	locationList[1].name = "Throne Room";
	locationList[1].description = "Where the mysterious King of Ehdaoli once ruled.";
	locationList[2].name = "Hall of Warriors";
	locationList[2].description = "Full suits of elaborate armor, dusty with age, line a feasting table.";
	locationList[3].name = "Council Chamber";
	locationList[3].description = "Within the hall, a massive round table stands in the middle. Each seat carved with the crests of the old families.";
	locationList[4].name = "Ward of the Ladies";
	locationList[4].description = "Dusty bookshelves, drawing tables and tattered linens remain.";
	locationList[5].name = "The Mystical Lord's Room";
	locationList[5].description = "Scrolls, books, drawings, mechanical devices litter the room.";

	locationList[1].ptrToEast = &locationList[2];
	locationList[2].ptrToWest = &locationList[1];
	locationList[2].ptrToSouth = &locationList[4];
	locationList[3].ptrToSouth = &locationList[5];
	locationList[3].ptrToNorth = &locationList[0];
	locationList[3].ptrToWest = &locationList[2];
	locationList[4].ptrToEast = &locationList[5];
	locationList[4].ptrToNorth = &locationList[2];
	locationList[5].ptrToWest = &locationList[4];
	locationList[5].ptrToNorth = &locationList[3];

	ptrCurrentLocation = &locationList[1];
	ptrEndLocation = &locationList[0];


}



/* Cleanup() - 	Clean up memory allocated
* */
void Program::Cleanup()
{
	// This is called automatically when the program ends

	if (locationList == nullptr)
	{
		;
	}
	else
	{
		delete[] locationList;
	}

}



/* Main() - Main program loop
* */
void Program::Main()
{
	bool done = false;
	while (!done)
	{
		DisplayCurrentLocation();

		if (ptrCurrentLocation == ptrEndLocation)
		{
			cout << "You have reached your destination!";
			break;
		}

		string playerSelection;
		playerSelection = GetUserInput();

		if (playerSelection == "n" && ptrCurrentLocation->ptrToNorth != nullptr)
		{
			ptrCurrentLocation = ptrCurrentLocation->ptrToNorth;
		}
		else if (playerSelection == "s" && ptrCurrentLocation->ptrToSouth != nullptr)
		{
			ptrCurrentLocation = ptrCurrentLocation->ptrToSouth;
		}
		else if (playerSelection == "e" && ptrCurrentLocation->ptrToEast != nullptr)
		{
			ptrCurrentLocation = ptrCurrentLocation->ptrToEast;
		}
		else if (playerSelection == "w" && ptrCurrentLocation->ptrToWest != nullptr)
		{
			ptrCurrentLocation = ptrCurrentLocation->ptrToWest;
		}
		else if (playerSelection == "q")
		{
			done = true;
		}
		else
		{
			cout << "invalid choice.";
		}

	}
	cout << endl << "GOOD BYE!" << endl;
}



/* DisplayCurrentLocation() - Use the current location
*              pointer to display the location's name
*              and description, as well as which
*              directions the player can move next.
* */
void Program::DisplayCurrentLocation()
{
	cout << ptrCurrentLocation->name << endl;
	cout << ptrCurrentLocation->description << endl;

	string userDirection = "\t ";

	if (ptrCurrentLocation->ptrToNorth != nullptr)
	{
		userDirection += "\t* north";
	}
	if (ptrCurrentLocation->ptrToSouth != nullptr)
	{
		userDirection += "\t* south";
	}
	if (ptrCurrentLocation->ptrToEast != nullptr)
	{
		userDirection += "\t* east";
	}
	if (ptrCurrentLocation->ptrToWest != nullptr)
	{
		userDirection += "\t* west";
	}

	cout << "You can move: " << userDirection << endl;

}



/* GetUserInput() - Display the list of options to the
*                  user, then get their input and return
*                  their choice.
* */
string Program::GetUserInput()
{
	string userSelection;
	cout << "Options: (n)orth, (s)outh, (e)ast, (w)est, (q)uit" << endl;
	cin >> userSelection;

	return userSelection;
}



/************************************/
/* Don't modify *********************/
/************************************/

Program::Program()
{
	locationList = nullptr;
	ptrCurrentLocation = nullptr;
	Setup();
}

Program::~Program()
{
	Cleanup();
}
