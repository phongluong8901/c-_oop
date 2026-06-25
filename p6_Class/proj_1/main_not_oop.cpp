#include <iostream>
#include <string>

using namespace std;

//-------House Class
class House
{
public:
    void setNumStories(int numStories)
    {
        this->numStories = numStories;
    }

    void setNumWindows(int numWindows)
    {
        this->numWindows = numWindows;
    }

    void setColor(string color)
    {
        this->color = color;
    }

    int getNumStories() const
    {
        return numStories;
    }

    int getNumWindows() const
    {
        return numWindows;
    }

    string getColor() const
    {
        return color;
    }

private:
    int numStories;
    int numWindows;
    string color;
};

//--------Main function

int main()
{
    House myHouse;
    House yourHouse;

    myHouse.setNumStories(2);
    myHouse.setNumWindows(6);
    myHouse.setColor("red");

    yourHouse.setNumStories(3);
    yourHouse.setNumWindows(10);
    yourHouse.setColor("blue");

    cout << "The house is " << myHouse.getColor()
         << " and has " << myHouse.getNumStories()
         << " stories and " << myHouse.getNumWindows()
         << " windows." << endl;

    cout << "The house is " << yourHouse.getColor()
         << " and has " << yourHouse.getNumStories()
         << " stories and " << yourHouse.getNumWindows()
         << " windows." << endl;

    return 0;
}