// có nghĩa là bạn đang yêu cầu trình biên dịch sao chép và dán toàn bộ nội dung của file "House.h" vào ngay vị trí này trước khi dịch mã nguồn.
#include "House.h"
#include <iostream>

using namespace std;

House::House()
{
    this->numStories = 1;
    this->numWindows = 4;
    this->color = "white";
} // end no-arg ctor

House::House(int numStories, int numWindows, string color)
{
    this->numStories = numStories;
    this->numWindows = numWindows;
    this->color = color;
} // end parameterized ctor

House::~House()
{
    cout << "The " << color << " house with " << numStories << " stories"
         << " and " << numWindows << " windows is being destroyed!" << endl;
}

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

//--
// Hàm ~House() được gọi là Hàm hủy (Destructor). Để hiểu rõ cơ chế của nó, bạn hãy hình dung vòng đời của một đối tượng giống như đời thực:

// Khởi tạo (Constructor - House()): Giống như việc bạn xây xong một ngôi nhà, các thông số được thiết lập.

// Sử dụng: Ngôi nhà tồn tại và phục vụ các nhu cầu trong chương trình (như gán màu, in thông tin).

// Hủy diệt (Destructor - ~House()): Giống như việc ngôi nhà bị phá dỡ hoàn toàn khi không còn dùng đến nữa, bộ nhớ RAM cấp phát cho ngôi nhà đó sẽ được dọn sạch để trả lại cho hệ điều hành.

//---
