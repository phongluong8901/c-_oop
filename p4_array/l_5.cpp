#include <iostream>  // Nạp thư viện nhập/xuất chuẩn
#include <vector>    // Nạp thư viện vector (mảng động)
#include <string>    // Nạp thư viện hỗ trợ kiểu chuỗi
using namespace std; // Sử dụng không gian tên chuẩn

int main() // Hàm chính của chương trình
{
    vector<string> shoppingList; // Khởi tạo mảng động rỗng chứa chuỗi
    string item;                 // Khai báo biến tạm lưu tên món hàng

    cout << "Enter items for your shopping list (type 'done' to finish):";
    getline(cin, item); // Nhập chuỗi từ bàn phím (hỗ trợ cả khoảng trắng)

    while (item != "done") // Lặp lại nếu người dùng chưa nhập 'done'
    {
        shoppingList.push_back(item); // Thêm món hàng vào cuối mảng động

        cout << "Enter another item (or 'done' to finish): ";
        getline(cin, item); // Tiếp tục nhập món hàng tiếp theo
    } // Kết thúc vòng lặp while

    cout << "\nYour shopping list: " << endl;
    for (string listItem : shoppingList) // Duyệt qua từng phần tử trong mảng động
    {
        cout << "- " << listItem << endl; // In ra từng món hàng
    }

    return 0; // Kết thúc chương trình thành công
}

// 1. Lệnh cin >> item (Cách thông thường)
// Cách hoạt động: Khi đọc chuỗi, nó sẽ dừng lại ngay khi gặp khoảng trắng (dấu cách - space) hoặc xuống dòng (Enter).

// Ví dụ: Nếu bạn nhập Apple Pie:

// Biến item chỉ nhận được chữ Apple.

// Chữ Pie bị bỏ lại trong bộ nhớ đệm (buffer).

// Nhược điểm: Không phù hợp để nhập các món hàng có từ 2 chữ trở lên (ví dụ: Fresh milk, Coca cola...).

// 2. Lệnh getline(cin, item) (Cách trong code của bạn)
// Cách hoạt động: Nó đọc toàn bộ dòng chữ bạn gõ, bao gồm cả khoảng trắng, và chỉ dừng lại khi bạn bấm phím Enter.

// Ví dụ: Nếu bạn nhập Apple Pie rồi bấm Enter:

// Biến item sẽ nhận chính xác và đầy đủ chuỗi Apple Pie.

// Ưu điểm: Rất phù hợp cho danh sách mua sắm vì người dùng có thể nhập các món hàng có dấu cách.