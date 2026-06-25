#include <iostream>
#include <string>

using namespace std;

//-------House Class
class House
{
public:
    void setNumStories(int numStories)
    {
        this->numStories = numStories;
    }

    void setNumWindows(int numWindows)
    {
        this->numWindows = numWindows; // Lấy giá trị của biến numWindows vừa được truyền vào hàm, đem gán (lưu) vào thuộc tính numWindows của ngôi nhà hiện tại
    }

    void setColor(string color)
    {
        this->color = color;
    }

    int getNumStories() const
    {
        return numStories;
    }

    int getNumWindows() const
    {
        return numWindows;
    }

    string getColor() const
    {
        return color;
    }

private:
    int numStories;
    int numWindows;
    string color;
};
//======= PROTOTYPE

void printHouseData(const House &house);

//--------Main function

int main()
{
    House myHouse;
    House yourHouse;

    myHouse.setNumStories(2);
    myHouse.setNumWindows(6);
    myHouse.setColor("red");

    yourHouse.setNumStories(3);
    yourHouse.setNumWindows(10);
    yourHouse.setColor("blue");

    printHouseData(myHouse);
    printHouseData(yourHouse);

    return 0;
}

void printHouseData(const House &house)
{
    cout << "The house is " << house.getColor()
         << " and has " << house.getNumStories()
         << " stories and " << house.getNumWindows()
         << " windows." << endl;
}

// 1. Dấu & có tác dụng gì? (Truyền tham chiếu)
// Vấn đề khi không dùng &: Nếu bạn chỉ truyền (House house), máy tính sẽ tạo ra một bản sao (copy) hoàn toàn mới của ngôi nhà để đưa vào hàm. Việc copy này rất tốn bộ nhớ và thời gian, nhất là với các đối tượng phức tạp chứa nhiều dữ liệu.

// Giải pháp: Dấu & giúp truyền trực tiếp đối tượng gốc vào hàm. Hàm sẽ làm việc trực tiếp với ngôi nhà của bạn ở ngoài hàm main, giúp chương trình chạy nhanh và tiết kiệm bộ nhớ.

// 2. Từ khóa const có tác dụng gì? (Bảo vệ dữ liệu)
// Vấn đề khi dùng & mà không có const: Khi hàm mượn trực tiếp đối tượng gốc, nó có toàn quyền thay đổi dữ liệu của ngôi nhà (ví dụ: vô tình viết nhầm house.setColor("yellow") bên trong hàm in). Điều này làm hỏng dữ liệu gốc ở main.

// Giải pháp: Từ khóa const đóng vai trò như một chiếc khóa an toàn. Nó khẳng định: "Hàm này chỉ được phép đọc dữ liệu để in ra màn hình, tuyệt đối không cho phép sửa đổi bất kỳ thông tin nào của ngôi nhà". Nếu bạn vô tình viết lệnh làm thay đổi dữ liệu trong hàm, trình biên dịch sẽ lập tức báo lỗi.

//---
// Điều gì xảy ra nếu BỎ const (Có & nhưng không có const)
// Giả sử bạn viết hàm in thông tin nhà như thế này (bị thiếu const):

// C++

// void printHouseData(House &house) {
//     // Vô tình viết nhầm hoặc bị lỗi logic làm đổi màu ngôi nhà
//     house.setColor("yellow");

//     cout << "The house is " << house.getColor() << endl;
// }
// Hậu quả:

// Trong hàm main, bạn tạo ngôi nhà myHouse màu đỏ ("red").

// Bạn truyền myHouse vào hàm printHouseData để in.

// Khi chạy xong, ngôi nhà myHouse ngoài đời thực ở hàm main bị biến thành màu vàng ("yellow").

// Kết luận: Khi không có const, hàm có quyền sửa đổi trực tiếp ngôi nhà gốc. Điều này làm hỏng dữ liệu ban đầu của bạn mà bạn không hề hay biết.

// Điều gì xảy ra khi GIỮ const (Có & và có const)
// Nếu bạn thêm const vào:

// C++

// void printHouseData(const House &house) {
//     // Nếu bạn lỡ tay viết lệnh sửa dữ liệu:
//     house.setColor("yellow"); // ❌ LẬP TỨC BÁO LỖI BIÊN DỊCH!

//     cout << "The house is " << house.getColor() << endl;
// }
// Tác dụng:

// Trình biên dịch C++ sẽ đọc từ khóa const và ngăn chặn mọi hành vi thay đổi dữ liệu của ngôi nhà.

// Nếu bạn vô tình (hoặc vô ý) viết lệnh sửa màu, sửa số tầng bên trong hàm, máy tính sẽ báo lỗi đỏ lòm ngay lúc bạn bấm nút Build/Run. Nó giúp bạn bảo vệ an toàn tuyệt đối cho dữ liệu gốc ở hàm main.

// Tóm lại
// Có const: Bạn an tâm 100% rằng dữ liệu gốc của đối tượng chỉ được đọc, không bao giờ bị hàm làm hỏng hay sửa đổi bậy bạ.

// Không có const: Hàm giống như một người mượn đồ của bạn, họ có toàn quyền đập phá, sơn sửa lại món đồ đó mà bạn không thể cản được.