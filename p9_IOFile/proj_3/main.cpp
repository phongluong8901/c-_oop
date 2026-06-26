#include <iostream>  // Nạp thư viện nhập/xuất chuẩn
#include <fstream>   // Nạp thư viện làm việc với tệp (ifstream, ofstream)
#include <string>    // Nạp thư viện xử lý chuỗi
using namespace std; // Sử dụng không gian tên chuẩn

int main() // Hàm chính của chương trình
{
    // Khởi tạo và mở tệp tên "names.txt" ở chế độ đọc
    ifstream nameFile("names.txt");
    // Khởi tạo và mở tệp tên "ages.txt" ở chế độ đọc
    ifstream ageFile("ages.txt");
    // Khởi tạo và mở tệp tên "output.txt" ở chế độ ghi
    ofstream outfile("output.txt");

    // Kiểm tra xem cả 2 tệp đầu vào có mở thành công hay không
    if (!nameFile || !ageFile)
    {
        cerr << "Problem opening one of the input files.  Exiting." << endl; // Báo lỗi nếu có tệp không mở được
        return 1;                                                            // Thoát chương trình với mã lỗi
    }

    string tempName; // Khởi tạo biến tạm chứa tên đọc từ tệp
    int tempAge;     // Khởi tạo biến tạm chứa tuổi đọc từ tệp

    // Vòng lặp đọc song song: lấy một dòng tên kết hợp với lấy một số tuổi
    // Điều kiện && đảm bảo chỉ ghi file khi đọc thành công cả tên lẫn tuổi cùng lúc
    while (getline(nameFile, tempName) && (ageFile >> tempAge))
    {
        // Ghi cặp dữ liệu (Tên + Tuổi) vào tệp output.txt cách nhau bởi khoảng trắng
        outfile << tempName << " " << tempAge << endl;
    }

    nameFile.close();                              // Đóng luồng tệp names.txt
    ageFile.close();                               // Đóng luồng tệp ages.txt
    outfile.close();                               // Đóng luồng tệp output.txt
    cout << "Done writing to output.txt!" << endl; // Thông báo hoàn tất

    return 0; // Báo cáo chương trình kết thúc thành công
}