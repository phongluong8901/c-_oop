#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
public:
    Rectangle();
    Rectangle(double length, double width);
    double getLength() const;
    double getWidth() const;
    void setLength(double length);
    void setWidth(double width);
    double area() const;
    double perimeter() const;

    // Khai báo các toán tử được nạp chồng (overloaded operators)

    // So sánh bằng: Kiểm tra xem hai hình chữ nhật có cùng chiều dài và chiều rộng không
    bool operator==(const Rectangle &other) const;

    // So sánh khác: Gọi lại toán tử == và phủ định kết quả
    bool operator!=(const Rectangle &other) const;

    // So sánh nhỏ hơn: So sánh dựa trên diện tích (area)
    bool operator<(const Rectangle &other) const;

    // Cộng hai hình chữ nhật: Tạo ra một hình chữ nhật mới với chiều dài và rộng cộng dồn
    Rectangle operator+(const Rectangle &other) const;

    // Gán: Gán giá trị từ đối tượng khác cho đối tượng hiện tại
    void operator=(const Rectangle &other);

private:
    double length;
    double width;
};

#endif