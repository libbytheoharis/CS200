#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Libby Wichman
// CS 200
// Lab 14 Exercise 4

struct Employee
{
	string name;
};
struct Manager
{
	string name;
	Employee* employees;
	int employeeCount;
};

int main()
{
	srand(time(NULL)); // (At the beginning of main())

	int managerCount;
	Manager* managers;


	string names[16] = {
		"Koios", "Julianna", "Agata", "Arundhati",
		"Zemfira", "Fedya", "Kim", "Ashok",
		"Jouni", "Blandina", "Ampelio", "Rosmunda",
		"Breeshey", "Ferdinand", "Gertrude", "Sarit"
	};

	cout << "How many managers? ";
	cin >> managerCount;
	managers = new Manager[managerCount];

	for (int i = 0; i < managerCount; i++)
	{
		managers[i].name = names[rand() % 16];

		
		managers[i].employeeCount = rand() % 4;

		managers[i].employees = new Employee[managers[i].employeeCount];

		if (managers[i].employeeCount > 0)
		{
			for (int j = 0; j < managers[i].employeeCount; j++)
			{
				managers[i].employees[j].name = names[rand() % 16];
			}
		}
	}

	for (int m = 0; m < managerCount; m++)
	{
		cout << endl;
		cout << "Manager:           "
			<< managers[m].name << endl;
		cout << "Underling Count:   "
			<< managers[m].employeeCount << endl;

		for (int e = 0; e < managers[m].employeeCount; e++)
		{
			cout << "\t" << e + 1 << ". "
				<< managers[m].employees[e].name << endl;
		}
	}

	delete [] managers;
}

