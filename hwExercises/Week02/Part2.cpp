#include <iostream>
using namespace std;

// false displays the value of 0, while true displays the value of 1.

int main()
{
	bool likesPizza = false;

	if (likesPizza == true)
		{
			cout << "Likes pizza." << endl;
		}
	else
		{
			cout << "Doesn't like pizza." << endl;
		}

	cout << likesPizza;
	while (true) {} // temp - don't let program quit.

	return 0;
}