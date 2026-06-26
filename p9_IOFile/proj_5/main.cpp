#include <iostream>  // Nạp thư viện nhập/xuất
#include <fstream>   // Nạp thư viện đọc tệp
#include <vector>    // Nạp thư viện vector quản lý mảng động
#include <iomanip>   // Nạp thư viện định dạng setw, left, setprecision...
#include "Student.h" // Nạp file header lớp Student
using namespace std;

int main()
{
    // Mở tệp "students.txt" ở chế độ đọc
    ifstream infile("students.txt");

    // Bẫy lỗi nếu không tìm thấy tệp
    if (!infile)
    {
        cerr << "Failed to open students.txt" << endl;
        return 1;
    }

    // Khai báo vector chứa các con trỏ kiểu Student* (quản lý địa chỉ các đối tượng trên Heap)
    // mảng động (vector) chứa các con trỏ trỏ đến đối tượng Student
    vector<Student *> roster;
    string first; // Biến tạm lưu tên
    string last;  // Biến tạm lưu họ
    double gpa;   // Biến tạm lưu điểm

    // Đọc đồng thời 3 giá trị (Họ, Tên, Điểm) từ tệp cho đến khi hết dữ liệu
    while (infile >> first >> last >> gpa)
    {
        // Kiểm tra tính hợp lệ của điểm GPA (thang điểm từ 0.0 đến 4.0)
        if (gpa >= 0.0 && gpa <= 4.0)
        {
            // Cấp phát động đối tượng Student trên Heap và đưa địa chỉ của nó vào vector
            Student *s = new Student(first, last, gpa);
            roster.push_back(s);
        }
    }

    // Đóng luồng tệp
    infile.close();

    // Thiết lập hiển thị số thập phân với độ chính xác 2 chữ số
    cout << fixed << showpoint << setprecision(2);
    cout << "Student Roster: " << endl;
    cout << "---------------------------------" << endl;

    double sum = 0; // Khởi tạo biến cộng dồn điểm GPA
    int honors = 0; // Khởi tạo biến đếm số học sinh đạt danh hiệu Honor Roll

    // Duyệt qua từng con trỏ Student* trong vector bằng range-based for loop
    for (Student *s : roster)
    {
        // Sử dụng toán tử -> để truy xuất hàm thành viên của đối tượng thông qua con trỏ.
        // setw(20) căn lề trái 20 khoảng trắng cho tên học sinh.
        cout << setw(20) << left << s->getFullName()
             << "GPA: " << s->getGPA() << endl;

        sum += s->getGPA(); // Cộng dồn điểm

        // Kiểm tra điều kiện học sinh danh dự (GPA >= 3.5)
        if (s->getGPA() >= 3.5)
        {
            honors++; // Tăng biến đếm học sinh danh dự
        }
    } // end for

    // Tính điểm trung bình GPA (dùng toán tử ba ngôi chặn lỗi chia cho 0 nếu vector rỗng)
    double avgGPA = (roster.size() > 0) ? sum / roster.size() : 0.0;

    cout << "\nClass Average GPA: " << avgGPA << endl; // In điểm trung bình lớp
    cout << "Honor Roll Students: " << honors << endl; // In tổng số học sinh danh dự

    // === DỌN DẸP BỘ NHỚ (CLEANUP) ===
    // 1. Hủy từng đối tượng được tạo bằng từ khóa new trên vùng nhớ Heap
    for (Student *s : roster)
    {
        delete s;
    }

    // 2. Xóa sạch các con trỏ bên trong vector, đưa vector về kích thước 0
    roster.clear();

    return 0; // Báo cáo chương trình kết thúc thành công
}