#include <iostream>
#include <string>
using namespace std;

// CS 200
// Libby Wichman
// HWEX4 : Functions


// Input/Output function declarations

string GetHindi(string english);
// Translates an English word into a Hindi word.
// Input is one of four English words (cat, dog, frog,
// rabbit)
// Outputs the corresponding Hindi word.

string GetEnglish(string hindi);
// Translates a Hindi word into an English word.
// Input is one of four Hindi words (billee, kutta,
// medhak, khargosh)
// Outputs the corresponding English word.



string GetHindi(string english)
{
	if ( english == "cat")
	{
		return "billee";
	}
	else if ( english == "dog")
	{
		return "kutta";
	}
	else if ( english == "frog")
	{
		return "medhak";
	}
	else if ( english == "rabbit")
	{
		return "khargosh";
	}
	else
	{
		return "Word not found.";
	}
}

string GetEnglish(string hindi)
{
	if (hindi == "billee")
	{
		return "cat";
	}
	else if (hindi == "kutta")
	{
		return "dog";
	}
	else if (hindi == "medhak")
	{
		return "frog";
	}
	else if (hindi == "khargosh")
	{
		return "rabbit";
	}
	else
	{
		return "Word not found.";
	}
}

// Menu functions

void DisplayMenu()
{
	cout << endl << endl;
	cout << "1. English to Hindi" << endl;
	cout << "2. Hindi to English" << endl;
	cout << "3. Quit" << endl;
}

void EnglishToHindi()
{
	string englishWord;
	string englishWordToHindi;

	cout << "English: ";
	cin >> englishWord;
	englishWordToHindi = GetHindi(englishWord);
	cout << "Hindi translation: " << englishWordToHindi << endl;
}

void HindiToEnglish()
{
	string hindiWord;
	string hindiWordToEnglish;

	cout << "Hindi: ";
	cin >> hindiWord;
	hindiWordToEnglish = GetEnglish(hindiWord);
	cout << "English translation: " << hindiWordToEnglish << endl;
}

int main()
{
	bool exit = false; 

	while (exit == false)
	{
		int userChoice;
		DisplayMenu();
		cin >> userChoice;

		if (userChoice == 1)
		{
			EnglishToHindi();
		}
		else if (userChoice == 2)
		{
			HindiToEnglish();
		}
		else if (userChoice == 3)
		{
			exit = true;
		}
		else
		{
			cout << "Not a valid entry! "
				<< "Please select from the menu." << endl;
		}

	}
	return 0;
}
