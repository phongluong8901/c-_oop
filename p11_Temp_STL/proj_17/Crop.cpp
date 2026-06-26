#include "Crop.h"
#include <cstdlib>
#include <ctime>

using namespace std;

// Hàm khởi tạo (Constructor): nhận vào 3 tham số và gán giá trị cho các thuộc tính tương ứng của lớp thông qua danh sách khởi tạo member initializer list
Crop::Crop(int height, int yield, int droughtResistance) : height(height), yield(yield),
                                                           droughtResistance(droughtResistance)
{
}

// Phương thức trả về chiều cao cây
int Crop::getHeight() const
{
    return height;
}

// Phương thức trả về sản lượng cây
int Crop::getYield() const
{
    return yield;
}

// Phương thức trả về khả năng chống hạn
int Crop::getDroughtResistance() const
{
    return droughtResistance;
}

// Phương thức tính điểm tổng hợp (Score) dựa trên công thức định sẵn
int Crop::getScore() const
{
    return (height * 2) + (yield * 3) + (droughtResistance * 4);
}

// Nạp chồng toán tử so sánh bằng (==): hai cây bằng nhau khi và chỉ khi điểm Score của chúng bằng nhau
bool Crop::operator==(const Crop &other) const
{
    return getScore() == other.getScore();
}

// Nạp chồng toán tử so sánh khác (!=): phủ định kết quả của toán tử bằng (==)
bool Crop::operator!=(const Crop &other) const
{
    return !(*this == other);
}

// Nạp chồng toán tử so sánh nhỏ hơn (<): so sánh dựa trên điểm Score
bool Crop::operator<(const Crop &other) const
{
    return getScore() < other.getScore();
}

// Nạp chồng toán tử so sánh lớn hơn (>): so sánh dựa trên điểm Score
bool Crop::operator>(const Crop &other) const
{
    return getScore() > other.getScore();
}

// Nạp chồng toán tử so sánh nhỏ hơn hoặc bằng (<=)
bool Crop::operator<=(const Crop &other) const
{
    return getScore() <= other.getScore();
}

// Nạp chồng toán tử so sánh lớn hơn hoặc bằng (>=)
bool Crop::operator>=(const Crop &other) const
{
    return getScore() >= other.getScore();
}

// Nạp chồng toán tử cộng (+): mô phỏng cơ chế lai tạo hai cây trồng (đối tượng hiện tại và đối tượng other)
Crop Crop::operator+(const Crop &other) const
{
    // Thiết lập mầm ngẫu nhiên cho hàm rand() dựa trên thời gian hiện tại
    srand(time(nullptr));

    // Định nghĩa một hàm lambda nội bộ để tạo độ biến thiên ngẫu nhiên
    auto randomize = [](int value)
    {
        int variation = (rand() % 3) - 1; // Tạo giá trị ngẫu nhiên là -1, 0, hoặc +1
        return value + variation;
    };

    // Tính trung bình cộng các đặc tính của cây bố và cây mẹ, sau đó áp dụng đột biến ngẫu nhiên
    int newHeight = randomize((height + other.height) / 2);
    int newYield = randomize((yield + other.yield) / 2);
    int newDrought = randomize((droughtResistance + other.droughtResistance) / 2);

    // Khởi tạo và trả về một đối tượng Crop hoàn toàn mới mang đặc tính lai tạo
    return Crop(newHeight, newYield, newDrought);
}

// Nạp chồng toán tử gán (=): sao chép trực tiếp giá trị các thuộc tính từ đối tượng khác sang đối tượng hiện tại
void Crop::operator=(const Crop &other)
{
    height = other.height;
    yield = other.yield;
    droughtResistance = other.droughtResistance;
}