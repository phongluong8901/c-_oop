#include <iostream>
#include <string>
#include "House.h" //sao chép và dán toàn bộ nội dung của file

using namespace std;

//-------House Class

//--------Main function

int main()
{
    House myHouse; // Dòng này cấp phát bộ nhớ và khởi tạo một ngôi nhà cụ thể mang tên myHouse.
    House yourHouse;

    cout << "Before calling any settings..." << ends;
    myHouse.print();

    // now call settings
    myHouse.setNumStories(2);
    myHouse.setNumWindows(6);
    myHouse.setColor("red");

    cout << "\nAfter calling settings..." << ends;
    myHouse.print();

    return 0;
}
