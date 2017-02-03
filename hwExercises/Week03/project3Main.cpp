#include <iostream>
using namespace std;
//
// CS 200
// HWEX3 Project 3
// Libby Wichman
//

int main()
{
	int sum = 0;
	bool isDone = false;

	while (isDone == false)
	{
		int inputNumber;
		char userDecision;

		cout << endl << "Enter a number: ";
		cin >> inputNumber;
		sum = sum + inputNumber;
		
		cout << endl << "Type (Q) to quit, or (A) to enter another. " << endl
			<< "Choice: ";
		cin >> userDecision;
		
		if (userDecision == 'q' || userDecision == 'Q')
		{
			isDone = true;
		}
	}

	cout << endl << "The sum is " << sum;

	while (true)
	{
		; //keep it open please
	}

	return 0;
}