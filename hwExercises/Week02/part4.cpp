#include <iostream>
using namespace std;

// If the user enters a capital letter, the capital letter
// "A" will be valued less than the lower case letter
// "a".

// This is because the letters are evaluated by their ascii
// value, where uppercase letters are given a value lower 
// than the lower case alphabet.


int main()
{
	char letter1;
	char letter2;

	cout << "Please enter a letter: ";
	cin >> letter1;
	cout << "Please enter another letter: ";
	cin >> letter2;

	if (letter1 < letter2)
	{
		cout << "first letter comes first.";
	}
	else
	{
		cout << "second letter comes first.";
	}

	while (true) {} // temp - don't let program quit.

	return 0;
}