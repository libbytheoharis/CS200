#include "hp1_program.hpp"

// CS 200
// Libby Wichman
// HW Project: Mars Experiment


/*
MODIFY THIS FILE
*/

#include <iostream>
using namespace std; 

/* Menu Functions **********************************************/

/*
DisplayMenu()
Inputs: None
Outputs: None
This function should just display a simple # list and header, such as:
1. Set mission parameters, 2. View parameters, 3. Run simulation, 4. Quit
*/
void Program::DisplayMenu()
{
	int userSelection = 0;
	
	{	
		cout << "Mars Project" << endl;
		cout << "1. Set Mission Parameters" << endl;
		cout << "2. View Parameters" << endl;
		cout << "3. Run Simulation" << endl;
		cout << "4. Quit" << endl; 
		cin >> userSelection;
	
		switch (userSelection)
		{
			case 1:
				SetParameters();
				break;
			case 2:
				ViewParameters();
				break;
			case 3:
				RunSimulation();
				break;
			case 4:
				cout << "End of Program.\n";
				break;
			default:
				cout << "This is not a valid choice." << endl;
				cout << "Choose again." << endl << endl << endl;
				break;
		}
	} while (userSelection != 4 && userSelection != 5);
}

/*
SetParameters()
Inputs: None
Outputs: None
In this function, we will get the user's input for the following fields:
- food grown per day (int)		- cleanup per person per day (int)
- team name	(string)			- team size (int)
- mission length in days (int)	- starting units of food (int)

Create variables for each of these. Prompt the user for each
of these items with a cout command ("please enter ___:"),
and get their input through cin.

Finally, once those are all entered, you will use the following functions
to set these variables in the simulator:
- SetFoodGrown_PerDay(int)		- SetCleanup_PerPersonPerDay(int)
- SetTeamName(string)			- SetTeamSize(int)
- SetMissionLength(int)			- SetFoodCount(int)
*/
void Program::SetParameters()
{
	int foodGrownPerDay;
	int cleanUpPerPersonPerDay;
	string teamName;
	int teamSize;
	int missionLengthInDays;
	int startingUnitsOfFood;

	cout << endl << "Please enter the food grown per day: ";
	cin >> foodGrownPerDay;
	cout << "Please enter the clean up per person, per day: ";
	cin >> cleanUpPerPersonPerDay;
	cout << "Enter the team name: ";
	cin >> teamName;
	cout << "Please enter the team size: ";
	cin >> teamSize;
	cout << "How many days is your Mission? ";
	cin >> missionLengthInDays;
	cout << "How many units of food are available at the start? ";
	cin >> startingUnitsOfFood;
	cout << "Thank you!" << endl << endl << endl;

	SetFoodGrown_PerDay(foodGrownPerDay);
	SetCleanup_PerPersonPerDay(cleanUpPerPersonPerDay);
	SetTeamName(teamName);
	SetTeamSize(teamSize);
	SetMissionLength(missionLengthInDays);
	SetFoodCount(startingUnitsOfFood);
}

/*
ViewParameters()
Inputs: None
Outputs: None
In this function, you will just display the parameters that were entered
in the SetParameters() function. You can do this by utilizing the "getter"
functions available to the simulation...:
- GetFoodConsumed_PerPersonPerDay()			- GetWasteCreated_PerPersonPerDay()
- GetOxygenCreated_PerDay()					- GetOxygenUsed_PerPersonPerDay()
- GetFoodGrown_PerDay()						- GetCleanup_PerPersonPerDay()
- GetTeamName()								- GetTeamSize()
- GetMissionLength()

All of these functions *return* a value - either ints or strings.
You can cout each of these, like:
cout << GetOxygenUsed_PerPersonPerDay() << endl;

Just display each value, but also make sure to display a label for each.
*/
void Program::ViewParameters()
{
	cout << "Food consumed per person, per day: "
		<< GetFoodConsumed_PerPersonPerDay() << endl;
	cout << "Waste created per person, per day: "
		<< GetWasteCreated_PerPersonPerDay() << endl;
	cout << "Oxygen created per day: "
		<< GetOxygenCreated_PerDay() << endl;
	cout << "Oxygen used per person, per day: "
		<< GetOxygenUsed_PerPersonPerDay() << endl;
	cout << "Food grown per day: "
		<< GetFoodGrown_PerDay() << endl;
	cout << "Clean up completed per person, per day: "
		<< GetCleanup_PerPersonPerDay() << endl;
	cout << "Team name: " << GetTeamName() << endl;
	cout << "Team size: " << GetTeamSize() << endl;
	cout << "Mission length: " << GetMissionLength() << endl;
	cout << "Thank you!" << endl << endl << endl;
}

