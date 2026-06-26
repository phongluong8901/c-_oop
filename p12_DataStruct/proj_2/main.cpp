#include <iostream>    // Thư viện nhập/xuất chuẩn
#include "ArrayList.h" // Nạp tệp tiêu đề ArrayList để sử dụng lớp ArrayList
using namespace std;

int main() // Điểm bắt đầu thực thi chương trình
{
    ArrayList myList; // Khởi tạo danh sách mảng với kích thước mặc định là 16

    // Vòng lặp thêm 15 phần tử vào danh sách (giá trị lần lượt là 0, 10, 20, ..., 140)
    for (int i = 0; i < 15; i++)
    {
        myList.add(i * 10);
    }

    myList.printList(); // In toàn bộ danh sách ra màn hình

    cout << endl
         << "Size is " << myList.size() << endl; // In ra kích thước hiện tại (15)

    // Thử chèn phần tử 555 vào vị trí index = 15
    myList.add(555, 15);

    myList.printList();                              // In lại danh sách sau khi chèn
    cout << "Size is now " << myList.size() << endl; // In ra kích thước mới (16)

    // Ghi đè/thay đổi giá trị 987 vào vị trí index = 3
    myList.set(987, 3);

    myList.printList(); // In danh sách sau khi cập nhật

    myList.add(1000); // Thêm phần tử khi mảng đã đạt MAX_SIZE = 16 -> Sẽ kích hoạt thông báo lỗi "List is full"

    return 0; // Kết thúc chương trình thành công
}