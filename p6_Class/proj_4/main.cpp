#include <iostream>
#include "LibraryCard.h"
using namespace std;

void printLibraryCardDetails(const LibraryCard &card);

int main()
{
    LibraryCard aliceCard("Alice Johnson");
    LibraryCard bobCard("Bob Smith");

    aliceCard.checkoutBook();
    aliceCard.checkoutBook();
    bobCard.checkoutBook();

    printLibraryCardDetails(aliceCard);
    printLibraryCardDetails(bobCard);

    cout << "Alice returns a book... " << endl;
    aliceCard.returnBook();
    printLibraryCardDetails(aliceCard);

    bobCard.returnBook();
    bobCard.returnBook(); // should trigger a warning!

    return 0;
}

void printLibraryCardDetails(const LibraryCard &card)
{
    cout << card.getCardholderName() << " has "
         << card.getBooksCheckedOut() << " books checked out."
         << endl;
}

// 1. Khi có & (Tham chiếu - const LibraryCard &card)
// Cách hoạt động: Chương trình không tạo ra một bản sao (copy) của thẻ thư viện. Nó tạo một "đường dẫn" (hoặc biệt danh) trực tiếp đến đối tượng aliceCard hoặc bobCard đang nằm trong hàm main.

// Hiệu suất: Cực kỳ nhanh và tiết kiệm bộ nhớ, vì máy tính không phải sao chép toàn bộ dữ liệu của đối tượng thẻ thư viện mỗi lần gọi hàm.

// Từ khóa const: Đảm bảo hàm chỉ được phép đọc thông tin chứ không thể sửa đổi dữ liệu của thẻ (card.getBooksCheckedOut()), giúp code an toàn tuyệt đối.

// 2. Khi không có & (Tham trị - const LibraryCard card)
// Cách hoạt động: Mỗi khi hàm printLibraryCardDetails được gọi, hệ thống sẽ sao chép toàn bộ dữ liệu của đối tượng gốc (aliceCard hoặc bobCard) ra một vùng nhớ tạm thời mới có tên là card.

// Ảnh hưởng: * Tốn bộ nhớ và thời gian: Máy tính phải chạy các hàm dựng bản sao (copy constructor) để nhân bản đối tượng. Với các class phức tạp, việc này làm giảm hiệu suất rõ rệt.

// Vòng đời phụ: Đối tượng tạm card sẽ tự động bị hủy (gọi hàm hủy ~LibraryCard()) ngay khi hàm printLibraryCardDetails thực hiện xong dòng cuối cùng.

// Tóm lại
// Về mặt hiển thị kết quả ra màn hình (Console), cả hai cách đều cho ra kết quả giống hệt nhau. Tuy nhiên, trong lập trình C++ thực tế với các đối tượng (Class), truyền theo tham chiếu kèm hằng số (const T &) là quy chuẩn bắt buộc để tối ưu hóa bộ nhớ và tốc độ xử lý.