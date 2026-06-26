#include <iostream>  // Nạp thư viện nhập/xuất chuẩn
using namespace std; // Sử dụng không gian tên chuẩn

int main()
{ // Hàm chính của chương trình

    // int* myIntPtr = new int(123); // (Dòng chú thích) Cấp phát và khởi tạo giá trị 123 luôn
    int *myIntPtr = new int;    // Cấp phát một vùng nhớ động cho kiểu int (chưa có giá trị)
    bool *myBoolPtr = new bool; // Cấp phát một vùng nhớ động cho kiểu bool (chưa có giá trị)

    *myBoolPtr = true; // Gán giá trị true cho vùng nhớ bool mà con trỏ đang trỏ tới

    *myIntPtr = 123; // Gán giá trị 123 cho vùng nhớ int mà con trỏ đang trỏ tới

    cout << *myIntPtr << endl; // In giá trị của vùng nhớ int (in ra: 123)

    cout << boolalpha; // Bật cờ hiển thị kiểu boolean dưới dạng chữ (true/false thay vì 1/0)

    cout << *myBoolPtr << endl; // In giá trị của vùng nhớ bool (in ra: true)

    delete myIntPtr;  // Giải phóng vùng nhớ heap của con trỏ myIntPtr để tránh rò rỉ bộ nhớ (memory leak)
    delete myBoolPtr; // Giải phóng vùng nhớ heap của con trỏ myBoolPtr

    myIntPtr = nullptr;  // Gán con trỏ về null (trỏ vào địa chỉ 0) để tránh trỏ lung tung sau khi xóa
    myBoolPtr = nullptr; // Gán con trỏ về null

    return 0; // Báo cáo chương trình kết thúc thành công
}