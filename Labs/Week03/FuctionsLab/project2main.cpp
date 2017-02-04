#include <iostream>
using namespace std;
//
// CS 200
// Libby Wichman
// In Class Lab - Functions
// Project 2
//
// Fuction: AddTax
// Input:
// Output:

float AddTax(float dollar)
{
	dollar = dollar + (dollar * 0.12);
	return dollar;
}

int main()
{
	cout << "Price: $" << 9.99 << " \t with tax: $" << AddTax(9.99) << endl;
	cout << "Price: $" << 19.95 << " \t with tax: $" << AddTax(19.95) << endl;
	cout << "Price: $" << 10.00 << " \t with tax: $" << AddTax(10.00) << endl;

	while (true)
	{
		; // keep it open please.
	}

	return 0;
}