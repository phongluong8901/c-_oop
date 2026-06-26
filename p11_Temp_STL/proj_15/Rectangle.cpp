#include "Rectangle.h"

// Constructor mặc định, khởi tạo chiều dài và chiều rộng bằng 1
Rectangle::Rectangle()
{
    length = 1;
    width = 1;
}

// Constructor có tham số
Rectangle::Rectangle(double length, double width)
{
    this->length = length;
    this->width = width;
}

double Rectangle::getLength() const
{
    return length;
}

double Rectangle::getWidth() const
{
    return width;
}

void Rectangle::setLength(double length)
{
    this->length = length;
}

void Rectangle::setWidth(double width)
{
    this->width = width;
}

double Rectangle::area() const
{
    return length * width;
}

double Rectangle::perimeter() const
{
    return 2 * (length + width);
}

// Định nghĩa toán tử ==
bool Rectangle::operator==(const Rectangle &other) const
{
    return length == other.length && width == other.width;
}

// Định nghĩa toán tử !=
bool Rectangle::operator!=(const Rectangle &other) const
{
    return !(*this == other); // Sử dụng lại toán tử == hiện tại và phủ định nó
}

// Định nghĩa toán tử < (so sánh diện tích)
bool Rectangle::operator<(const Rectangle &other) const
{
    return this->area() < other.area();
}

// Định nghĩa toán tử +
Rectangle Rectangle::operator+(const Rectangle &other) const
{
    // Trỏ về một đối tượng Rectangle mới với các thuộc tính cộng dồn
    return Rectangle(length + other.length, width + other.width);
}

// Định nghĩa toán tử gán =
void Rectangle::operator=(const Rectangle &other)
{
    length = other.length;
    width = other.width;
}