/*
AdjustFood()
Inputs: None
Outputs: None
This function deals with the following functions:
- GetFoodGrown_PerDay()		- GetFoodConsumed_PerPersonPerDay()		
- GetFoodCount()			- GetTeamSize()

It will calculate the amount of food produced and consumed,
and update the food count.

First, create a temporary local int variable, named something like "foodCount".
Assign it the return value of the GetFoodCount() function.

Then, adjust the food count with the formula:
	new food count = old food count + food grown per day - ( food consumed per person per day * team size )

After the calculation, update the food count using SetFoodCount(int).
*/
void Program::AdjustFood()
{
	int foodCount;

	foodCount = GetFoodCount();
	foodCount = foodCount + GetFoodGrown_PerDay() - (GetFoodConsumed_PerPersonPerDay() * GetTeamSize());
	SetFoodCount(foodCount);
}

/*
AdjustWaste()
Inputs: None
Outputs: None
This function deals with the following functions:
- GetWasteCount()		- GetWasteCreated_PerPersonPerDay()
- GetTeamSize()			- GetCleanup_PerPersonPerDay()

Create a temporary variable and assign it the value of GetWasteCount().

Calculate the new waste count with the formula:
	new waste count = old waste count + (waste created per person per day * team size) - (cleanup per person per day * team size)

After the calculation, update the waste count using SetWasteCount(int).
*/
void Program::AdjustWaste()
{
	int wasteForMission;
	
	wasteForMission = GetWasteCount();
	wasteForMission = wasteForMission + (GetWasteCreated_PerPersonPerDay() * GetTeamSize()) - (GetCleanup_PerPersonPerDay() * GetTeamSize());
	SetWasteCount(wasteForMission);
}

/*
AdjustOxygen()
Inputs: None
Outputs: None
This function deals with the following functions:
- GetOxygenCount()		- GetOxygenCreated_PerDay()
- GetTeamSize()			- GetOxygenUsed_PerPersonPerDay()

Create a temporary variable and assign it the value of GetOxygenCount().

Calculate the new oxygen count with the formula:
	new oxygen count = old oxygen count + oxygen created per day - (oxygen used per person per day * team size)

After the calculation, update the oxygen count using SetOxygenCount(int).
*/
void Program::AdjustOxygen()
{
	int oxygenForMission;
	
	oxygenForMission = GetOxygenCount();
	oxygenForMission = oxygenForMission + GetOxygenCreated_PerDay() - (GetOxygenUsed_PerPersonPerDay() * GetTeamSize());
	SetOxygenCount(oxygenForMission);
}

/*
RunSimulation()
Inputs: None
Outputs: None
The simulation runs through each day, adjusting values to see if
the astronauts can survive for the set amount of days.
Follow the comments below for the steps.
*/
void Program::RunSimulation()
{
	cout << endl << "RUN SIMULATION" << endl;

	// Set up the simulation:
	// * Create an integer variable called day, and initialize it to 1.
	// * Use SetOxygenCount(int) to initialize the oxygen count to 100.
	// * Use SetWasteCount(int) to initialize the waste count to 0.
	// * Create a boolean variable called missionSuccess, and set it to true.

	int day = 1;
	SetOxygenCount(100);
	SetWasteCount(0);
	bool missionSuccess = true;

	// Create a while loop. This will continue looping while
	// the day is less than the mission length (GetMissionLength()),
	// and while missionSuccess is true.
	while (missionSuccess == true)
	{
		// Adjust current supplies via the AdjustFood(), AdjustWaste(), and AdjustOxygen() functions.
		AdjustFood();
		AdjustWaste();
		AdjustOxygen();

		// Display the following values, and make sure to label them as well.
		// e.g., cout << "LABEL: " << values << endl;

		// * The current day
		// * Food grown				GetFoodGrown_PerDay()
		// * Waste cleaned			GetCleanup_PerPersonPerDay()
		// * Oxygen created			GetOxygenCreated_PerDay()
		// * Food consumed			GetFoodConsumed_PerPersonPerDay()
		// * Waste created			GetWasteCreated_PerPersonPerDay
		// * Oxygen consumed		GetOxygenUsed_PerPersonPerDay
		// * Current food count		GetFoodCount()
		// * Current waste count	GetWasteCount()
		// * Current oxygen count	GetOxygenCount()

		cout << "Day: " << day << endl;
		cout << "Food grown: " << GetFoodGrown_PerDay() << endl;
		cout << "Waste cleaned: " << GetCleanup_PerPersonPerDay() << endl;
		cout << "Oxygen created: " << GetOxygenCreated_PerDay() << endl;
		cout << "Food consumed: " << GetFoodConsumed_PerPersonPerDay() << endl;
		cout << "Waste created: " << GetWasteCreated_PerPersonPerDay() << endl; 
		cout << "Oxygen consumed: " << GetOxygenUsed_PerPersonPerDay() << endl;
		cout << "Current food count: " << GetFoodCount() << endl;
		cout << "Current waste count: " << GetWasteCount() << endl;
		cout << "Current oxygen count: " << GetOxygenCount() << endl;

		// Check to see if resources have been depleted.
		// If so, then the mission is a failure.

		// If food count is less than 0, display a message that they ran out of food and set missionSuccess to false.

		if (GetFoodCount() < 0)
		{
			cout << "The astronauts ran out of food. Mission Failure." << endl;
			missionSuccess = false;
		}
		else if (GetWasteCount() > 20)
		{
			cout << "The astronauts have drowned in trash. Mission Failure." << endl;
			missionSuccess = false;
		}
		else if (GetOxygenCount() < 0)
		{
			cout << "The astronauts have run out of air. Mission Failure." << endl;
			missionSuccess = false;
		}
		else
		{
			day++;
		}
	}

	// After the while loop: Display the results.
	// If missionSuccess is true, display "MISSION SUCCESS!"
	// Otherwise, display "MISSION FAILURE!"

	cout << endl << "RESULTS" << endl;
	if (missionSuccess == true)
	{
		cout << "MISSION SUCCESS!" << endl;
	}
	else
	{
		cout << "MISSION FAILURE!" << endl;
	}
}



