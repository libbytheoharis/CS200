#include <iostream>
#include <fstream>      // file input/output
#include <string>
#include <cstdlib>      // has functions for random #s
#include <ctime>        // for seeding the random # generator
using namespace std;

// CS 200
// In class Lab: Project 3
// Libby Wichman

struct PoemMaker
{
	string nouns[10];
	string adjectives[10];

	void LoadNouns(string filename)
	{
		ifstream input;
		input.open(filename);

		for (int i = 0; i < 10; i++)
		{
			input >> nouns[i];
		}

		input.close();
	}
	void LoadAdjectives(string filename)
	{
		ifstream input;
		input.open(filename);

		for (int i = 0; i < 10; i++)
		{
			input >> adjectives[i];
		}

		input.close();
	}
	string GetRandomNoun()
	{
		int randomNumber = rand() % 10;
		return nouns[randomNumber];
	}
	string GetRandomAdjective()
	{
		int randomNumber = rand() % 10;
		return adjectives[randomNumber];
	}
	string GeneratePoem(int lines)
	{
		string poem = " ";
		
		for (int i = 0; i < lines; i++)
		{
			poem += GetRandomNoun() + " are " + GetRandomAdjective() + "\n";
		}

		return poem;
	}
};

int main()
{
	srand(time(NULL));
	
	PoemMaker poemMaker;

	poemMaker.LoadNouns("nouns.txt");
	poemMaker.LoadAdjectives("adjectives.txt");

	string poem = poemMaker.GeneratePoem(5);

	cout << poem; 

	while (true)
	{
		;
	}
}