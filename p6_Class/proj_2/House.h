#ifndef HOUSE_H
#define HOUSE_H

using namespace std;

#include <string>
class House
{
public:
    House();
    House(int numStories, int numWindows, string color);
    ~House();
    void setNumStories(int numStories);

    void setNumWindows(int numWindows);

    void setColor(string color);

    int getNumStories() const;

    int getNumWindows() const;

    string getColor() const;

    void print() const;

private:
    int numStories;
    int numWindows;
    string color;
};

#endif // HOUSE_H

// Đoạn code #ifndef, #define và #endif trong file .h được gọi là Include Guard (hoặc Macro Guard).

// Đây là một kỹ thuật bắt buộc trong C++ để ngăn chặn lỗi "Redefinition" (định nghĩa lại) khi dự án của bạn trở nên lớn hơn.

// #ifndef HOUSE_H    // Nếu (IF) chưa (N) định nghĩa (DEF) từ khóa HOUSE_H
// #define HOUSE_H    // Thì hãy định nghĩa (DEFINE) từ khóa HOUSE_H ngay bây giờ
// ... Toàn bộ nội dung class House nằm ở đây ...

// #endif             // Kết thúc khối điều kiện của #ifndef

//---
// 1. Nhóm Hàm Khởi Tạo và Hủy (Constructors & Destructor)
// House(); (Hàm dựng mặc định)

// Ý nghĩa: Được gọi tự động khi bạn tạo một đối tượng nhà mà không truyền bất kỳ thông tin nào (ví dụ: House myHouse;).

// Tác dụng: Khởi tạo ngôi nhà với các giá trị mặc định (như 1 tầng, 4 cửa sổ, màu trắng) để tránh việc biến mang giá trị rác.

// House(int numStories, int numWindows, string color); (Hàm dựng có tham số)

// Ý nghĩa: Được gọi khi bạn muốn thiết lập thông số cho ngôi nhà ngay tại thời điểm tạo ra nó (ví dụ: House myHouse(2, 6, "red");).

// Tác dụng: Giúp khởi tạo nhanh một đối tượng với các giá trị tùy chỉnh truyền vào từ bên ngoài.

// ~House(); (Hàm hủy)

// Ý nghĩa: Được gọi tự động khi đối tượng kết thúc vòng đời (ra khỏi phạm vi hoạt động hoặc chương trình kết thúc).

// Tác dụng: Dùng để dọn dẹp bộ nhớ hoặc thông báo đối tượng đã bị hủy khỏi RAM.

// 2. Nhóm Hàm Thiết Lập (Setters)
// Các hàm này có nhiệm vụ gán hoặc thay đổi giá trị cho các thuộc tính riêng tư bên trong đối tượng.

// void setNumStories(int numStories);

// Gán số tầng mới cho ngôi nhà.

// `void setNumWindows(int numWindows);

// Gán số lượng cửa sổ mới.

// `void setColor(string color);

// Gán màu sắc mới cho ngôi nhà.

// 3. Nhóm Hàm Lấy Giá Trị (Getters)
// Các hàm này có từ khóa const ở cuối, nghĩa là nó chỉ đọc/lấy giá trị ra ngoài chứ không cho phép thay đổi các thuộc tính của đối tượng.

// int getNumStories() const;

// Trả về số tầng hiện tại của ngôi nhà.

// int getNumWindows() const;

// Trả về số lượng cửa sổ hiện tại.

// string getColor() const;

// Trả về màu sắc hiện tại.

// 4. Hàm In Thông Tin
// void print() const;

// Ý nghĩa: Cũng được gắn từ khóa const để đảm bảo hàm này không làm thay đổi dữ liệu của đối tượng.

// Tác dụng: In ra màn hình toàn bộ các thông số hiện có của ngôi nhà (số tầng, số cửa sổ, màu sắc) một cách rõ ràng.