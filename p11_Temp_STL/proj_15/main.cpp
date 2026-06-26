#include <iostream>
#include "Rectangle.h"
using namespace std;

int main()
{
    // Khởi tạo các đối tượng hình chữ nhật
    Rectangle rect1(10, 20);
    Rectangle rect2(50, 100);
    Rectangle rect3(10, 20);
    Rectangle resultRect;

    // Sử dụng toán tử + đã nạp chồng
    resultRect = rect1 + rect2; // Trình biên dịch hiểu ngầm là: rect1.operator+(rect2);

    // Sử dụng toán tử == và !=
    cout << "rect1 == rect3? " << boolalpha << (rect1 == rect3) << endl;
    cout << "rect1 != rect2? " << boolalpha << (rect1 != rect2) << endl;

    // In kích thước và diện tích của hình chữ nhật kết quả
    cout << "resultRect: "
         << resultRect.getLength() << " * "
         << resultRect.getWidth() << " = "
         << resultRect.area() << endl;

    // Sử dụng toán tử so sánh <
    cout << "rect1 < rect2? " << boolalpha << (rect1 < rect2) << endl;

    return 0; // Kết thúc chương trình
}