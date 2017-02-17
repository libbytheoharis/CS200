// CS 200
// Libby Wichman
// In Class Lab: Strings and Vectors

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* GetNameLength (easy) ***************************************/

/*
Use the size() function to get the length of each name, and return
the sum of all sizes together.
*/
int GetNameLength(string first, string second, string third)
{
	int sum = 0;
	sum = first.size() + second.size() + third.size();
	return sum; // returns the sum of the lengths of all the names
}

// Test: Already implemented, you don't need to modify
void Test_GetNameLength();



/* Translate (easy) ***************************************/

// Use this function for the Translate function below
string TranslateWord(string word)
{
	// English -> Esperanto

	// nouns
	if (word == "the cat") { return "la kato"; }
	else if (word == "the dog") { return "la hundo"; }
	else if (word == "the person") { return "la persono"; }
	else if (word == "the mouse") { return "la muso"; }
	else if (word == "the bird") { return "la birdo"; }

	// verbs
	else if (word == "hugs") { return "brakumas"; }
	else if (word == "kisses") { return "kisas"; }
	else if (word == "hits") { return "batas"; }
	else if (word == "watches") { return "spektas"; }
	else if (word == "follows") { return "sekvas"; }
}

/*
Use the TranslateWord function (above) to translate the subject, verb, and object,
and build it into one sentence.

For example, if you pass in:
TranslateWord( "the cat" );
the result will be
"la kato"

The word order will be the same, HOWEVER, make sure you append "n" after the object's translation.
*/
string Translate(string subject, string verb, string object)
{
	string phrase = "";
	subject = TranslateWord(subject);
	verb = TranslateWord(verb);
	object = TranslateWord(object) + "n";
	phrase = subject + " " + verb + " " + object;
	return phrase;
}

void Test_Translate();



/* FindItem (medium) ***************************************/

/*
Search through the list of names.
If any of the names match the "findMe" parameter,
return the current index of that item.
Otherwise, return -1 if not found.
*/
int FindItem(vector<string> names, string findMe)
{
	for (unsigned int i = 0; i < names.size(); i++)
	{
		if (names[i] == findMe)
		{
			return i;
		}
	}
	return -1;
}

void Test_FindItem();



/* GetInitials (hard) ***************************************/

/*
A vector of names is passed in, such as "Homer", "J", "Simpson".
The output for this should be "HJS" - the first letter of each name.
This will require dealing with the initials as a 2D array.

Hint:	names[0] is "Homer", and names[0][0] is "H".
names[1] is "J", and names[1][0] is "J".
names[2] is "Simpson", and names[2][0] is "S".

Use a for-loop to iterate through all the names in the vector, and append letter #0 to the initials.
*/
string GetInitials(vector<string> names)
{
	string initials = "";

	// Iterate through each name, getting the 0th character from each and appending it to the "initials" string.
	for (unsigned int i = 0; i < names.size(); i++)
	{
		initials = initials + names[i][0];
	}

	return initials;
}

void Test_GetInitials();


/* Program entry-point ***************************************/

int main()
{
	Test_GetNameLength();
	Test_Translate();
	Test_FindItem();
	Test_GetInitials();

	cout << endl << "Program done" << endl;
	while (true);
	return 0;
}

/* TESTS - DON'T MODIFY ******************************************/

void Test_GetNameLength()
{
	cout << endl << "TEST GetNameLength()" << endl;
	int nameLength;

	// Test 1: All 3 names provided
	nameLength = GetNameLength("Ludwik", "Lejzer", "Zamenhof");
	if (nameLength != 20)
	{
		cout << "GetNameLength() test failed - Name length " << nameLength << " returned, but was expecting length to be 20." << endl;
	}
	else
	{
		cout << "GetNameLength() test 1 passed" << endl;
	}

	// Test 2: Only 2 names provided
	nameLength = GetNameLength("Louis", "", "Couturat");
	if (nameLength != 13)
	{
		cout << "GetNameLength() test failed - Name length " << nameLength << " returned, but was expecting length to be 13." << endl;
	}
	else
	{
		cout << "GetNameLength() test 1 passed" << endl;
	}

	// Test 3: Only 1 name provided
	nameLength = GetNameLength("", "", "Schleyer");
	if (nameLength != 8)
	{
		cout << "GetNameLength() test failed - Name length " << nameLength << " returned, but was expecting length to be 8." << endl;
	}
	else
	{
		cout << "GetNameLength() test 1 passed" << endl;
	}
}

void Test_Translate()
{
	cout << endl << "TEST Translate()" << endl;
	string translation;

	// Test 1
	translation = Translate("the cat", "follows", "the bird");
	if (translation != "la kato sekvas la birdon")
	{
		cout << "Translate() test failed - \"" << translation << "\" was returned but \"la kato sekvas la birdon\" was expected" << endl;
	}
	else
	{
		cout << "Translate() test 1 passed" << endl;
	}

	// Test 2
	translation = Translate("the dog", "watches", "the person");
	if (translation != "la hundo spektas la personon")
	{
		cout << "Translate() test failed - \"" << translation << "\" was returned but \"la hundo spektas la personon\" was expected" << endl;
	}
	else
	{
		cout << "Translate() test 2 passed" << endl;
	}
}

void Test_FindItem()
{
	cout << endl << "TEST FindItem()" << endl;
	vector<string> names = { "Hosmer", "Perez", "Gordon", "Moustakas" };
	int foundIndex;

	// Test 1: No item in the list
	foundIndex = FindItem(names, "Escobar");
	if (foundIndex != -1)
	{
		cout << "FindItem() test failed - Index " << foundIndex << " was returned for Escobar, who isn't in the list." << endl;
	}
	else
	{
		cout << "FindItem() test 1 passed" << endl;
	}

	// Test 2: Find item in list
	foundIndex = FindItem(names, "Hosmer");
	if (foundIndex != 0)
	{
		cout << "FindItem() test failed - Index " << foundIndex << " was returned for Hosmer, who should be at position 0." << endl;
	}
	else
	{
		cout << "FindItem() test 2 passed" << endl;
	}

	// Test 3: Find item in list
	foundIndex = FindItem(names, "Moustakas");
	if (foundIndex != 3)
	{
		cout << "FindItem() test failed - Index " << foundIndex << " was returned for Moustakas, who should be at position 3." << endl;
	}
	else
	{
		cout << "FindItem() test 3 passed" << endl;
	}
}

void Test_GetInitials()
{
	cout << endl << "TEST GetInitials()" << endl;
	string initials;

	// Test 1: Check initials
	initials = GetInitials({ "John", "Ronald", "Reuel", "Tolkien" });
	if (initials != "JRRT")
	{
		cout << "GetInitials() test failed - " << initials << " was returned for John Ronald Reuel Tolkein, but \"JRRT\" was expected." << endl;
	}
	else
	{
		cout << "GetInitials() test 1 passed" << endl;
	}
}