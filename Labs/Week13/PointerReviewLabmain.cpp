
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <string>

using namespace std;

// Libby Wichman
// CS 200 
// Lab 12: Pointer Review Lab

struct College
{
	string name;
	string state;
};

struct Student
{
	string name;
	College* ptrSchool;
};

int main()
{
	Student students[5];


	College colleges[3];
	colleges[0].name = "JCCC";
	colleges[0].state = "KS";
	colleges[1].name = "MCCKC";
	colleges[1].state = "MO";
	colleges[2].name = "KCKCC";
	colleges[2].state = "KS";


	for (int i = 0; i < 5; i++)
	{
		int collegeChoice = -1;
		cout << endl << "Enter name for student " << (i + 1) << ": ";
		cin >> students[i].name;
		cout << "Which college for " << students[i].name << "?" << endl << endl;

		for (int j = 0; j < 3; j++)
		{
			cout << (j + 1) << ". " << colleges[j].name << "  " << colleges[j].state << endl;
		}
		
		cin >> collegeChoice;
		students[i].ptrSchool = &colleges[collegeChoice - 1];
	}

	for (int i = 0; i < 5; i++)
	{
		cout << endl << "All students: " << endl;
		cout << (i + 1) << ". " << students[i].name << "   \t"
			<< students[i].ptrSchool->name << "    \t"
			<< students[i].ptrSchool->state << endl; 
	}

	while (true)
	{
		; //keep it open
	}
	
}