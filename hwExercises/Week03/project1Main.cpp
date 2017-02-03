#include <iostream>
#include <string>
using namespace std;
//
//
// CS 200
// HWEX3 Project 1
// 
//

int main()
{
	float priceOfItem = 0.00; 
	string cityLocation;
	float pricePlusTax;
	float total;

	cout << "What is the item price? ";
	cin >> priceOfItem;
	cout << "What city? ";
	cin >> cityLocation;

	if (cityLocation == "Olathe")
	{
		total = priceOfItem + (priceOfItem * 0.065);
	}
	else if (cityLocation == "OverlandPark")
	{
		total = priceOfItem + (priceOfItem * 0.0935);
	}
	else if (cityLocation == "Raytown")
	{
		total = priceOfItem + (priceOfItem * 0.08225);
	}
	else if (cityLocation == "Independence")
	{
		total = priceOfItem + (priceOfItem * 0.07725);
	}
	else
	{
		total = priceOfItem + (priceOfItem * 0.08);
	}

	cout << "Total price is : $" << total << endl;

	while (true)
	{
		;
	}

	return 0;
}