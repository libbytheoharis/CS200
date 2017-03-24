/*
DON'T MODIFY THIS FILE
*/

#include <iostream>
using namespace std;

#include "hp2_program.hpp"
#include "hp2_tester.hpp"

int main()
{
	int choice;

    do
    {
		cout << endl << endl;
		cout << "1. RUN TESTS" << endl;
		cout << "2. RUN PROGRAM" << endl;
		cout << "3. EXIT PROGRAM" << endl;
		cin >> choice;

        if ( choice == 1 )
        {
            Tester tester;
            tester.Start();
        }
        else if ( choice == 2 )
        {
            Program program;
            program.Main(); // Start program
        }

    } while ( choice != 3 );


	return 0;
}
