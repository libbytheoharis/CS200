#include <iostream>
#include <string>
using namespace std;

// CS 200 
// Libby Wichman
// InClassLab8 - Testing



float Average(float a, float b, float c)
{
	return (a + b + c) / 3;
}

void Test_Average()
{
	// Test 1
	int t1Input1 = 1, t1Input2 = 1, t1Input3 = 1;
	int t1ExpectedOutput = 1;
	int t1ActualOutput = Average(t1Input1, t1Input2, t1Input3);

	if (t1ExpectedOutput != t1ActualOutput)
	{
		cout << "Failed for " << t1Input1 << ", " << t1Input2 << ", " << t1Input3 << endl;
	}
	else
	{
		cout << "Passed for " << t1Input1 << ", " << t1Input2 << ", " << t1Input3 << endl;
	}

	// Test 2
	int t2Input1 = -1, t2Input2 = 0, t2Input3 = 1;
	int t2ExpectedOutput = 0;
	int t2ActualOutput = Average(t2Input1, t2Input2, t2Input3);

	if (t2ExpectedOutput != t2ActualOutput)
	{
		cout << "Failed for " << t2Input1 << ", " << t2Input2 << ", " << t2Input3 << endl;
	}
	else
	{
		cout << "Passed for " << t2Input1 << ", " << t2Input2 << ", " << t2Input3 << endl;
	}

	// Test 3
	int t3Input1 = 3, t3Input2 = 6, t3Input3 = 9;
	int t3ExpectedOutput = 6;
	int t3ActualOutput = Average(t3Input1, t3Input2, t3Input3);

	if (t3ExpectedOutput != t3ActualOutput)
	{
		cout << "Failed for " << t3Input1 << ", " << t3Input2 << ", " << t3Input3 << endl;
	}
	else
	{
		cout << "Passed for " << t3Input1 << ", " << t3Input2 << ", " << t3Input3 << endl;
	}

}

int Max(int a, int b, int c)
{
	if ((a < b) && (c < b))
	{
		return b;
	}
	else if ( a < c )
	{
		return c;
	}
	else
	{
		return a;
	}
}

void Test_Max()
{
	// Test 1
	int t1Input1 = 1, t1Input2 = 1, t1Input3 = 1;
	int t1ExpectedOutput = 1;
	int t1ActualOutput = Max(t1Input1, t1Input2, t1Input3);

	if (t1ExpectedOutput != t1ActualOutput)
	{
		cout << "Failed for " << t1Input1 << ", " << t1Input2 << ", " << t1Input3 << endl;
	}
	else
	{
		cout << "Passed for " << t1Input1 << ", " << t1Input2 << ", " << t1Input3 << endl;
	}

	// Test 2
	int t2Input1 = -5, t2Input2 = 0, t2Input3 = 5;
	int t2ExpectedOutput = 5;
	int t2ActualOutput = Max(t2Input1, t2Input2, t2Input3);

	if (t2ExpectedOutput != t2ActualOutput)
	{
		cout << "Failed for " << t2Input1 << ", " << t2Input2 << ", " << t2Input3 << endl;
	}
	else
	{
		cout << "Passed for " << t2Input1 << ", " << t2Input2 << ", " << t2Input3 << endl;
	}

	// Test 3
	int t3Input1 = 30, t3Input2 = 20, t3Input3 = 10;
	int t3ExpectedOutput = 30;
	int t3ActualOutput = Max(t3Input1, t3Input2, t3Input3);

	if (t3ExpectedOutput != t3ActualOutput)
	{
		cout << "Failed for " << t3Input1 << ", " << t3Input2 << ", " << t3Input3 << endl;
	}
	else
	{
		cout << "Passed for " << t3Input1 << ", " << t3Input2 << ", " << t3Input3 << endl;
	}
}

int Factorial(int n)
{
	int fac = n;

	if (n == 0)
	{
		return 1;
	}
	else if (n < 0)
	{
		cout << "undefined";
		return 0;
	}
	else
	{
		for (int i = (n-1); i >= 1; i--)
		{
			fac = fac * i;
		}
		return fac;
	}
}

void Test_Factorial()
{
	// Test 1
	int t1Input1 = 0;
	int t1ExpectedOutput = 1;
	int t1ActualOutput = Factorial(t1Input1);

	if (t1ExpectedOutput != t1ActualOutput)
	{
		cout << "Failed for " << t1Input1 << endl;
	}
	else
	{
		cout << "Passed for " << t1Input1 << endl;
	}

	// Test 2
	int t2Input1 = 5;
	int t2ExpectedOutput = 120;
	int t2ActualOutput = Factorial(t2Input1);

	if (t2ExpectedOutput != t2ActualOutput)
	{
		cout << "Failed for " << t2Input1 << endl;
	}
	else
	{
		cout << "Passed for " << t2Input1 << endl;
	}

	// Test 3
	int t3Input1 = 4;
	int t3ExpectedOutput = 24;
	int t3ActualOutput = Factorial(t3Input1);

	if (t3ExpectedOutput != t3ActualOutput)
	{
		cout << "Failed for " << t3Input1 << endl;
	}
	else
	{
		cout << "Passed for " << t3Input1 << endl;
	}

}

string FormatName(string first, string last)
{
	return last + ", " + first;
}

void Test_FormatName()
{
	// Test 1
	string t1Input1 = "Albus", t1Input2 = "Dumbledore";
	string t1ExpectedOutput = "Dumbledore, Albus";
	string t1ActualOutput = FormatName(t1Input1, t1Input2);

	if (t1ExpectedOutput != t1ActualOutput)
	{
		cout << "Failed for " << t1Input1 << ", " << t1Input2 << endl;
	}
	else
	{
		cout << "Passed for " << t1Input1 << ", " << t1Input2 << endl;
	}

	// Test 2
	string t2Input1 = "Severus", t2Input2 = "Snape";
	string t2ExpectedOutput = "Snape, Severus";
	string t2ActualOutput = FormatName(t2Input1, t2Input2);

	if (t2ExpectedOutput != t2ActualOutput)
	{
		cout << "Failed for " << t2Input1 << ", " << t2Input2 << endl;
	}
	else
	{
		cout << "Passed for " << t2Input1 << ", " << t2Input2 << endl;
	}

	// Test 3
	string t3Input1 = "Harry", t3Input2 = "Potter";
	string t3ExpectedOutput = "Potter, Harry";
	string t3ActualOutput = FormatName(t3Input1, t3Input2);

	if (t3ExpectedOutput != t3ActualOutput)
	{
		cout << "Failed for " << t3Input1 << ", " << t3Input2 << endl;
	}
	else
	{
		cout << "Passed for " << t3Input1 << ", " << t3Input2 << endl;
	}
}

int main()
{
	Test_Average();
	Test_Max();
	Test_Factorial();
	Test_FormatName();

	while (true)
	{
		; // keep it open
	}

	return 0;
}