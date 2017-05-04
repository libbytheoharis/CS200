/*
MODIFY THIS FILE
*/

#include "hp4_program.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


//! Initializes the program state.
/**
    - Seed the random number generator:       
    - Set the two pointer variables to nullptr; m_locationList and m_team.
    - Set the m_week variable to 0.
    - Call the Setup() function.
*/
Program::Program()
{
	srand(time(NULL));
	m_locationList = nullptr;
	m_team = nullptr;
	m_week = 0;

	Setup();
}

//! Cleans up the program.
/**
    - Call the Cleanup() function.
*/
Program::~Program()
{
	Cleanup();
}

//! Calls functions needed for program setup, and then calls Main().
/**
    - Call SetupDynamicArrays()
    - Call LoadLocations()
    - Call LoadPeople()
    - Call Main()


*/
void Program::Setup()
{
	SetupDynamicArrays();
	LoadLocations();
	LoadPeople();
	Main();
}

//! Cleans up the dynamic memory.
/**
    Safely free the memory allocated by m_team and m_locationList.


*/
void Program::Cleanup()
{
	delete[] m_team, m_locationList;
}

//! Main game loop.
/**
    With the game loop...
        - Increment the week by 1
        - Call DisplayWeekStats()
        - Call UpdateTeam()
        - Call ScavengePhase()
        - Call ZombiePhase()
        - if everyone is dead (call IsEveryoneDead())...
            - done with game loop
        - Call RoundPause()

    - Once the game is over, call DisplaySummary().
*/
void Program::Main()
{
	bool gameOn = false;

	while (gameOn == false)
	{
		m_week++;
		DisplayWeekStats();
		UpdateTeam();
		ScavengePhase();
		ZombiePhase();

		gameOn = IsEveryoneDead();

		RoundPause();
	}
	
	DisplaySummary();
	
}

//! Display the base's stats and the current week.
/**
    Display the current week, as well as the current ammo and food held by the base.
*/
void Program::DisplayWeekStats()
{
	cout << "---------------------------------" << endl
		<< "------------- WEEK " << m_week << "-------------" << endl;
	cout << "BASE STATS" << endl;
	cout << m_base.GetFood() << " unit(s) food\t" << m_base.GetAmmo() << " unit(s) ammo" << endl << endl;
}

//! Update the team's hunger and health.
/**
    For each team member:
        - Call their Update() function
        - Look at the person's GetHunger() value, and request that amount of food from the base via TakeFood().
        - Have person Eat() that food.
        - Display that person's stats afterwards.
*/
void Program::UpdateTeam()
{
	cout << "TEAM STATS" << endl;

	for (int i = 0; i < m_teamCount; i++)
	{
		int hunger = 0;
		m_team[i].Update();
		hunger = m_team[i].GetHunger();
		hunger = m_base.TakeFood(hunger);
		m_team[i].Eat(hunger);
		
		cout << m_team[i].GetName() << " eats " << hunger << " unit(s) of food." << endl;
		m_team[i].DisplayStats();
	}

}

//! Get player to choose scavenging locations and update base and team stats.
/**
    - Display a list of all the available locations.
    - Ask the user which 3 locations to scavenge at, get their input.
    - Do input validation to make sure they have selected 3 valid indices.
    - Calculate the total amount of ammo salvaged from all 3 locations.
    - Calculate the total amount of food salvaged from all 3 locations.
    - Display the results - amount of food and ammo scavenged (total of each.)
    - Add that amount of ammo and food back to the base.
*/
void Program::ScavengePhase()
{
	int one, two, three = 0;
	int totalAmmo = 0;
	int totalFood = 0;
	
	cout << endl << "SELECT 3 LOCATIONS TO SCAVENGE" << endl;
	for (int i = 0; i < m_locationCount; i++)
	{
		cout << i << ". " << m_locationList[i].GetName() << endl;
	}
	cin >> one >> two >> three;
	
	if ((one < 0 || one > m_locationCount) || (two < 0 || two > m_locationCount) || (three < 0 || three > m_locationCount))
	{
		cout << "Invalid entry" << endl;
		cout << "SELECT 3 LOCATIONS TO SCAVENGE" << endl;
		for (int i = 0; i < m_locationCount; i++)
		{
			cout << i << ". " << m_locationList[i].GetName() << endl;
		}
		cin >> one >> two >> three;
	}

	totalAmmo = m_locationList[one].GetAmmo() + m_locationList[two].GetAmmo() + m_locationList[three].GetAmmo();
	totalFood = m_locationList[one].GetFood() + m_locationList[two].GetFood() + m_locationList[three].GetFood();

	cout << "RESULT" << endl
		<< totalAmmo << " unit(s) ammo scavenged" << endl
		<< totalFood << " unit(s) food scavenged" << endl << endl;

	m_base.AddAmmo(totalAmmo);
	m_base.AddFood(totalFood);
}

