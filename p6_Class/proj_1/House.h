#ifndef HOUSE_H
#define HOUSE_H

using namespace std;

#include <string>
class House
{
public:
    void setNumStories(int numStories);

    void setNumWindows(int numWindows);

    void setColor(string color);

    int getNumStories() const;

    int getNumWindows() const;

    string getColor() const;

    void print() const;

private:
    int numStories;
    int numWindows;
    string color;
};

#endif // HOUSE_H

// Đoạn code #ifndef, #define và #endif trong file .h được gọi là Include Guard (hoặc Macro Guard).

// Đây là một kỹ thuật bắt buộc trong C++ để ngăn chặn lỗi "Redefinition" (định nghĩa lại) khi dự án của bạn trở nên lớn hơn.

// #ifndef HOUSE_H    // Nếu (IF) chưa (N) định nghĩa (DEF) từ khóa HOUSE_H
// #define HOUSE_H    // Thì hãy định nghĩa (DEFINE) từ khóa HOUSE_H ngay bây giờ
// ... Toàn bộ nội dung class House nằm ở đây ...

// #endif             // Kết thúc khối điều kiện của #ifndef