#include <iostream>
#include <memory> // Thư viện cần thiết để sử dụng make_unique
#include "Car.h"  // Nạp file định nghĩa lớp Car

using namespace std;

int main()
{
    // Khởi tạo một con trỏ độc quyền (unique_ptr) quản lý đối tượng Car động
    // Truyền trực tiếp tham số "red" (màu đỏ) và 4 (số cửa) vào hàm khởi tạo của Car
    auto myCarPtr = make_unique<Car>("red", 4);

    // Truy xuất phương thức getColor thông qua toán tử mũi tên (->) và in ra màn hình
    cout << "Color: " << myCarPtr->getColor() << endl;

    // Truy xuất phương thức getNumDoors thông qua toán tử mũi tên (->) và in ra màn hình
    cout << "Doors: " << myCarPtr->getNumDoors() << endl;

    // Trả về 0 để kết thúc chương trình thành công
    return 0;
}