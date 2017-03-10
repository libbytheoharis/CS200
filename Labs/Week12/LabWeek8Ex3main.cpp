#include <iostream>
#include <string>

using namespace std;

// CS 200
// Libby Wichman
// Lab for Week 8 - Exercise 3

int main()
{
	int myIntVariable = 24;
	float myFloatVariable = 0.354;
	string myStringVariable = "Strings for me and you!";

	int* ptrInteger = &myIntVariable;
	float* ptrFloat = &myFloatVariable;
	string* ptrString = &myStringVariable;

	cout << ptrInteger << " = " << myIntVariable << endl;
	cout << ptrFloat << " = " << myFloatVariable << endl;
	cout << ptrString << " = " << myStringVariable << endl;

	while (true)
	{
		; // keep it open
	}

	return 0;
}