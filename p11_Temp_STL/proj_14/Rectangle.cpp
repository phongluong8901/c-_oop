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