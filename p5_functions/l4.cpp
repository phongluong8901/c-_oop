// FunctionOverloading

#include <iostream>  // Nạp thư viện nhập/xuất chuẩn
#include <string>    // Nạp thư viện hỗ trợ chuỗi (string)
using namespace std; // Sử dụng không gian tên chuẩn

// Khai báo các nguyên mẫu hàm (Function Overloading - Nạp chồng hàm)
int getResult(int num1, int num2);          // Bản 1: Nhận 2 số nguyên, trả về nguyên
string getResult(string str1, string str2); // Bản 2: Nhận 2 chuỗi, trả về chuỗi
int getResult(int num);                     // Bản 3: Nhận 1 số nguyên, trả về nguyên

int main() // Hàm chính của chương trình
{
    int resultNum = getResult(30, 20);              // Gọi Bản 1: Truyền 2 số nguyên, trả về tích (600)
    string nameResult = getResult("John", "Baugh"); // Gọi Bản 2: Truyền 2 chuỗi, trả về chuỗi nối ("John Baugh")
    int cubeResult = getResult(5);                  // Gọi Bản 3: Truyền 1 số nguyên, trả về lập phương (125)

    cout << "result num is " << resultNum << endl;   // In kết quả 1
    cout << "name result is " << nameResult << endl; // In kết quả 2
    cout << "cube result is " << cubeResult << endl; // In kết quả 3

    return 0; // Kết thúc hàm main thành công
}

// Định nghĩa chi tiết các hàm
int getResult(int num1, int num2)
{
    return num1 * num2; // Trả về tích của 2 số nguyên
}

string getResult(string str1, string str2)
{
    return str1 + " " + str2; // Nối 2 chuỗi lại với nhau, cách nhau bởi dấu cách
}

int getResult(int num)
{
    return num * num * num; // Tính lập phương của số nguyên
}

// Giải thích nhanh về Nạp chồng hàm (Function Overloading):
// Nạp chồng hàm là gì? Bạn được phép tạo nhiều hàm trùng tên nhau (ở đây là getResult) nhưng phải khác nhau về tham số (khác số lượng tham số, hoặc khác kiểu dữ liệu của tham số).

// Cách máy tính phân biệt: Khi bạn gọi hàm, trình biên dịch sẽ tự động nhìn vào đầu vào bạn truyền vào để chọn đúng phiên bản hàm phù hợp:

// Truyền vào (30, 20) -> 2 số nguyên -> Chọn bản 1 (nhân hai số).

// Truyền vào ("John", "Baugh") -> 2 chuỗi -> Chọn bản 2 (nối chuỗi).

// Truyền vào (5) -> 1 số nguyên -> Chọn bản 3 (tính lập phương).

// Tác dụng: Giúp code của bạn gọn gàng, trực quan hơn vì không cần phải đặt tên các hàm có cùng một mục đích xử lý thành getResultInt, getResultString, hay getResultCube dài dòng.