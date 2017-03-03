#include <iostream>
#include <string>
using namespace std;

// CS 200
// Libby Wichman
// InClassLab: Arrays Part 2

int main()
{
	string names[5];

	names[0] = "Xia";
	names[1] = "Shang";
	names[2] = "Zhou";
	names[3] = "Qin";
	names[4] = "Han";

	int index = 0;
	int arraySize = 5;
	
	while(index < arraySize)
	{
		cout << names[index] << endl;
		index++;
	}

	return 0;
}
