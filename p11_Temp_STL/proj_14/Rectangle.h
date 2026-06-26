#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
    // Khai báo changeData và printData là các hàm bạn (friend functions)
    // Chúng có quyền truy cập trực tiếp vào các thuộc tính private của lớp Rectangle
    friend void changeData(Rectangle &rect);
    friend void printData(Rectangle &rect);

    // Khai báo RectangleHelper là lớp bạn (friend class)
    // Mọi phương thức bên trong RectangleHelper đều có quyền truy cập private members của Rectangle
    friend class RectangleHelper;

public:
    Rectangle();
    Rectangle(double length, double width);
    double getLength() const;
    double getWidth() const;
    void setLength(double length);
    void setWidth(double width);
    double area() const;
    double perimeter() const;

private:
    double length; // Thuộc tính ẩn (private)
    double width;  // Thuộc tính ẩn (private)
};

#endif

//
// 2. Tại sao changeData(r1); vẫn nằm trong main() mà lại tác động được?
// Bởi vì trong Rectangle.h, bạn đã "bắn một tín hiệu" khai báo:
// friend void changeData(Rectangle &rect);

// friend (Hàm bạn): Giống như bạn cấp cho hàm changeData một chiếc thẻ đặc quyền. Bình thường, hàm ngoài không được phép sờ vào dữ liệu private (như length, width) của r1. Nhưng nhờ có từ khóa friend, hàm changeData được phép nhảy thẳng vào vùng nhớ của r1 để sửa giá trị.

// Dấu & trong Rectangle &rect (Tham chiếu): Đây là chìa khóa thứ hai. Khi bạn truyền r1 vào, hàm không tạo ra bản sao nào cả, mà nó thao tác trực tiếp trên chính khối bộ nhớ gốc của r1 ngoài main().

//---
// Lý do bắt buộc phải khai báo các dòng đó trong file .h là vì trong lập trình C++, các hàm và lớp bên ngoài mặc định không được phép chạm vào vùng dữ liệu riêng tư (private) của một lớp.

// Hãy tưởng tượng lớp Rectangle giống như một ngôi nhà có két sắt (private chứa length và width).

// Nếu không có khai báo friend, bất kỳ ai (các hàm ngoài, lớp ngoài) muốn lấy hoặc sửa kích thước đều phải đi qua "cửa chính" là các hàm public (như setLength(), area()). Họ hoàn toàn không thể nhìn thấy hay sửa trực tiếp hai biến đó.

// Khi bạn viết lệnh friend, nó giống như việc bạn cấp cho họ một đặc quyền và chìa khóa riêng.

// friend void changeData(...) và friend void printData(...): Cấp chìa khóa cho hai hàm này để chúng có thể tự do đọc/ghi thẳng vào length và width của hình chữ nhật.

// friend class RectangleHelper: Cấp chìa khóa tổng cho toàn bộ lớp RectangleHelper để các phương thức trong đó có thể tác động trực tiếp lên dữ liệu mật của Rectangle.

// Nếu bạn xóa các dòng khai báo friend này đi và vẫn giữ nguyên code trong main.cpp (như cố tình gõ rect.length = 100 bên trong hàm changeData), trình biên dịch sẽ lập tức báo lỗi đỏ lòm vì vi phạm tính bảo mật đóng gói của hướng đối tượng.