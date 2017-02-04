#include <iostream>
using namespace std;

// CS 200
// Libby Wichman
// In Class Lab - Project 4

int main()
{
	float startingWage;
	float percentRaisePerYear;
	float adjustedWage;
	int yearsWorked;

	cout << "Please enter your starting wage: ";
	cin >> startingWage;
	cout << "Please enter the percentage of a raise do you receive per year: ";
	cin >> percentRaisePerYear;
	cout << "How many years have you worked? ";
	cin >> yearsWorked;

	percentRaisePerYear /= 100;
	adjustedWage = startingWage;

		for (yearsWorked; yearsWorked > 0; yearsWorked--)
		{
			adjustedWage = adjustedWage + (adjustedWage * percentRaisePerYear);
		}

	cout << "Your new wage is $" << adjustedWage;

	while (true)
	{
		; //keep it open please.
	}

	return 0;
}