#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Variable declarations
    string name, color, answer;

    // Output and input
    cout << "Hello, what is your name? ";
    cin >> name;

    cout << "What is your favorite color? ";
    cin >> color;

    cout << endl;
    cout << "So can I call you " << color << " " << name << "?" << endl;

    cout << "Does that work for you? ";
    cin >> answer;

    return 0;
}
