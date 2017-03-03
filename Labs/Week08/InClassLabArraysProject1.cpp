#include <iostream>
#include <string>
using namespace std;

// CS 200
// Libby Wichman
// InClassLab: Arrays

int main()
{
	string names[5];

	names[0] = "Xia";
	names[1] = "Shang";
	names[2] = "Zhou";
	names[3] = "Qin";
	names[4] = "Han";

	{
		cout << names[0] << endl
			<< names[1] << endl
			<< names[2] << endl
			<< names[3] << endl
			<< names[4] << endl;
	}while (true);
	return 0;
}
