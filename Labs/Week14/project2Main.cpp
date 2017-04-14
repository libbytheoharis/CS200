#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


// CS 200 
// In Class Lab: Project 2
// Libby Wichman


int main()
{
	string wordToReplace;
	string wordToReplaceWith;
	string buffer;

	ifstream input("aesopFable.txt");
	ofstream output("aesopFableModified.txt");

	cout << "What word would you like to replace?" << endl;
	cin >> wordToReplace;
	cout << "With which word would you like to replace " << wordToReplace << "?" << endl;
	cin >> wordToReplaceWith;

	while (input >> buffer)
	{
		if (buffer == wordToReplace)
		{
			output << wordToReplaceWith << " ";
		}
		else
		{
			output << buffer << " ";
		}

	}

	input.close();
	output.close();

}
