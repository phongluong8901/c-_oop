#ifndef STUDENT_H // Kiểm tra tiền xử lý tránh định nghĩa trùng lặp
#define STUDENT_H

#include <string> // Nạp thư viện chuỗi
using namespace std;

class Student // Khai báo lớp Student
{
public:
    Student(string firstName, string lastName, double gpa); // Hàm khởi tạo nhận họ, tên và điểm GPA
    string getFullName() const;                             // Hàm lấy tên đầy đủ
    double getGPA() const;                                  // Hàm lấy điểm GPA

private:
    string firstName; // Biến thành viên lưu tên
    string lastName;  // Biến thành viên lưu họ
    double gpa;       // Biến thành viên lưu điểm
};

#endif