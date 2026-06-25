// Tip calculation
#include <iostream>
#include <iomanip> //(viết tắt của Input/Output Manipulators) trong C++ được sử dụng để điều khiển định dạng đầu ra của dữ liệu khi hiển thị trên màn hình (thông qua cout).
using namespace std;

int main()
{

    double billAmount;
    double tipPercentage;
    double tipAmount;
    double totalAmount;

    cout << fixed << setprecision(2);

    cout << "Enter the total bill amount: " << endl;
    cin >> billAmount;

    cout << "Enter the tip percentage you would like to leave: " << endl;
    cin >> tipPercentage;

    tipAmount = billAmount * (tipPercentage / 100);
    totalAmount = billAmount + tipAmount;

    cout << "You should tip $" << tipAmount << endl;
    cout << "Your total with tip is: $" << totalAmount << endl;

    return 0;
}

// Trong đoạn code tính tiền tip của bạn, dòng lệnh:
// cout << fixed << setprecision(2);
// sử dụng hai hàm thao tác (manipulator) từ thư viện này với tác dụng cụ thể như sau:

// 1. fixed
// Tác dụng: Buộc hệ thống hiển thị các số dấu phẩy động (kiểu double hoặc float) ở dạng thập phân thông thường, thay vì tự động chuyển sang dạng ký hiệu khoa học (ví dụ: 1.2e+02) khi số có giá trị quá lớn hoặc quá nhỏ.

// Điểm nổi bật: Khi kết hợp với setprecision, nó cố định số chữ số nằm ở phần thập phân.

// 2. setprecision(2)
// Tác dụng: Xác định số lượng chữ số có nghĩa sẽ được hiển thị.

// Khi đi kèm với fixed: Nó quy định chính xác số chữ số thập phân được làm tròn và hiển thị sau dấu phẩy.

// Ứng dụng trong code của bạn: Đảm bảo tiền tip và tổng tiền hiển thị đúng chuẩn tiền tệ với 2 chữ số thập phân (ví dụ: hiển thị 15.50$ thay vì 15.5$).