#ifndef BUFFER_H // Kiểm tra nếu macro BUFFER_H chưa được định nghĩa
#define BUFFER_H // Định nghĩa macro BUFFER_H để tránh nạp file header nhiều lần

#include <iostream>
#include <cstring> // Thư viện hỗ trợ các hàm thao tác chuỗi như strlen, strcpy_s
using namespace std;

class Buffer
{
public:
    // 1. Constructor thông thường (Cấp phát bộ nhớ động)
    Buffer(const char *input)
    {
        cout << "Constructor called" << endl;
        length = strlen(input);                   // Lấy độ dài chuỗi đầu vào
        data = new char[length + 1];              // Cấp phát vùng nhớ heap cho mảng char
        strcpy_s(data, strlen(input) + 1, input); // Sao chép nội dung vào data một cách an toàn
    } // end ctor

    // 2. Destructor (Hàm hủy - Dọn dẹp bộ nhớ)
    ~Buffer()
    {
        cout << "Destructor called!" << endl;
        delete[] data; // Giải phóng vùng nhớ đã cấp phát bằng new[]
    } // end dtor

    // 3. Copy Constructor (Hàm khởi tạo sao chép)
    // Thực hiện sao chép sâu (deep copy) để đối tượng mới có vùng nhớ riêng biệt
    Buffer(const Buffer &other)
    {
        cout << "Copy constructor called" << endl;
        length = other.length;
        data = new char[length + 1];
        strcpy_s(data, strlen(other.data) + 1, other.data);
    }

    // 4. Copy Assignment Operator (Toán tử gán sao chép)
    Buffer &operator=(const Buffer &other)
    {
        cout << "Copy assignment called" << endl;
        if (this != &other) // Kiểm tra chống tự gán (ví dụ: a = a)
        {
            delete[] data; // Hủy vùng nhớ hiện tại để tránh rò rỉ bộ nhớ
            length = other.length;
            data = new char[length + 1];
            strcpy_s(data, strlen(other.data) + 1, other.data);
        }

        return *this; // Trả về tham chiếu của đối tượng hiện tại
    }

    // 5. Move Constructor (Hàm khởi tạo di chuyển) - Sử dụng rvalue reference (&&)
    // Tiếp quản trực tiếp vùng nhớ của đối tượng cũ mà không cần cấp phát mới hay sao chép tốn kém
    Buffer(Buffer &&other) noexcept
    {
        cout << "Move constructor called" << endl;
        data = other.data;     // Trỏ con trỏ của mình tới vùng nhớ của đối tượng nguồn
        length = other.length; // Chuyển giao độ dài
        other.data = nullptr;  // Vô hiệu hóa đối tượng nguồn bằng cách trỏ về null
        other.length = 0;
    }

    // 6. Move Assignment Operator (Toán tử gán di chuyển)
    Buffer &operator=(Buffer &&other) noexcept
    {
        cout << "Move assignment called" << endl;
        if (this != &other)
        {
            delete[] data;     // Dọn dẹp vùng nhớ cũ của đối tượng đích
            data = other.data; // Tiếp quản vùng nhớ từ đối tượng nguồn
            length = other.length;
            other.data = nullptr; // Vô hiệu hóa nguồn
            other.length = 0;
        }

        return *this;
    }

    // Phương thức in nội dung bộ đệm
    void print() const
    {
        cout << "Buffer contents: " << (data ? data : "null") << endl;
    }

private:
    char *data;    // Con trỏ quản lý mảng ký tự trên heap
    size_t length; // Biến lưu trữ độ dài chuỗi
};

#endif