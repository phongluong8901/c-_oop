#include <iostream>  // Nạp thư viện nhập/xuất chuẩn
using namespace std; // Sử dụng không gian tên chuẩn

int main()
{ // Hàm chính của chương trình

    const int ARR_SIZE = 5; // Khởi tạo hằng số kích thước mảng (không thay đổi được giá trị)
    int arrSize = 0;        // Khởi tạo biến lưu kích thước mảng nhập từ bàn phím, gán bằng 0

    cout << "Please enter an array size: "; // In yêu cầu nhập kích thước mảng
    cin >> arrSize;                         // Nhận giá trị kích thước mảng từ người dùng

    int *myArray = new int[arrSize]; // Cấp phát động một mảng số nguyên trên Heap với kích thước vừa nhập

    for (int i = 0; i < arrSize; i++)
    {                       // Vòng lặp duyệt qua từng phần tử của mảng từ 0 đến arrSize - 1
        myArray[i] = i * 2; // Gán giá trị cho phần tử tại vị trí i bằng i nhân 2
    }

    for (int i = 0; i < arrSize; i++)
    {                               // Vòng lặp in các phần tử trong mảng
        cout << myArray[i] << endl; // In giá trị của phần tử tại vị trí i ra màn hình
    }

    delete[] myArray;  // Hủy/giải phóng toàn bộ vùng nhớ mảng động đã cấp phát để tránh rò rỉ bộ nhớ
    myArray = nullptr; // Gán con trỏ về null (trỏ địa chỉ 0) tránh lỗi truy cập vùng nhớ đã bị xóa

    return 0; // Báo cáo chương trình kết thúc thành công
}