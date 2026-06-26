#include <iostream>  // Nạp thư viện nhập/xuất chuẩn
#include <iomanip>   // Nạp thư viện định dạng (setw, setprecision, fixed, showpoint)
#include <fstream>   // Nạp thư viện làm việc với tệp (ofstream)
using namespace std; // Sử dụng không gian tên chuẩn

// Khai báo nguyên mẫu hàm nhận luồng ghi tệp (ofstream&) dưới dạng tham chiếu và số giới hạn
void printFormatted(ofstream &outfile, int highNum);

int main() // Hàm chính của chương trình
{
    int highNum;                      // Khởi tạo biến lưu số lượng dòng dữ liệu
    cout << "Enter a high number:  "; // Yêu cầu nhập số giới hạn
    cin >> highNum;                   // Nhận giá trị từ bàn phím

    cout << "Writing to file..." << endl; // Thông báo bắt đầu ghi tệp

    // Khởi tạo đối tượng ofstream để mở tệp "output.txt" ghi dữ liệu
    ofstream outfile("output.txt");

    // Kiểm tra xem tệp có mở thành công hay không
    if (!outfile)
    {
        cerr << "Error: Could not open file for writing." << endl; // Báo lỗi nếu không mở được tệp
        return 1;                                                  // Thoát chương trình với mã lỗi
    }

    // Bật cờ cố định phần thập phân (fixed) và hiển thị phần thập phân (showpoint) cho màn hình console
    // khong co showpoint: 5 ; co showpoint 5.00
    cout << fixed << showpoint;
    // Bật cờ cố định phần thập phân và hiển thị phần thập phân cho luồng ghi vào tệp
    outfile << fixed << showpoint;

    printFormatted(outfile, highNum); // Gọi hàm xử lý và truyền luồng tệp cùng với giới hạn
    // outfile << "Hello world!" << endl;

    outfile.close();        // Đóng tệp để lưu dữ liệu và giải phóng tài nguyên
    cout << "Done" << endl; // Thông báo hoàn thành

    return 0; // Báo cáo chương trình kết thúc thành công
}

// Định nghĩa hàm thực hiện tính toán và in kết quả ra cả màn hình lẫn tệp
void printFormatted(ofstream &outfile, int highNum)
{
    for (int i = 1; i <= highNum; i++) // Lặp từ 1 đến highNum
    {
        double value1 = i * 5.7575;  // Tính toán giá trị thứ nhất
        double value2 = i * 3.14159; // Tính toán giá trị thứ hai

        // In định dạng ra màn hình (Console): chiếm 12 khoảng trắng, làm tròn 2 chữ số thập phân
        cout << setw(12) << setprecision(2) << value1
             << setw(12) << setprecision(3) << value2 << endl; // Giá trị 2 chiếm 12 khoảng trắng, làm tròn 3 chữ số

        // In định dạng y hệt như trên nhưng ghi thẳng vào tệp thông qua luồng outfile
        // Dòng lệnh này dùng để định dạng và ghi hai giá trị số (value1 và value2) vào tệp (file) thông qua luồng outfile mà bạn đã mở.
        outfile << setw(12) << setprecision(2) << value1
                << setw(12) << setprecision(3) << value2 << endl;
    }
}

//--
