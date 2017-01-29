#include <iostream>     // input/output commands
using namespace std;    // standard library

int main()              // program entry function
{
	// Variable declarations
	float widthRm1;
	float lengthRm1;
	float areaRm1;
	float perimeterRm1;
	float widthRm2;
	float lengthRm2;
	float areaRm2;
	float perimeterRm2;

	// Title 
	cout << "ROOM CALCULATOR\n\n\n";
	cout << "Room 1\n\n\n";

	// Get user input for Room 1:
	cout << "Enter the width: ";        // text output
	cin >> widthRm1;                       // input from the user

	cout << "Enter the length: ";
	cin >> lengthRm1;

	areaRm1 = widthRm1 * lengthRm1;              // assignment statement
	perimeterRm1 = 2 * widthRm1 + 2 * lengthRm1;

										// Display results:
	cout << endl;                       // empty line
	cout << "Area: " << areaRm1 << endl;
	cout << "Perimeter: " << perimeterRm1 << endl
		<< endl
		<< endl;

	// Get user input for Room 2:
	cout << "Room 2\n\n\n";
	cout << "Enter the width: ";        // text output
	cin >> widthRm2;                       // input from the user

	cout << "Enter the length: ";
	cin >> lengthRm2;

	areaRm2 = widthRm2 * lengthRm2;              // assignment statement
	perimeterRm2 = 2 * widthRm2 + 2 * lengthRm2;

	// Display results:
	cout << endl;                       // empty line
	cout << "Area: " << areaRm2 << endl;
	cout << "Perimeter: " << perimeterRm2 << endl;

	while (true);
	return 0;           // end of program
}
