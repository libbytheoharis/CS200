#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Libby Wichman
// CS 200 
// Lab 14 Dynamic Variables and Arrays

int main()
{
	int* myInt;
	string* myStr;
	float* myFloat;

	myInt = new int; 
	*myInt = 20;

	myStr = new string;
	*myStr = "Libby";

	myFloat = new float;
	*myFloat = 199.99;

	cout << *myInt << "\t" << *myStr << "\t" << *myFloat;

	while (true)
	{
		; //keep it open
	}

	delete myInt;
	delete myStr;
	delete myFloat;

}