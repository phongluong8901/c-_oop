#include <iostream>
#include <memory>  // Thư viện bắt buộc để sử dụng smart pointers (unique_ptr, make_unique)
#include <utility> // Thư viện hỗ trợ hàm std::move
using namespace std;

int main()
{
    // Khởi tạo hằng số kích thước mảng bằng 5 (hiện đang bị ẩn ở các dòng comment dưới)
    const int ARR_SIZE = 5;

    // Cách 1 (cũ): unique_ptr<double> myDubPtr(new double);
    // Cách 2 (chuẩn từ C++14): Khởi tạo một con trỏ độc quyền quản lý vùng nhớ kiểu double
    unique_ptr<double> myDubPtr = make_unique<double>();
    // auto myArray = make_unique<int[]>(ARR_SIZE); // Khởi tạo mảng động dùng unique_ptr

    // Gán giá trị 3.14 vào vùng nhớ mà myDubPtr đang trỏ tới
    *myDubPtr = 3.14;

    // In ra giá trị lưu tại vùng nhớ của con trỏ
    cout << "Pointer value: " << *myDubPtr << endl;

    // Chuyển quyền sở hữu vùng nhớ từ myDubPtr sang cho otherPtr
    // Sau dòng này, myDubPtr sẽ trở thành nullptr (trỏ tới rỗng) và mất quyền truy cập dữ liệu
    unique_ptr<double> otherPtr = move(myDubPtr);

    // In ra giá trị thông qua otherPtr để chứng minh dữ liệu đã được chuyển sang
    cout << "otherPtr: " << *otherPtr << endl;

    // Các khối lệnh dưới đây bị chú thích (comment), dùng để minh họa cách tạo và duyệt mảng động với smart pointer
    // for (int i = 0; i < ARR_SIZE; i++) {
    //  myArray[i] = i * 2;
    // }

    // for (int i = 0; i < ARR_SIZE; i++) {
    //  cout << myArray[i] << endl;
    // }

    // Trả về 0 để kết thúc chương trình thành công
    return 0;
}