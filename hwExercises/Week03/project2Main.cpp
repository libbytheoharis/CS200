#include <iostream>
#include <string>
using namespace std;
//
// CS 200
// HWEX3 Project 2
// Libby Wichman
//

int main()
{
	int number;
	string romanNumeral;

	cout << "Enter a number between 1 and 5: ";
	cin >> number;

	switch (number)
	{
		case 1:
			romanNumeral = "I";
			break;
		case 2:
			romanNumeral = "II";
			break;
		case 3:
			romanNumeral = "III";
			break;
		case 4:
			romanNumeral = "IV";
			break;
		case 5:
			romanNumeral = "V";
			break;
	}
	
	cout << "Roman numberal is: " << romanNumeral;

	while (true)
	{
		; // to keep the program open
	}

	return 0;
}