#include <iostream>
#include "Rectangle.h"
#include "RectangleHelper.h"

using namespace std;

// Khai báo nguyên mẫu hàm bạn (friend functions)
void changeData(Rectangle &rect);
void printData(Rectangle &rect);

int main()
{
    // Khởi tạo đối tượng r1 với chiều dài 10, chiều rộng 25
    Rectangle r1(10, 25);
    RectangleHelper helper;

    cout << "r1 area: " << r1.area() << endl; // In diện tích ban đầu (10 * 25 = 250)

    // Gọi hàm bạn changeData để thay đổi length và width thành 100
    changeData(r1);

    cout << "Now, r1 area: " << r1.area() << endl; // In diện tích sau khi đổi (100 * 100 = 10000)

    // Dùng lớp bạn helper để thay đổi length và width thành 500
    helper.modifyRectangle(r1);
    cout << "after helper modifies, area: " << r1.area() << endl; // In diện tích mới (500 * 500 = 250000)

    cout << "printing data directly with printData:" << endl;
    // Gọi hàm bạn printData để in trực tiếp thuộc tính private
    printData(r1);

    return 0;
}

// Định nghĩa hàm bạn changeData: được quyền truy cập rect.length và rect.width
void changeData(Rectangle &rect)
{
    rect.length = 100;
    rect.width = 100;
}

// Định nghĩa hàm bạn printData: được quyền truy cập và in trực tiếp dữ liệu private
void printData(Rectangle &rect)
{
    cout << "length: " << rect.length
         << ", width: " << rect.width << endl;
}