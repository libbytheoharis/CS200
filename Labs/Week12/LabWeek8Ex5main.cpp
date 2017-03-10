#include <iostream>

using namespace std;

// CS 200
// Libby Wichman
// Lab: Week 8 - Exercise 5

int main()
{
	char userChoice;
	float priceHamburger = 6.99;
	float priceFries = 2.99;
	float priceSalad = 5.99;
	float* ptrPrice;

	while (true)
	{
		float taxAmt = 0.065;
		cout << "[h]amburger, [f]ries, or [s]alad? ";
		cin >> userChoice;

		switch (userChoice)
		{
		case 'h':
		{
			ptrPrice = &priceHamburger;
			cout << "Original price: $" << *ptrPrice << endl;
			*ptrPrice = (taxAmt * *ptrPrice) + *ptrPrice;
			cout << "With tax price: $" << *ptrPrice << endl << endl;
			break;
		}
		case 'f':
		{
			ptrPrice = &priceFries;
			cout << "Original price: $" << *ptrPrice << endl;
			*ptrPrice = (taxAmt * *ptrPrice) + *ptrPrice;
			cout << "With tax price: $" << *ptrPrice << endl << endl;
			break;
		}
		case 's':
		{
			ptrPrice = &priceSalad;
			cout << "Original price: $" << *ptrPrice << endl;
			*ptrPrice = (taxAmt * *ptrPrice) + *ptrPrice;
			cout << "With tax price: $" << *ptrPrice << endl << endl;
			break;
		}
		}
	}


	while (true)
	{
		; //keep it open
	}

	return 0;
}
