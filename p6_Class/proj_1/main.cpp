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
//======= PROTOTYPE

void printHouseData(const House &house);

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

    printHouseData(myHouse);
    printHouseData(yourHouse);

    return 0;
}

void printHouseData(const House &house)
{
    cout << "The house is " << house.getColor()
         << " and has " << house.getNumStories()
         << " stories and " << house.getNumWindows()
         << " windows." << endl;
}