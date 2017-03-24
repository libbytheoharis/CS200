#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std; 

// Libby Wichman 
// CS 200 
// Lab 14 Exercise 3


int main()
{
	srand(time(NULL)); // (At the beginning of main())

	int size = 0;


	cout << "Lotto number count: ";
	cin >> size;

	int* lottoNumbers;
	lottoNumbers = new int[size];

	for (int i = 0; i < size; i++)
	{
		lottoNumbers[i] = rand() % 100;
		cout << lottoNumbers[i] << "\t";
	}

	while (true)
	{
		; //keep open
	}

	delete[] lottoNumbers;
}