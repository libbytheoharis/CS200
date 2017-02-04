#include <iostream>
#include <string>
using namespace std;

// CS 200
// Libby Wichman
// In Class Lab - Functions
// Project 3

float CountChange(int quarterCount, int dimeCount, int nickelCount, int pennyCount);
// Function: CountChange
// Input: User inputs how many of each coin they have.
// Output: Total change in dollars.


float CountChange(int quarterCount, int dimeCount, int nickelCount, int pennyCount)
{	
	quarterCount = static_cast<float>(quarterCount) * 0.25;
	dimeCount = static_cast<float>(dimeCount) * 0.10;
	nickelCount = static_cast<float>(nickelCount) * 0.05;
	pennyCount = static_cast<float>(pennyCount) * 0.01;
	// I've tried a number of different ways to try to get 
	// the money variable from outputting an integer, but 
	// I still can't figure it out. Arg!
	return (quarterCount + dimeCount + nickelCount + pennyCount);
}

int main()
{	
	while (true)
	{
		int quarters, dimes, nickels, pennies;

		cout << "How many quarters? ";
		cin >> quarters;

		cout << "How many dimes? ";
		cin >> dimes;

		cout << "How many nickels? ";
		cin >> nickels;

		cout << "How many pennies? ";
		cin >> pennies;

		float money = CountChange(quarters, dimes, nickels, pennies);
		cout << "Money: $" << money << endl;

		cout << endl << endl;
	}

	return 0;
}