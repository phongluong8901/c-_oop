#include "Player.h" // Nạp file header Player.h để chương trình biết định nghĩa của lớp Player.

// Constructor: Khởi tạo đối tượng Player.
// Đoạn sau dấu hai chấm (:) được gọi là Member Initialization List (Danh sách khởi tạo thành viên).
// Nó gán trực tiếp tham số vào thuộc tính, giúp tối ưu hóa hiệu năng hơn là gán bên trong thân hàm.
Player::Player(string name, Race race, int hitPoints, int magicPoints)
    : name(name), race(race), hitPoints(hitPoints), magicPoints(magicPoints)
{
    // Thân hàm rỗng vì toàn bộ việc khởi tạo đã được thực hiện ở danh sách phía trên.
}

// Hàm getter: Trả về tên của người chơi.
string Player::getName() const
{
    return name;
}

// Hàm getter: Trả về chủng tộc của người chơi dưới dạng kiểu Race enum.
Race Player::getRace() const
{
    return race;
}

// Hàm chuyển đổi enum sang chuỗi: Kiểm tra giá trị chủng tộc và trả về chuỗi chữ tương ứng để dễ hiển thị.
string Player::whatRace() const
{
    switch (race) // Kiểm tra giá trị của biến race.
    {
    case Race::HUMAN:
        return "Human"; // Nếu là HUMAN, trả về chuỗi "Human".
    case Race::ELF:
        return "Elf";
    case Race::DWARF:
        return "Dwarf";
    case Race::ORC:
        return "Orc";
    case Race::TROLL:
        return "Troll";
    default: // Trường hợp không xác định, trả về "Unknown".
        return "Unknown";
    }
}

// Hàm getter: Trả về lượng máu (hitPoints).
int Player::getHitPoints() const
{
    return hitPoints;
}

// Hàm getter: Trả về lượng mana/phép thuật (magicPoints).
int Player::getMagicPointers() const
{
    return magicPoints;
}

// Hàm setter: Gán hoặc thay đổi tên của người chơi.
void Player::setName(string name)
{
    this->name = name; // Con trỏ "this->" chỉ đến đối tượng hiện tại, giúp phân biệt giữa tham số truyền vào và thuộc tính của lớp.
}

// Hàm setter: Thay đổi chủng tộc.
void Player::setRace(Race race)
{
    this->race = race;
}

// Hàm setter: Thay đổi lượng máu.
void Player::setHitPoints(int hitPoints)
{
    this->hitPoints = hitPoints;
}

// Hàm setter: Thay đổi lượng mana/phép thuật.
void Player::setMagicPoints(int magicPoints)
{
    this->magicPoints = magicPoints;
}

//-- Player::Player(string name, Race race, int hitPoints, int magicPoints)
//     : name(name), race(race), hitPoints(hitPoints), magicPoints(magicPoints)
// {

// Điều xảy ra trong RAM: Máy tính lấy trực tiếp dữ liệu đầu vào và đúc thẳng vào thuộc tính name, race ngay tại khoảnh khắc biến đó vừa sinh ra.

// Kết quả: Giống như bạn đúc một viên gạch. Nó chỉ mất 1 công đoạn duy nhất và hoàn thành ngay lập tức.

//---
// tuong tu
// Player::Player(string name, Race race, int hitPoints, int magicPoints)
// {
//     this->name = name; // Gán ở đây
//     this->race = race;
// }

// Điều xảy ra trong RAM: 1. Bước 1: Máy tính tạo ra các thuộc tính name, race rỗng (nó phải tốn bộ nhớ để khởi tạo giá trị mặc định trước).
// 2. Bước 2: Sau đó, nó mới dùng dấu = để chép đè chữ "Arthur" vào.

// Kết quả: Giống như bạn đúc xong một viên gạch hỏng, rồi lại phải đập đi hoặc tô vẽ đè lên để sửa lại. Bạn bị mất 2 công đoạn, vừa tốn thời gian, vừa làm giảm hiệu suất của chương trình.
