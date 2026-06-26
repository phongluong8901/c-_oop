#include <iostream>
#include "RulesDemo.h" // Nạp file header chứa các lớp phân tích

int main()
{
    // Minh họa Rule of Three (Quy tắc Ba)
    cout << "\n--- Rule of Three ---" << endl;
    RuleOfThree a("Alpha"); // Gọi constructor thường -> Cấp phát vùng nhớ cho "Alpha"
    RuleOfThree b = a;      // Gọi Copy Constructor -> Sao chép nội dung "Alpha" sang cho b
    b = a;                  // Gọi Copy Assignment Operator -> Gán đè nội dung

    // Minh họa Rule of Five (Quy tắc Năm)
    cout << "\n--- Rule of Five ---" << endl;
    RuleOfFive c("Beta");   // Gọi constructor thường
    RuleOfFive d = move(c); // Gọi Move Constructor -> Di chuyển dữ liệu từ c sang d, c bị vô hiệu (trỏ tới null)
    RuleOfFive e;           // Khởi tạo đối tượng e mặc định ("default")
    e = move(d);            // Gọi Move Assignment Operator -> Di chuyển dữ liệu từ d sang e

    // Minh họa Rule of Zero (Quy tắc Không)
    cout << "\n--- Rule of Zero ---" << endl;
    RuleOfZero f("Gamma"); // Khởi tạo f quản lý bởi smart pointer
    f.print();             // In nội dung bên trong f

    return 0; // Kết thúc chương trình, các biến sẽ tự động gọi Destructor theo thứ tự ngược lại khi ra khỏi scope
}