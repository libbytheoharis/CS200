#include <iostream>
using namespace std;

// Yes anything that can be tested can be used as
// the condition of an if statement.

int main()
{
	bool isTallEnoughForRide;
	float feet; 

	cout << "What is your height in feet? ";
	cin >> feet;

	if (feet > 3)
	{
		isTallEnoughForRide = true;
	}
	else if (feet <= 3)
	{
		isTallEnoughForRide = false;
	}

	if (isTallEnoughForRide == true)
	{
		cout << "Permitted to ride the roller coaster.";
	}
	else if (isTallEnoughForRide == false)
	{
		cout << "Too short to ride the roller coaster.";
	}

	while (true) {} // temp - don't let program quit.

	return 0;
}