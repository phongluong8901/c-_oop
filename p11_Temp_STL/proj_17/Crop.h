#ifndef CROP_H // Kiểm tra tiền xử lý: đảm bảo file header này chỉ được include 1 lần trong suốt quá trình biên dịch
#define CROP_H

class Crop
{
public:
    // Constructor: hàm khởi tạo đối tượng với 3 tham số đầu vào
    Crop(int height, int yield, int droughtResistance);

    // Các phương thức getter (hàm hằng - const): dùng để truy xuất dữ liệu, cam kết không làm thay đổi thuộc tính bên trong
    int getHeight() const;
    int getYield() const;
    int getDroughtResistance() const;
    int getScore() const;

    // Nạp chồng các toán tử so sánh (const ở cuối bảo vệ đối tượng hiện tại không bị sửa đổi)
    bool operator==(const Crop &other) const;
    bool operator!=(const Crop &other) const;
    bool operator<(const Crop &other) const;
    bool operator>(const Crop &other) const;
    bool operator<=(const Crop &other) const;
    bool operator>=(const Crop &other) const;

    // Nạp chồng toán tử cộng (+): dùng để lai tạo 2 đối tượng Crop và trả về một Crop mới
    Crop operator+(const Crop &other) const;

    // Nạp chồng toán tử gán (=): dùng để sao chép giá trị từ đối tượng khác vào đối tượng hiện tại
    void operator=(const Crop &other);

private:
    // Các thuộc tính mang đặc tính của cây trồng (được đóng gói ở mức độ private, an toàn trước sự can thiệp bên ngoài)
    int height;
    int yield;
    int droughtResistance;
};

#endif // Kết thúc khối lệnh của #ifndef