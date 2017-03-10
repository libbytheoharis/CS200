#include <iostream>
#include <string>

using namespace std;

// CS 200
// Libby Wichman
// Lab: Week 8 - Exercise 6

int main()
{
	string students[3] = { "Randy", "Morty", "Jess" };
	string* ptrStudent;
	int userChoice;

	cout << "Enter 0, 1, or 2: ";
	cin >> userChoice;

	ptrStudent = &students[userChoice];

	cout << "New name: ";
	cin >> *ptrStudent;

	for (int i = 0; i < 3; i++)
	{
		cout << "student " << i << " = " << students[i] << endl;
	}

	while (true)
	{
		; //keep it open
	}

	return 0;
}