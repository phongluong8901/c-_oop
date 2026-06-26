#include <iostream>
#include <string>
#include "House.h" //sao chép và dán toàn bộ nội dung của file

using namespace std;

//-------House Class

//--------Main function

int main()
{
    House myHouse; // Dòng này cấp phát bộ nhớ và khởi tạo một ngôi nhà cụ thể mang tên myHouse.
    House yourHouse;

    myHouse.setNumStories(2);
    myHouse.setNumWindows(6);
    myHouse.setColor("red");

    yourHouse.setNumStories(3);
    yourHouse.setNumWindows(10);
    yourHouse.setColor("blue");

    myHouse.print();
    yourHouse.print();

    //--
    House theirHouse(2, 10, "green");
    theirHouse.print();

    return 0;
}

//
// Khi nào hàm hủy tự động chạy?
// Hàm hủy sẽ tự động được kích hoạt khi đối tượng vượt quá phạm vi hoạt động (scope) của nó. Trong đoạn code main của bạn:

// Khi hàm main bắt đầu, hai ngôi nhà myHouse và yourHouse được tạo ra trong RAM.

// Chương trình chạy hết các lệnh in thông tin.

// Khi hàm main kết thúc (gặp dấu ngoặc nhọn cuối cùng } hoặc lệnh return 0), chương trình chuẩn bị đóng lại. Lúc này, myHouse và yourHouse không còn cần thiết nữa.

// Trình biên dịch sẽ tự động gọi hàm ~House() cho từng ngôi nhà để thông báo và dọn dẹp.

//---
// Đúng rồi, nó sẽ xóa toàn bộ các biến (đối tượng) được tạo ra từ class House. Cụ thể trong trường hợp của bạn, nó sẽ xóa lần lượt myHouse, yourHouse, và theirHouse.