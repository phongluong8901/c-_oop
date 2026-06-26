#ifndef RULES_DEMO_H // Kiểm tra nếu macro chưa được định nghĩa
#define RULES_DEMO_H // Định nghĩa macro để tránh nạp header nhiều lần

#include <iostream>
#include <cstring> // Thư viện hỗ trợ hàm strlen, strcpy_s
#include <memory>  // Thư viện hỗ trợ smart pointer (make_unique)

using namespace std;

// ==========================================
// 1. RULE OF THREE (Quy tắc Ba)
// Dùng khi lớp tự quản lý bộ nhớ (cấp phát bằng new[])
// Cần định nghĩa đủ 3 hàm đặc biệt: Copy Constructor, Copy Assignment, và Destructor
// ==========================================
class RuleOfThree
{
public:
    // Constructor mặc định hoặc có tham số
    RuleOfThree(const char *text = "default")
    {
        // Cấp phát bộ nhớ động cho mảng char dựa trên độ dài chuỗi + 1 (ký tự kết thúc chuỗi '\0')
        data = new char[strlen(text) + 1];
        // Sao chép chuỗi an toàn vào vùng nhớ data
        strcpy_s(data, strlen(text) + 1, text);
        cout << "[Three] Constructed with: " << data << endl;
    }

    // 1. Copy Constructor (Hàm khởi tạo sao chép)
    // Thực hiện deep copy (sao chép sâu) để tránh hai đối tượng trỏ chung một vùng nhớ
    RuleOfThree(const RuleOfThree &other)
    {
        data = new char[strlen(other.data) + 1];
        strcpy_s(data, strlen(other.data) + 1, other.data);
        cout << "[Three] Copied: " << data << endl;
    }

    // 2. Copy Assignment Operator (Toán tử gán sao chép)
    RuleOfThree &operator=(const RuleOfThree &other)
    {
        // Kiểm tra tự gán (ví dụ: a = a) để tránh lỗi xóa nhầm dữ liệu
        if (this != &other)
        {
            // Hủy vùng nhớ cũ đang trỏ tới để tránh rò rỉ bộ nhớ (memory leak)
            delete[] data;
            // Cấp phát vùng nhớ mới tương ứng với dữ liệu được gán
            data = new char[strlen(other.data) + 1];
            strcpy_s(data, strlen(other.data) + 1, other.data);
        }
        cout << "[Three] Assigned: " << data << endl;
        return *this; // Trả về tham chiếu của đối tượng hiện tại
    }

    // 3. Destructor (Hàm hủy)
    // Giải phóng bộ nhớ đã cấp phát bằng new[] khi đối tượng bị hủy
    ~RuleOfThree()
    {
        cout << "[Three] Destroyed: " << data << endl;
        delete[] data;
    }

private:
    char *data; // Con trỏ quản lý vùng nhớ cấp phát động
};

// ==========================================
// 2. RULE OF FIVE (Quy tắc Năm)
// Mở rộng từ Rule of Three, hỗ trợ thêm ngữ cảnh di chuyển (Move semantics) trong C++11
// Bao gồm: Copy Constructor, Copy Assignment, Move Constructor, Move Assignment và Destructor
// ==========================================
class RuleOfFive
{

public:
    // Constructor mặc định, cấp phát bộ nhớ động
    RuleOfFive(const char *text = "default")
    {
        data = new char[strlen(text) + 1];
        strcpy_s(data, strlen(text) + 1, text);
        cout << "[Five] Constructed with: " << data << endl;
    }

    // Copy Constructor (Sao chép)
    RuleOfFive(const RuleOfFive &other)
    {
        data = new char[strlen(other.data) + 1];
        strcpy_s(data, strlen(other.data) + 1, other.data);
        cout << "[Five] Copied: " << data << endl;
    }

    // Copy Assignment Operator (Toán tử gán sao chép)
    RuleOfFive &operator=(const RuleOfFive &other)
    {
        if (this != &other)
        {
            delete[] data;
            data = new char[strlen(other.data) + 1];
            strcpy_s(data, strlen(other.data) + 1, other.data);
        }
        cout << "[Five] Copy-assigned: " << data << endl;
        return *this;
    }

    // 4. Move Constructor (Hàm khởi tạo di chuyển) - dùng && (rvalue reference)
    // Chuyển giao quyền sở hữu tài nguyên, không tạo bản sao tốn kém
    RuleOfFive(RuleOfFive &&other) noexcept
    {
        data = other.data;    // Trỏ con trỏ của mình tới vùng nhớ của đối tượng cũ
        other.data = nullptr; // Đặt con trỏ đối tượng cũ về rỗng để tránh bị hủy kép
        cout << "[Five] Moved!" << endl;
    }

    // 5. Move Assignment Operator (Toán tử gán di chuyển)
    RuleOfFive &operator=(RuleOfFive &&other) noexcept
    {
        if (this != &other)
        {
            delete[] data;        // Dọn dẹp vùng nhớ hiện tại của đối tượng nhận gán
            data = other.data;    // Tiếp quản vùng nhớ
            other.data = nullptr; // Vô hiệu hóa nguồn
        }
        cout << "[Five] Move-assigned!" << endl;
        return *this;
    }

    // Destructor (Hàm hủy)
    ~RuleOfFive()
    {
        cout << "[Five] Destroyed: " << (data ? data : "null") << endl;
        delete[] data;
    }

private:
    char *data;
};

// ==========================================
// 3. RULE OF ZERO (Quy tắc Không)
// Khuyên dùng trong C++ hiện đại. Không cần định nghĩa bất kỳ hàm hủy, copy hay move nào.
// Các đối tượng tự động quản lý tài nguyên thông qua Smart Pointers (như unique_ptr, shared_ptr) hoặc standard containers (vector, string).
// ==========================================
class RuleOfZero
{
public:
    RuleOfZero(const char *text = "default")
    {
        // Khởi tạo mảng động thông qua unique_ptr, tự động giải phóng khi đối tượng ra khỏi phạm vi
        data = make_unique<char[]>(strlen(text) + 1);
        strcpy_s(data.get(), strlen(text) + 1, text);
        cout << "[Zero] Constructed with: " << data.get() << endl;
    }

    // Không cần viết Copy/Move constructor hay Destructor
    // Trình biên dịch sẽ tự động tạo các hàm quản lý tài nguyên an toàn ngầm định

    void print() const
    {
        cout << "[Zero] Content: " << data.get() << endl;
    }

private:
    unique_ptr<char[]> data; // Con trỏ thông minh quản lý mảng ký tự
};

#endif