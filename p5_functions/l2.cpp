// ReturnTypeParameterFun

#include <iostream>  // Nạp thư viện nhập/xuất chuẩn
using namespace std; // Sử dụng không gian tên chuẩn

// Khai báo nguyên mẫu hàm (Function Prototypes)
void printHello();                // Hàm không trả về giá trị, không nhận tham số
void printNumber(int a);          // Hàm không trả về giá trị, nhận 1 tham số nguyên
int giveMe10();                   // Hàm trả về số nguyên, không nhận tham số
int addThese(int num1, int num2); // Hàm trả về nguyên, nhận 2 tham số nguyên

int square(int n); // Hàm trả về nguyên, tính bình phương

int main() // Hàm chính, nơi chương trình bắt đầu chạy
{
    int num1 = 120; // Khởi tạo biến nguyên num1 bằng 120
    int num2 = 580; // Khởi tạo biến nguyên num2 bằng 580

    printHello();     // Gọi hàm in chữ Hello
    printNumber(100); // Gọi hàm in số 100

    int someData = giveMe10(); // Gọi hàm lấy số 10, gán vào biến someData
    cout << someData << endl;  // In giá trị someData ra màn hình

    int totalValue = addThese(num1, num2); // Gọi hàm cộng num1 và num2, gán vào totalValue
    cout << totalValue << endl;            // In totalValue ra màn hình

    printNumber(addThese(num1, 50)); // Lồng hàm: cộng num1 với 50, sau đó truyền kết quả vào hàm in số

    cout << square(7) << endl; // Gọi hàm tính bình phương của 7 và in ra

    return 0; // Kết thúc hàm main thành công
}

// Định nghĩa chi tiết các hàm (Function Definitions)
void printHello()
{
    cout << "Hello there!" << endl; // In ra màn hình dòng chữ
}

void printNumber(int a)
{
    cout << "The number is " << a << endl; // In ra chuỗi kèm theo giá trị của biến a
}

int giveMe10()
{
    return 10; // Trả về trực tiếp số 10
}

int addThese(int num1, int num2)
{
    return num1 + num2; // Trả về tổng của hai số truyền vào
}

int square(int n)
{
    return n * n; // Trả về bình phương của số truyền vào
}

// Bản chất của việc khai báo và định nghĩa:
// Chỉ là thông báo: Khai báo (như int giveMe10();) chỉ giống như việc bạn dán một tấm biển thông báo cho trình biên dịch biết: "Có một hàm tên như thế này tồn tại đấy nhé". Lúc này, máy tính chưa hề cấp phát bộ nhớ hay thực thi bất kỳ dòng code nào bên trong thân hàm.

// Thực thi khi gọi: Hàm chỉ thực sự chạy khi hàm main (hoặc một hàm khác) gọi đến nó (ví dụ: giveMe10();). Lúc này, chương trình mới nhảy đến phần định nghĩa hàm ở bên dưới để thực thi các lệnh bên trong và trả về kết quả.