#include <iostream>  // Nạp thư viện nhập/xuất chuẩn
using namespace std; // Sử dụng không gian tên chuẩn

void noChange(const double *const someValue); // Khai báo nguyên mẫu hàm không thể thay đổi địa chỉ lẫn dữ liệu

void noConst(); // 1. Con trỏ thường trỏ đến dữ liệu thường
void cp2ncd();  // 2. Con trỏ hằng trỏ đến dữ liệu thường
void ncp2cd();  // 3. Con trỏ thường trỏ đến dữ liệu hằng
void cp2cd();   // 4. Con trỏ hằng trỏ đến dữ liệu hằng

int main()
{ // Hàm chính của chương trình

    double *myDubz = new double(5.25); // Cấp phát động biến double mang giá trị 5.25

    noConst();    // Gọi hàm 1
    cout << endl; // In dòng trống

    cp2ncd();     // Gọi hàm 2
    cout << endl; // In dòng trống

    ncp2cd();     // Gọi hàm 3
    cout << endl; // In dòng trống

    cp2cd();      // Gọi hàm 4
    cout << endl; // In dòng trống

    noChange(myDubz); // Gọi hàm truyền con trỏ vào hàm bảo vệ kép

    delete myDubz;    // Giải phóng bộ nhớ heap
    myDubz = nullptr; // Trỏ con trỏ về null

    return 0; // Báo cáo chương trình kết thúc thành công
}

// Định nghĩa hàm bảo vệ kép: Không đổi được địa chỉ con trỏ (const thứ hai) và không sửa được giá trị dữ liệu (const thứ nhất)
void noChange(const double *const someValue)
{
    cout << *someValue << endl; // Chỉ được phép đọc giá trị in ra màn hình
}

// 1. non-const pointer to non-const data (Con trỏ thường trỏ tới dữ liệu thường)
void noConst()
{
    cout << "In noConst" << endl;

    int *intPtr = new int(50);                      // Cấp phát động ô nhớ nguyên giữ giá trị 50
    cout << "\toriginal value:" << *intPtr << endl; // In giá trị ban đầu: 50

    *intPtr = 100;                                 // Sửa được giá trị dữ liệu (thành 100)
    cout << "\tchanged data: " << *intPtr << endl; // In giá trị mới: 100

    delete intPtr; // Hủy vùng nhớ cũ

    intPtr = new int(125);                             // Trỏ sang vùng nhớ mới hoàn toàn chứa 125 (đổi được cả địa chỉ con trỏ)
    cout << "\tnew int entirely: " << *intPtr << endl; // In giá trị mới: 125

    delete intPtr; // Hủy vùng nhớ mới
}

// 2. const pointer to non-const data (Con trỏ hằng trỏ tới dữ liệu thường)
void cp2ncd()
{
    cout << "In cp2ncd" << endl;

    int *const intPtr = new int(100); // Khởi tạo con trỏ hằng trỏ tới ô nhớ giá trị 100 (địa chỉ con trỏ này cố định không trỏ đi đâu khác được)

    cout << "\toriginal value: " << *intPtr << endl; // In giá trị: 100

    *intPtr = 250;                                   // Cho phép sửa đổi dữ liệu bên trong (sửa thành 250)
    cout << "\tmodified value: " << *intPtr << endl; // In giá trị: 250

    // intPtr = new int(222); // LỖI: Không thể thay đổi địa chỉ con trỏ vì con trỏ bị khóa const

    delete intPtr; // Giải phóng bộ nhớ
}

// 3. non-const pointer to const data (Con trỏ thường trỏ tới dữ liệu hằng)
void ncp2cd()
{
    cout << "In ncp2cd" << endl;

    const int *intPtr = new int(500);                // Khởi tạo con trỏ trỏ tới vùng dữ liệu kiểu hằng (mang giá trị 500)
    cout << "\toriginal value: " << *intPtr << endl; // In giá trị: 500

    // *intPtr = 600; // LỖI: Không thể dùng con trỏ này để sửa giá trị 500 thành 600 vì dữ liệu được bảo vệ như hằng số

    delete intPtr; // Giải phóng ô nhớ cũ

    intPtr = new int(1000);                     // HỢP LỆ: Con trỏ thường nên có thể chuyển hướng trỏ sang ô nhớ hoàn toàn mới (chứa 1000)
    cout << "\tnew value: " << *intPtr << endl; // In giá trị: 1000

    delete intPtr; // Giải phóng ô nhớ mới
}

// 4. const pointer to const data (Con trỏ hằng trỏ tới dữ liệu hằng)
void cp2cd()
{
    cout << "In cp2cd" << endl;

    const int *const intPtr = new int(5000); // Khóa toàn diện: Không sửa được dữ liệu (const trước) và không đổi được địa chỉ trỏ (const sau)

    cout << "\toriginal value: " << *intPtr << endl; // In giá trị: 5000

    //  *intPtr = 6000;    // LỖI: Dữ liệu là hằng, không được phép thay đổi nội dung
    // intPtr = new int(6000);  // LỖI: Địa chỉ con trỏ là hằng, không cho phép trỏ sang vùng nhớ khác

    delete intPtr; // Giải phóng bộ nhớ
}