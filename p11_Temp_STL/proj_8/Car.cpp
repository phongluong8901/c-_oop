#include "Car.h" // Nạp file header Car.h để nhận diện lớp Car

// Định nghĩa hàm khởi tạo (Constructor)
// Dùng danh sách khởi tạo member initialization list (: color(color), numDoors(numDoors)) để gán giá trị trực tiếp, tối ưu hơn gán trong thân hàm
Car::Car(string color, int numDoors) : color(color), numDoors(numDoors)
{
}

// Định nghĩa phương thức getColor
string Car::getColor() const
{
    // Trả về thuộc tính color của xe
    return color;
}

// Định nghĩa phương thức getNumDoors
int Car::getNumDoors() const
{
    // Trả về thuộc tính numDoors của xe
    return numDoors;
}