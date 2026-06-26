#ifndef DRONE_H // Kiểm tra xem DRONE_H đã được định nghĩa chưa để tránh nạp lại
#define DRONE_H // Định nghĩa DRONE_H

#include <string>    // Nạp thư viện xử lý chuỗi
using namespace std; // Sử dụng không gian tên chuẩn

class Drone // Khai báo lớp Drone
{
public:                                          // Vùng công khai (truy xuất từ bên ngoài class)
    Drone(string modelName, double batteryLife); // Hàm khởi tạo nhận tên model và thời lượng pin
    string getModelName() const;                 // Hàm lấy tên model (cam kết không sửa đổi đối tượng)
    double getBatteryLife() const;               // Hàm lấy thời lượng pin

private:                // Vùng riêng tư (chỉ nội bộ class truy xuất được)
    string modelName;   // Biến thành viên lưu tên model
    double batteryLife; // Biến thành viên lưu thời lượng pin
};

#endif // Kết thúc khối tiền xử lý