#include <iostream>
using namespace std;
//
// CS 200
// HWEX3 Project 4
// Libby Wichman
//

int main()
{
	int feet;

	while (true)
	{
		cout << endl << endl << "Enter the amount of feet: ";
		cin >> feet;

		for (int counter = 0; counter <= (feet * 12); counter++)
		{
			if (counter % 12 == 0)
			{
				cout << "|";
			}
			else
				cout << "-";
		}

	}
	return 0;
}