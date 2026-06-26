#include <iostream>  // Nạp thư viện nhập/xuất chuẩn
#include <vector>    // Nạp thư viện vector để quản lý mảng động
#include <fstream>   // Nạp thư viện làm việc với tệp (ifstream)
using namespace std; // Sử dụng không gian tên chuẩn

int main() // Hàm chính của chương trình
{
    int inputNum;       // Khởi tạo biến tạm để lưu số nguyên đọc từ tệp
    int sum = 0;        // Khởi tạo biến tích lũy tổng, gán bằng 0
    vector<int> myInts; // Khởi tạo một vector rỗng chứa các số nguyên

    // Khởi tạo luồng đọc tệp và mở tệp "input.txt" trên ổ cứng
    ifstream infile("input.txt");

    // Kiểm tra xem tệp có mở thành công hay không
    if (!infile)
    {
        cerr << "Could not open file." << endl; // Báo lỗi nếu không tìm thấy tệp
        return 1;                               // Thoát chương trình với mã lỗi
    }

    // Đọc từng số nguyên từ tệp cho đến khi hết tệp (EOF) hoặc đọc thất bại
    // Cách này an toàn và chuẩn xác hơn cách dùng while(!infile.eof())
    while (infile >> inputNum)
    {
        myInts.push_back(inputNum); // Thêm số vừa đọc vào cuối vector myInts
        sum += inputNum;            // Cộng dồn giá trị vào biến tổng
    } // end while

    // Vòng lặp range-based for duyệt qua từng phần tử trong vector để in ra màn hình
    for (int num : myInts)
    {
        cout << num << endl; // In giá trị phần tử
    }

    cout << "Sum of numbers is: " << sum << endl; // In tổng các số

    infile.close(); // Đóng luồng tệp để giải phóng tài nguyên hệ thống

    return 0; // Báo cáo chương trình kết thúc thành công
}