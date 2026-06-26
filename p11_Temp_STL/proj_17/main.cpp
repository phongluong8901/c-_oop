#include <iostream>
#include <vector>
#include <memory>
#include "Crop.h" // Nạp file tiêu đề (header) của lớp Crop
using namespace std;

// Khai báo nguyên mẫu (prototype) hàm in thông tin cây trồng
void printCrop(const Crop &crop);

int main()
{
    // Khởi tạo một vector lưu trữ các con trỏ thông minh unique_ptr quản lý đối tượng Crop.
    // Việc dùng unique_ptr giúp tự động dọn dẹp bộ nhớ khi vector bị hủy, tránh rò rỉ bộ nhớ.
    vector<unique_ptr<Crop>> crops;

    // Thêm đối tượng Crop thứ nhất vào vector với (height=30, yield=40, droughtResistance=20)
    crops.push_back(make_unique<Crop>(30, 40, 20));
    // Thêm đối tượng Crop thứ hai vào vector
    crops.push_back(make_unique<Crop>(25, 50, 15));
    // Thêm đối tượng Crop thứ ba vào vector
    crops.push_back(make_unique<Crop>(32, 38, 22));

    // Thực hiện lai tạo Cây 1 (*crops[0]) và Cây 2 (*crops[1]) thông qua nạp chồng toán tử cộng (+).
    // Dấu * dùng để lấy đối tượng thực tế mà con trỏ thông minh đang trỏ tới.
    Crop hybrid = *crops[0] + *crops[1];

    cout << "Crop 1:" << endl;
    // In thông số Cây 1
    printCrop(*crops[0]);

    cout << "Crop 2:" << endl;
    // In thông số Cây 2
    printCrop(*crops[1]);

    cout << "Crop 3:" << endl;
    // In thông số Cây 3
    printCrop(*crops[2]);

    cout << "Hybrid crop:" << endl;
    // In thông số cây lai tạo (hybrid)
    printCrop(hybrid);

    // Cài đặt cờ boolalpha để in giá trị boolean dạng chữ (true/false) thay vì số (1/0)
    cout << boolalpha;

    // So sánh bằng: Kiểm tra điểm Score của cây lai có bằng cây 3 không
    cout << "Hybrid == Crop 3? " << (hybrid == *crops[2]) << endl;

    // So sánh lớn hơn: Kiểm tra điểm Score của cây lai có lớn hơn cây 3 không
    cout << "Hybrid > Crop 3? " << (hybrid > *crops[2]) << endl;

    return 0; // Kết thúc chương trình
}

// Định nghĩa hàm in thông tin chi tiết của một đối tượng Crop
void printCrop(const Crop &crop)
{
    cout << "Height: " << crop.getHeight()
         << ", Yield: " << crop.getYield()
         << ", Drought Resistance: " << crop.getDroughtResistance()
         << ", Score: " << crop.getScore() << endl
         << endl;
}

//
// "Tự động tạo ra đối tượng, đưa nó vào danh sách quản lý, và khi nào không dùng đến (hoặc chương trình kết thúc), nó sẽ tự động dọn dẹp bộ nhớ giúp bạn".

// Mổ xẻ chi tiết từng thành phần
// vector<unique_ptr<Crop>> crops;

// Bạn tạo ra một cái túi (std::vector) chuyên đi chứa các con trỏ thông minh.

// unique_ptr có nghĩa là mỗi đối tượng Crop chỉ được phép có độc nhất một con trỏ sở hữu nó.

// make_unique<Crop>(30, 40, 20)

// Lệnh này cấp phát bộ nhớ, gọi hàm khởi tạo để tạo ra một cây trồng mới ngay trong bộ nhớ heap với các chỉ số tương ứng, đồng thời đóng gói nó vào một unique_ptr.

// crops.push_back(...)

// Ném cái unique_ptr vừa tạo vào trong danh sách crops.

// ---
// Điều gì xảy ra bên trong hậu trường khi chạy lệnh này?
// Khi trình biên dịch đọc được phép toán *crops[0] + *crops[1], nó sẽ nhảy vào hàm operator+ bên trong file Crop.cpp và thực hiện các bước sau:

// Tính trung bình cộng các đặc tính: Lấy chiều cao, sản lượng, và khả năng chống hạn của Cây 1 và Cây 2 cộng lại rồi chia đôi.

// Gieo mầm đột biến ngẫu nhiên: Hệ thống tự động cộng hoặc trừ ngẫu nhiên một lượng nhỏ (-1, 0, hoặc +1) để mô phỏng sự biến dị của tự nhiên.

// Tạo cây mới: Trả về một đối tượng Crop hoàn toàn mới mang các thông số đã lai tạo để lưu vào biến hybrid.