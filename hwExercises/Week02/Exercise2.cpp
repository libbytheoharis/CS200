#include <iostream>
using namespace std;

// The scope of the age variable is any integer. 
// This includes positive and negative whole numbmers.

// The scope of the ticket price value is almost any 
// number with decimal points. It cannot have an 
// excessive number of digits (more than 38 decimal
// places on either side).

int main()
{
	int age;
	float ticketPrice;

	cout << "Age? ";
	cin >> age;

	if (age < 13)
	{
		ticketPrice = 5.00;
	}
	else
	{
		ticketPrice = 7.00;
	}

	cout << "Ticket price: " << ticketPrice << endl;

	while (true) {} // temp - don't let program quit.

	return 0;
}