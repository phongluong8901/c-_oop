#include <iostream>  // Nạp thư viện nhập/xuất chuẩn
using namespace std; // Sử dụng không gian tên chuẩn

int main() // Hàm chính của chương trình
{

    int myLovelyInt = 150;         // Khởi tạo biến số nguyên mang giá trị 150
    int *somePtr = &myLovelyInt;   // Khởi tạo con trỏ kiểu int, lưu địa chỉ (&) của biến myLovelyInt
    double myDouble = 3.14;        // Khởi tạo biến số thực mang giá trị 3.14
    double *doublePtr = &myDouble; // Khởi tạo con trỏ kiểu double, lưu địa chỉ (&) của biến myDouble

    cout << "myLovelyInt is originally: " << myLovelyInt << endl; // In giá trị ban đầu: 150
    cout << "pointer holds value: " << somePtr << endl;           // In địa chỉ bộ nhớ mà con trỏ đang trỏ tới (ví dụ: 0x...)
    cout << "pointer dereferenced: " << *somePtr << endl;         // Truy xuất giá trị tại địa chỉ đó (giá trị: 150)

    *somePtr = 200; // Thay đổi giá trị của biến myLovelyInt thông qua con trỏ (đổi thành 200)

    cout << "myLovelyInt is now: " << myLovelyInt << endl; // In giá trị mới của biến: 200

    cout << doublePtr << endl;  // In địa chỉ bộ nhớ của biến myDouble
    cout << *doublePtr << endl; // Truy xuất giá trị của biến myDouble (giá trị: 3.14)

    return 0; // Báo cáo chương trình kết thúc thành công
}