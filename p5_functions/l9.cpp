// ProductArrayByReference

#include <iostream>  // Nạp thư viện nhập/xuất chuẩn
#include <array>     // Nạp thư viện mảng tĩnh
using namespace std; // Sử dụng không gian tên chuẩn

int productArray(array<int, 6> myArray);               // Bản 1: Trả về tích qua lệnh return (tham trị)
void productArray(array<int, 6> myArray, int &result); // Bản 2: Trả về kết quả qua tham chiếu &result

int main() // Hàm chính của chương trình
{
    array<int, 6> numbers{1, 2, 3, 4, 5, 6}; // Khởi tạo mảng tĩnh gồm 6 số nguyên

    int finalProduct;                    // Khai báo biến lưu kết quả
    productArray(numbers, finalProduct); // Gọi Bản 2: Truyền mảng và biến tham chiếu. Kết quả tính toán sẽ được cập nhật trực tiếp vào finalProduct

    cout << "The product of the array elements (by reference) is: " << finalProduct << endl; // In ra tích (kết quả: 720)

    /*int result = productArray(numbers); // Đoạn code gọi Bản 1 (nếu bỏ dấu //)

    cout << "The product of the array elements is: " << result << endl;*/

    return 0; // Kết thúc hàm main thành công
}

int productArray(array<int, 6> myArray) // Định nghĩa Bản 1
{
    int product = 1; // Khởi tạo biến tích bằng 1

    for (int num : myArray) // Duyệt qua từng phần tử
    {
        product *= num; // Nhân dồn vào biến cục bộ
    }

    return product; // Trả về kết quả cho nơi gọi
}

void productArray(array<int, 6> myArray, int &result) // Định nghĩa Bản 2
{
    result = 1; // Khởi tạo biến kết quả gốc bằng 1

    for (int num : myArray) // Duyệt qua từng phần tử
    {
        result *= num; // Nhân dồn trực tiếp vào ô nhớ của biến result ngoài main
    }
}

// iải thích nhanh về điểm nổi bật trong code:
// Nạp chồng hàm (Function Overloading): Cả hai hàm đều tên là productArray nhưng khác nhau về kiểu trả về và tham số. Trình biên dịch sẽ tự biết chọn hàm nào dựa vào cách bạn gọi.

// Truyền tham chiếu (int &result): Ở Bản 2, nhờ dấu &, hàm không cần dùng return mà vẫn đưa được kết quả 720 ra ngoài hàm main bằng cách ghi đè trực tiếp vào ô nhớ của biến finalProduct.