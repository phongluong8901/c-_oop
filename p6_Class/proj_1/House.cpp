// có nghĩa là bạn đang yêu cầu trình biên dịch sao chép và dán toàn bộ nội dung của file "House.h" vào ngay vị trí này trước khi dịch mã nguồn.
#include "House.h"
#include <iostream>

using namespace std;
void House::setNumStories(int numStories)
{
    this->numStories = numStories;
}

void House::setNumWindows(int numWindows)
{
    this->numWindows = numWindows;
}

void House::setColor(string color)
{
    this->color = color;
}

int House::getNumStories() const
{
    return numStories;
}

int House::getNumWindows() const
{
    return numWindows;
}

string House::getColor() const
{
    return color;
}

void House::print() const
{
    cout << "The house is " << color
         << " and has " << numStories
         << " stories and " << numWindows
         << " windows." << endl;
}

// Dấu :: trong C++ được gọi là Scope Resolution Operator (toán tử phân giải phạm vi).

// Trong dòng code void House::setNumStories(int numStories), ý nghĩa của nó là:

// Chỉ định thuộc sở hữu: Nó cho trình biên dịch biết rằng hàm setNumStories thuộc về lớp House.

// Phân biệt: Nếu không có House::, trình biên dịch sẽ nghĩ đây là một hàm thông thường nằm ngoài class. Nhờ có ::, nó hiểu chính xác đây là ruột của hàm đã được khai báo bên trong class House.