#ifndef PRIEST_H
#define PRIEST_H // Ngăn chặn việc file Priest.h bị include lặp lại nhiều lần trong project.

#include "Player.h" // Nạp file Player.h để lớp Priest biết Player là gì và có thể kế thừa.

// Khai báo lớp Priest (Tu sĩ) kế thừa công khai (public) từ lớp Player (Player là lớp cha).
class Priest : public Player
{
public:
    // Constructor của Priest: Nhận vào tên và chủng tộc.
    // Lập tức chuyển tiếp thông tin này lên constructor của lớp cha Player bằng cách truyền:
    // tên, chủng tộc, 100 (máu), và 200 (mana). Thân hàm `{}` rỗng vì mọi thứ đã được khởi tạo xong.
    Priest(string name, Race race) : Player(name, race, 100, 200) {}

    // Ghi đè (override) hàm attack() thuần ảo từ lớp cha.
    // Cung cấp câu thoại tấn công mang đặc trưng riêng của Tu sĩ.
    string attack() const override
    {
        return "I will assault you with Holy Wrath!";
    }
};

#endif // Kết thúc khối lệnh #ifndef PRIEST_H.