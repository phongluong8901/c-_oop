#include <iostream>

using namespace std;

int main()
{
    // variable
    int myInt;  // declaretion
    myInt = 15; // initialization
    double myDouble = 3.1434;

    int x = 10;
    int y(10);
    int z{10};

    char singChar = 'a';
    string myName = "John";

    bool isranning = true;

    // math
    // +,-,*,/

    // relational
    //  >,<,>=,<=,==,!=

    // logic
    //  &&, ||

    // const

    // input
    int age;
    cout << "Please enter your age" << endl;
    cin >> age;

    string fullName;
    cin.get();
    getline(cin, fullName);
    cout << fullName << endl;

    return 0;
}