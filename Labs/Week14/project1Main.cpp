#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


// CS 200 
// In Class Lab: Project 1
// Libby Wichman

struct Option
{
	string title;
	int count;


};

struct Poll
{
	string question;
	Option options[4];
};


int main()
{

	Poll myPoll;

	myPoll.question = "What is the best food?";

	myPoll.options[0].title = "Pizza";
	myPoll.options[0].count = 0;
	
	myPoll.options[1].title = "Veggie Taco";
	myPoll.options[1].count = 0;

	myPoll.options[2].title = "Samosas";
	myPoll.options[2].count = 0;

	myPoll.options[3].title = "Sushi";
	myPoll.options[3].count = 0;

	bool userContintues = true;

	while (userContintues == true)
	{
		int userSelection;
		cout << myPoll.question << endl
			<< "0. " << myPoll.options[0].title << endl
			<< "1. " << myPoll.options[1].title << endl
			<< "2. " << myPoll.options[2].title << endl
			<< "3. " << myPoll.options[3].title << endl
			<< "4. EXIT" << endl;
		cout << "What is your selection?" << endl;
		cin >> userSelection;

		if (userSelection == 0)
		{
			myPoll.options[0].count++;
		}
		else if (userSelection == 1)
		{
			myPoll.options[1].count++;
		}
		else if (userSelection == 2)
		{
			myPoll.options[2].count++;
		}
		else if (userSelection == 3)
		{
			myPoll.options[3].count++;
		}
		else if (userSelection == 4)
		{
			userContintues = false;
		}
		else
		{
			cout << "Not a vaild option.";
		}

		ofstream output;
		output.open("results.txt");

		output << "QUESTION" << endl;
		output << myPoll.question << endl << endl;
		output << "RESULTS" << endl;
		
		for (int i = 0; i < 4; i++)
		{
			output << myPoll.options[i].title << "\t \t" << myPoll.options[i].count << "votes" << endl;
		}

		output.close();
			
	}

}