//! Check for zombie attack, and adjust team health and base stats.
/**
    - Generate a random number between 0 and 3.
    - If the random number is 0, then zombie attack:
        - Randomly select the zombie amount, between 1 and 3.
        - Calculate the total zombie health: 10 x the zombie count.
        - Display a message about the zombie attack, and how many zombies there are.
        - Determine if the base has enough ammo to fend off the zombies.
        - If there is not enough ammo:
            - Display a message that the base is out of ammo.
            - Subtract the amount of ammo the base has from the total zombie health.
            - Base ammo is now 0.
            - Zombies get a chance to attack a person. Randomly select a team member to attack.
            - Display a message of who the zombies attacked.
            - Call that team member's Hurt() function, with a random amount of damage between 10 and 20.
        - If there is enough ammo:
            - Subtract the total zombie health from the ammo count.
            - Display a message that the zombies have been killed, and how much ammo was used (equivalent to total zombie health).
*/
void Program::ZombiePhase()
{
	int randomNumber = (rand() % 3);

	if (randomNumber == 0)
	{
		int zombieNumber = (rand() % 3);
		int zombieHealth = zombieNumber * 10;

		cout << "ZOMBIE ATTACK!" << endl;
		cout << zombieNumber << " zombies attack!" << endl;
		if (zombieHealth > m_base.GetAmmo())
		{
			cout << "Ran out of ammo!" << endl;
			m_base.SubtractAmmo(zombieHealth);
			m_base.SetAmmo(0);
			int teamMemberHurt = (rand() % m_teamCount);
			m_team[teamMemberHurt].Hurt(rand() % 10 + 10);
		}
		else
		{
			m_base.SubtractAmmo(zombieHealth);
			cout << "Zombie(s) killed. Used " << zombieHealth
				<< " unit(s) ammo." << endl;
		}
	}

}

//! Check if the entire team is dead. If everyone is dead, return true. Otherwise, return false.
/**
    Determine if everybody on the team is dead. If at least one person lives, then this will return false.
    If everybody is dead, return true.

    If everyone is dead, display a message that everyone is dead.

    @return <bool>      true if everyone is dead; false if at least one person is alive.
*/
bool Program::IsEveryoneDead()
{
	int deadCount = 0;
	
	for (int j = 0; j < m_teamCount; j++)
	{
		bool personDead = m_team[j].IsDead();
		if (personDead == true)
		{
			deadCount++;
		}
	}
	if (deadCount == m_teamCount)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//! Display the game summary.
/**
    Display the amount of weeks that the team survived.
*/
void Program::DisplaySummary()
{
	cout << "Your team has survived " << m_week << " week(s)" << endl << endl;
}

//! Ask the user for input before continuing the program execution.
/**
    Ask the user to enter a value before continuing.
    (Can just be a dummy cin into a variable that doesn't do anything.)
*/
void Program::RoundPause()
{
	string userInput;

	cout << "Continue? (y/n): ";
	cin >> userInput;
	// just pause, no other function.
}

//! Load location information from the locations.txt file.
/**
    Create an ifstream object and open the locations.txt file.

    Create three temporary variables: name (string), ammo (int), food (int).
    Also create a counter variable i (int) and initialize it to 0.

    Create a while loop, while the counter i is less than the location count m_locationCount...
        - Retrieve name, ammo, and food from the input file
        - Setup location #i via its Setup() function.
        - Increment the counter variable i.

    Close the input file when done.
*/
void Program::LoadLocations()
{
	ifstream in_stream;
	in_stream.open("locations.txt");
	if (in_stream.fail())
	{
		cout << "Input file opening failed.\n";
	}

	string name;
	int ammo;
	int food;
	int i = 0;
	
	while (i < m_locationCount)
	{
		in_stream >> name;
		in_stream >> ammo;
		in_stream >> food;

		m_locationList[i].Setup(name, ammo, food);

		i++;
	}

	in_stream.close();
}

//! Load a list of names from the names.txt file and randomly assign names to the team.
/**
    Load names:
        - Create an array of strings that will store names that are loaded in. The array size should be 207.
        - Create a counter variable i, initialize it to 0.
        - Create an input file stream, and open names.txt
        - Use a while loop to load data from the input file to the names array
            e.g., while ( input >> names[i] )
        - Within the while loop, increment i by 1.
        - Close the input file once done.

    Assign names to team:
        - For each team member, use the Setup() function.
        - Pass in a random name to the Setup function to assign the person a random name.
*/
void Program::LoadPeople()
{
	string names[207];
	int i = 0;
	
	ifstream in_stream;
	in_stream.open("names.txt");
	if (in_stream.fail())
	{
		cout << "Input file opening failed.\n";
	}

	while (i < 207)
	{
		in_stream >> names[i];
		i++;
	}
	in_stream.close();

	for (int j = 0; j < m_teamCount; j++)
	{
		m_team[j].Setup(names[(rand() % 207)]);
	}
}

//! Ask the user how many locations and team members are available, and allocate memory for the dynamic arrays.
/**
    Ask the player how many locations and how many team members to have.

    Max location size is 10. Utilize a while loop to validate that the user has entered
    an amount between 0 and 10.

    Team count has to be 1 or more, use a while loop to validate that the user has entered
    an amount greater than 1.

    Afterward, use the m_locationList and m_team pointers to create
    dynamic arrays with the sizes given.
*/
void Program::SetupDynamicArrays()
{
	do
	{
		cout << "How many locations? (max 10) ";
		cin >> m_locationCount;
	} while (m_locationCount <= 0 || m_locationCount > 10);

	do
	{
		cout << "How many people on the team? ";
		cin >> m_teamCount;
	} while (m_teamCount < 1);

	m_locationList = new Location[m_locationCount];
	m_team = new Person[m_teamCount];
}
