#include "Student.h" // Nạp file header

// Định nghĩa hàm khởi tạo đối tượng Student
Student::Student(string firstName, string lastName, double gpa)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->gpa = gpa;
}

// Kết hợp chuỗi họ và tên trả về tên hoàn chỉnh
string Student::getFullName() const
{
    return firstName + " " + lastName;
}

// Trả về điểm số gpa
double Student::getGPA() const
{
    return gpa;
}