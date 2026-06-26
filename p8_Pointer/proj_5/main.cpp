#include <iostream>  // Nạp thư viện nhập/xuất chuẩn
#include "Exhibit.h" // Nạp file header khai báo lớp Exhibit
using namespace std; // Sử dụng không gian tên chuẩn

int main() // Hàm chính của chương trình
{
    const int EXHIBIT_COUNT = 3; // Khởi tạo hằng số kích thước mảng bằng 3

    // Khai báo mảng gồm 3 con trỏ, mỗi con trỏ có khả năng trỏ tới một đối tượng Exhibit
    Exhibit *exhibitPtrs[EXHIBIT_COUNT];

    // Cấp phát bộ nhớ động, tạo đối tượng Exhibit trên Heap và gán địa chỉ cho con trỏ thứ nhất
    exhibitPtrs[0] = new Exhibit("T-Rex Skeleton", 101, 350.5);
    // Tương tự, cấp phát cho phần tử thứ hai
    exhibitPtrs[1] = new Exhibit("Ancient Egypt", 204, 480.25);
    // Tương tự, cấp phát cho phần tử thứ ba
    exhibitPtrs[2] = new Exhibit("Space Exploration", 309, 290.75);

    // Vòng lặp duyệt qua từng con trỏ trong mảng để lấy thông tin đối tượng thông qua toán tử ->
    for (int i = 0; i < EXHIBIT_COUNT; i++)
    {
        cout << "Exhibit: " << exhibitPtrs[i]->getName() << endl;                       // In tên triển lãm
        cout << "\tRoom: " << exhibitPtrs[i]->getRoomNumber() << endl;                  // In số phòng
        cout << "\tDisplay Size (sq ft): " << exhibitPtrs[i]->getDisplaySize() << endl; // In kích thước
        cout << endl;
    } // end for

    // Vòng lặp giải phóng bộ nhớ đã cấp phát bằng từ khóa new để tránh rò rỉ bộ nhớ (memory leak)
    for (int i = 0; i < EXHIBIT_COUNT; i++)
    {
        delete exhibitPtrs[i];    // Hủy đối tượng tại vùng nhớ heap
        exhibitPtrs[i] = nullptr; // Gán con trỏ về null để tránh trỏ vào vùng nhớ vừa hủy
    }

    return 0; // Báo cáo chương trình kết thúc thành công
}

//
// exhibitPtrs[i]->getName() có nghĩa là: Truy cập vào con trỏ thứ i trong mảng, sau đó gọi hàm getName() của đối tượng mà con trỏ đó đang trỏ tới.
// Để hiểu rõ hơn, chúng ta hãy bẻ nhỏ cấu trúc này ra nhé:

// exhibitPtrs[i]: Lấy ra con trỏ nằm ở vị trí thứ i trong mảng con trỏ exhibitPtrs (chính là địa chỉ của đối tượng Exhibit được tạo bằng lệnh new).

// -> (Toán tử mũi tên): Là toán tử được sử dụng riêng cho con trỏ đối tượng. Nó có nhiệm vụ đi đến địa chỉ vùng nhớ đó và truy xuất vào các hàm/biến bên trong đối tượng.

// Lưu ý: Nó tương đương với cách viết viết dài dòng là (*exhibitPtrs[i]).getName().

// getName(): Gọi hàm lấy tên của đối tượng Exhibit đó (trả về chuỗi tên như "T-Rex Skeleton", "Ancient Egypt",...).

//---
// Toán tử mũi tên -> Dùng để truy xuất thành viên (hàm/biến) của một đối tượng thông qua con trỏ.
// Toán tử phân giải phạm vi :: Dùng để truy cập các thành viên tĩnh (static), không gian tên (`std::'], hoặc phạm vi của lớp.