/* Utility Functions **********************************************/

/*
GetValidInput(int, int)
Inputs: min (int), max (int)
Outputs: int
This function takes in a minimum and maximum value that
can be entered by the user.

First, prompt the user for input with a cout statement.
Create a variable (int) to store their decision,
and get the user's input with cin.

Then, create a while loop that will keep asking the user
to re-enter their selection, WHILE the input is invalid.

Invalid input is if it is < min or > max.

After the while loop (once the input is valid), return
the variable that is storing the user's choice.
*/
int Program::GetValidInput(int min, int max)
{
	// Create an integer variable to store the user's choice
	int userChoice;
	// Output to console: Ask the user to enter a value
	cout << "Please enter a value: ";
	// Get the user's input and store it in your choice variable
	cin >> userChoice;
	// While the input is invalid...
		// Display "invalid input"
		// Get the user's input again, and store it in the same choice variable
	while (userChoice < min || userChoice > max)
	{
		cout << "Invalid input." << endl;
		cout << "Please enter a value: ";
		cin >> userChoice;
	}
	// Return the choice variable after the while loop

	return userChoice; // replace this
}


/*
DO NOT MODIFY BELOW
*/

/* Setter Functions **********************************************/

void Program::SetFoodGrown_PerDay(int value)
{
	foodGrown_PerDay = value;
}

void Program::SetCleanup_PerPersonPerDay(int value)
{
	cleanup_PerPersonPerDay = value;
}

void Program::SetTeamSize(int value)
{
	teamSize = value;
}

void Program::SetMissionLength(int value)
{
	missionLengthInDays = value;
}

void Program::SetTeamName(string value)
{
	teamName = value;
}

void Program::SetFoodCount(int value)
{
	countFood = value;
}

void Program::SetWasteCount(int value)
{
	countWaste = value;
}

void Program::SetOxygenCount(int value)
{
	countOxygen = value;
}


/* Getter Functions **********************************************/

int Program::GetFoodGrown_PerDay()
{
	return foodGrown_PerDay;
}

int Program::GetCleanup_PerPersonPerDay()
{
	return cleanup_PerPersonPerDay;
}

int Program::GetTeamSize()
{
	return teamSize;
}

int Program::GetMissionLength()
{
	return missionLengthInDays;
}

string Program::GetTeamName()
{
	return teamName;
}

int Program::GetFoodConsumed_PerPersonPerDay()
{
	return foodConsumed_PerPersonPerDay;
}

int Program::GetWasteCreated_PerPersonPerDay()
{
	return wasteCreated_PerPersonPerDay;
}

int Program::GetOxygenUsed_PerPersonPerDay()
{
	return oxygenUsed_PerPersonPerDay;
}

int Program::GetOxygenCreated_PerDay()
{
	return oxygenCreated_PerDay;
}

int Program::GetFoodCount()
{
	return countFood;
}

int Program::GetWasteCount()
{
	return countWaste;
}

int Program::GetOxygenCount()
{
	return countOxygen;
}




