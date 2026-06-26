#ifndef WARRIOR_H
#define WARRIOR_H // Ngăn chặn việc file Warrior.h bị include lặp lại nhiều lần trong project.

#include "Player.h" // Nạp file Player.h để lớp Warrior biết Player là gì và có thể kế thừa.

// Khai báo lớp Warrior (Chiến binh) kế thừa công khai (public) từ lớp Player (Player là lớp cha).
class Warrior : public Player
{
public:
    // Constructor của Warrior: Nhận vào tên và chủng tộc.
    // Lập tức chuyển tiếp thông tin này lên constructor của lớp cha Player bằng cách truyền:
    // tên, chủng tộc, 200 (máu), và 0 (mana). Thân hàm `{}` rỗng vì mọi thứ đã được khởi tạo xong.
    Warrior(string name, Race race) : Player(name, race, 200, 0) {}

    // Ghi đè (override) hàm attack() thuần ảo từ lớp cha.
    // Cung cấp câu thoại tấn công mang đặc trưng riêng của Chiến binh.
    string attack() const override
    {
        return "I will destroy you with my sword, foul demon!";
    }
};

#endif // Kết thúc khối lệnh #ifndef WARRIOR_H.