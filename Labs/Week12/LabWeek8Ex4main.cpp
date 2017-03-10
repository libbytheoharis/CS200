#include <iostream>
#include <string>

using namespace std;

//CS 200
//Libby Wichman
//Lab: Week 8 - Exercise 4

int main()
{

	while (true)
	{
		char choice;

		cout << endl << endl << "[i]nt, [f]loat, [b]oolean, or [d]ouble? ";
		cin >> choice;
		cout << endl << endl;

		switch (choice)
		{
		case 'i':
		{
			int userInt = 32;
			int* ptrInt = &userInt;

			cout << "Integer size: " << sizeof(userInt) << endl;
			cout << "Address: " << ptrInt << endl;
			break;
		}
		case 'f':
		{
			float userFloat = 2.342;
			float* ptrFloat = &userFloat;

			cout << "Float size: " << sizeof(userFloat) << endl;
			cout << "Address: " << ptrFloat << endl;
			break;
		}
		case 'b':
		{
			bool userBool = false;
			bool* ptrBool = &userBool;

			cout << "Boolean size: " << sizeof(userBool) << endl;
			cout << "Address: " << ptrBool << endl;
			break;
		}
		case 'd':
		{
			double userDouble = 84.56;
			double* ptrDouble = &userDouble;

			cout << "Double size: " << sizeof(userDouble) << endl;
			cout << "Address: " << ptrDouble << endl;
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