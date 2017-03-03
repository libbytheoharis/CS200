#include <iostream>
#include <string>
using namespace std;

// CS 200
// Libby Wichman
// InClassLab: Arrays Part 3

int main()
{
	string items[3];
	float prices[3];
	int arraySize = 3;
	int itemCount = 0;

		while (itemCount < arraySize)
		{
			cout << "Enter item name: ";
			cin >> items[itemCount];
			cout << "Enter price: ";
			cin >> prices[itemCount];
			itemCount++;
		}

		cout << endl;
		cout << endl;

		int counter = 0;
		while (counter < itemCount)
		{
			cout << "Item #" << counter
				<< ": " << items[counter]
				<< ", $" << prices[counter]
				<< endl;
			counter++;
		}

	return 0;
}
