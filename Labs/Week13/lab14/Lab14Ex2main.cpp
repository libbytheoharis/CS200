#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Libby Wichman
// CS 200 
// Lab 14 Exercise 2

struct Person
{
	string name;
	Person* ptrFriend;
};

int main()
{
	Person* personA;
	Person* personB;
	Person* personC;

	personA = new Person;
	personB = new Person;
	personC = new Person;

	(*personA).name = "Harry";
	(*personB).name = "Ron";
	(*personC).name = "Hermione";

	personA->ptrFriend = personB;
	personB->ptrFriend = personC;
	personC->ptrFriend = personA;

	cout << "Person A: " << personA->name << ", friend: " << personA->ptrFriend->name << endl; 
	cout << "Person B: " << personB->name << ", friend: " << personB->ptrFriend->name << endl;
	cout << "Person C: " << personC->name << ", friend: " << personC->ptrFriend->name; 

	while (true)
	{
		; //keep open
	}

	delete personA;
	delete personB;
	delete personC;

}


