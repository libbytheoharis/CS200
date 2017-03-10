#include <iostream>

using namespace std;

// CS 200
// Libby Wichman
// Lab for Week 8 - Exercise 2

int main()
{
	int howManyDogs[5] = { 1, 2, 0, 3, 1 };

	cout << "Memory location of the array: " << howManyDogs << endl;
	cout << "Item 0 address: " << &howManyDogs[0] << "\t value: " << howManyDogs[0] << endl;
	cout << "Item 1 address: " << &howManyDogs[1] << "\t value: " << howManyDogs[1] << endl;
	cout << "Item 2 address: " << &howManyDogs[2] << "\t value: " << howManyDogs[2] << endl;
	cout << "Item 3 address: " << &howManyDogs[3] << "\t value: " << howManyDogs[3] << endl;
	cout << "Item 4 address: " << &howManyDogs[4] << "\t value: " << howManyDogs[4] << endl;

	while (true)
	{
		; // keep it open
	}

	return 0;
}