#include <iostream>
#include <string>
using namespace std;

//CS 200 
//Libby Wichman
//InClassLab Array: Project E


int main()
{
	string items[3];
	float prices[3];
	int arraySize = 3;
	int itemCount = 0;

	for ( itemCount = 0; itemCount < arraySize; itemCount++)
	{
		cout << "Enter item name: ";
		cin >> items[itemCount];
		cout << "Enter price: ";
		cin >> prices[itemCount];
	}

	cout << endl;

	for(int counter = 0; counter < itemCount; counter++)
	{
		cout << "Item #" << counter << ": " << items[counter] << ", $" << prices[counter] << endl;
	}

	while (true)
	{
		; //keep it open
	}

	return 0;
}