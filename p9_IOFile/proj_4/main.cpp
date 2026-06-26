#include <iostream>  // Nạp thư viện nhập/xuất chuẩn
#include <fstream>   // Nạp thư viện làm việc với tệp (ifstream)
#include <iomanip>   // Nạp thư viện định dạng (fixed, showpoint, setprecision)
using namespace std; // Sử dụng không gian tên chuẩn

int main() // Hàm chính của chương trình
{
    // Khởi tạo luồng đọc và mở tệp "salaries.txt" trên ổ cứng
    ifstream infile("salaries.txt");

    // Kiểm tra xem tệp có mở thành công hay không
    if (!infile)
    {
        cerr << "Error opening file.  Aborting..." << endl; // Báo lỗi nếu không mở được tệp
        return 1;                                           // Thoát chương trình với mã lỗi
    }

    double salary;            // Khởi tạo biến lưu mức lương đọc từ tệp
    int employeeCount = 0;    // Khởi tạo biến đếm số lượng nhân viên hợp lệ, ban đầu = 0
    double totalSalary = 0.0; // Khởi tạo biến cộng dồn tổng tiền lương, ban đầu = 0.0
    int highEarners = 0;      // Khởi tạo biến đếm nhân viên có lương trên 100,000, ban đầu = 0

    // Vòng lặp đọc từng giá trị lương từ tệp cho đến khi hết dữ liệu
    while (infile >> salary)
    {
        // Bẫy lỗi dữ liệu: nếu lương âm hoặc vượt quá 1 triệu
        if (salary < 0 || salary > 1000000)
        {
            // Bỏ qua (không xử lý) các dòng dữ liệu bị lỗi này và tiếp tục vòng lặp
            continue;
        }

        employeeCount++;       // Tăng số lượng nhân viên hợp lệ thêm 1
        totalSalary += salary; // Cộng dồn mức lương vào tổng quỹ lương

        // Kiểm tra nếu mức lương lớn hơn 100,000
        if (salary > 100000)
        {
            highEarners++; // Tăng biến đếm nhân viên thu nhập cao thêm 1
        }
    } // end while

    infile.close(); // Đóng tệp để giải phóng bộ nhớ

    // Tính lương trung bình (dùng toán tử ba ngôi để tránh lỗi chia cho 0 nếu tệp trống)
    double averageSalary = (employeeCount > 0) ? totalSalary / employeeCount : 0.0;

    // Thiết lập định dạng in số thập phân: cố định dạng và hiển thị đủ phần thập phân với 2 chữ số
    cout << fixed << showpoint << setprecision(2);
    cout << "Employee Salary Report" << endl; // In tiêu đề báo cáo
    cout << "-------------------------------" << endl;
    cout << "Total Employees:               " << employeeCount << endl;  // In tổng số nhân viên hợp lệ
    cout << "Total Payroll:                 $" << totalSalary << endl;   // In tổng quỹ lương
    cout << "Average Salary:                $" << averageSalary << endl; // In lương trung bình
    cout << "Over $100,000 Earners:         " << highEarners << endl;    // In số lượng nhân viên > 100,000

    return 0; // Báo cáo chương trình kết thúc thành công
}