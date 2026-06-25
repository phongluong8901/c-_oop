#include <iostream>  // Nạp thư viện nhập/xuất chuẩn
#include <cmath>     // Nạp thư viện toán học để dùng các hàm pow, sqrt, ceil, floor, log2
using namespace std; // Sử dụng không gian tên chuẩn

int main() // Hàm chính của chương trình
{
    int powResult = pow(2, 3);    // Hàm tính lũy thừa 2^3, kết quả lưu vào powResult (8)
    int sqrtResult = sqrt(25);    // Hàm tính căn bậc hai của 25, lưu vào sqrtResult (5)
    int ceilResult = ceil(4.2);   // Hàm làm tròn lên thành số nguyên lớn hơn hoặc bằng (5)
    int floorResult = floor(4.2); // Hàm làm tròn xuống thành số nguyên nhỏ hơn hoặc bằng (4)
    int logResult = log2(512);    // Hàm tính logarit cơ số 2 của 512, lưu vào logResult (9)

    cout << "2^3 is " << powResult << endl;             // In kết quả lũy thừa
    cout << "sqrt of 25 is " << sqrtResult << endl;     // In kết quả căn bậc hai
    cout << "ceiling of 4.2 is " << ceilResult << endl; // In kết quả làm tròn lên
    cout << "floor of 4.2 is " << floorResult << endl;  // In kết quả làm tròn xuống
    cout << "log2 of 512 is " << logResult << endl;     // In kết quả log2

    return 0; // Kết thúc hàm main thành công
}