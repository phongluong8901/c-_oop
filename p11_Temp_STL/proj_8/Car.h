#ifndef CAR_H // Kiểm tra xem CAR_H đã được định nghĩa hay chưa để tránh khai báo trùng lặp thư viện
#define CAR_H

#include <string> // Nạp thư viện string để có thể sử dụng kiểu dữ liệu string
using namespace std;

class Car // Khai báo lớp Car
{
public: // Các phương thức bên dưới có thể được truy cập từ bên ngoài lớp
    // Hàm khởi tạo (constructor) nhận vào màu sắc và số cửa
    Car(string color, int numDoors);

    // Phương thức lấy màu sắc, từ khóa const ở cuối đảm bảo hàm này không làm thay đổi thuộc tính của đối tượng
    string getColor() const;

    // Phương thức lấy số cửa
    int getNumDoors() const;

private: // Các thuộc tính bên dưới bị ẩn, chỉ có thể truy cập bên trong lớp Car
    string color;
    int numDoors;
};

#endif // Kết thúc khối điều kiện của #ifndef