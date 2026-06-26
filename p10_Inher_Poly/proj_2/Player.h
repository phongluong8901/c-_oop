#ifndef PLAYER_H
#define PLAYER_H // Ngăn chặn việc file này bị include lặp lại nhiều lần trong cùng một project.

#include <string>    // Nạp thư viện để sử dụng kiểu dữ liệu string (chuỗi).
using namespace std; // Sử dụng không gian tên std để không cần viết std::string hay std::cout.

// Định nghĩa một tập hợp các chủng tộc (enum class) giúp dữ liệu an toàn và chặt chẽ hơn.
enum class Race
{
    HUMAN,
    ELF,
    DWARF,
    ORC,
    TROLL
};

// Khai báo lớp cơ sở (lớp cha) Player.
class Player
{
public:
    // Constructor: Hàm khởi tạo, chạy khi bạn tạo mới một đối tượng Player, yêu cầu truyền vào tên, chủng tộc, máu và mana.
    Player(string name, Race race, int hitPoints, int magicPoints);

    // Hàm hủy (destructor) ảo mặc định. Rất quan trọng khi dùng con trỏ đa hình để đảm bảo dọn dẹp sạch bộ nhớ lớp con.
    virtual ~Player() = default;

    // Các hàm getter: Dùng để lấy ra thông tin (tên, chủng tộc, máu, mana) từ bên ngoài lớp. Từ khóa const ở cuối cam kết hàm này không làm thay đổi dữ liệu của đối tượng.
    string getName() const;
    Race getRace() const;
    string whatRace() const;
    int getHitPoints() const;
    int getMagicPointers() const;

    // Các hàm setter: Dùng để thay đổi hoặc gán lại thông tin cho đối tượng.
    void setName(string name);
    void setRace(Race race);
    void setHitPoints(int hitPoints);
    void setMagicPoints(int magicPoints);

    // Hàm thuần ảo (pure virtual function). Số "= 0" bắt buộc các lớp con (như Warrior, Mage, Priest) phải tự viết lại hàm này. Nó biến Player thành một lớp trừu tượng (không thể khởi tạo trực tiếp Player).
    virtual string attack() const = 0;

private:
    // Các thuộc tính của người chơi (được giấu kín bên trong lớp, chỉ cho phép truy xuất thông qua các hàm getter/setter ở trên).
    string name;
    Race race;
    int hitPoints;
    int magicPoints;
};

#endif // Kết thúc khối lệnh của #ifndef PLAYER_H.

//--virtual ~Player() = default;
// 1. virtual ~Player() = default; (Hàm hủy ảo mặc định)
// Tác dụng: Dòng này đảm bảo khi bạn gọi delete player; (như trong hàm doCleanup), chương trình sẽ hủy đối tượng một cách an toàn từ dưới lên — nghĩa là nó sẽ gọi hàm hủy của lớp con (như Warrior, Mage, Priest) trước, sau đó mới gọi hàm hủy của lớp cha (Player).

// Điều gì xảy ra nếu không có từ khóa virtual? Nếu bạn bỏ chữ virtual, C++ sẽ chỉ gọi hàm hủy của lớp cha Player. Vùng nhớ dành riêng cho các thuộc tính mở rộng của lớp con sẽ không được giải phóng, dẫn đến hiện tượng rò rỉ bộ nhớ (memory leak).

// = default; là gì? Báo cho trình biên dịch biết hãy tự động tạo một hàm hủy rỗng mặc định, vì chúng ta không cần viết thêm logic dọn dẹp phức tạp nào ở lớp cha.

//--virtual string attack() const = 0;
// 2. virtual string attack() const = 0; (Hàm thuần ảo)
// Tác dụng: 1. Biến Player thành một Lớp trừu tượng (Abstract Class). Bạn không thể khởi tạo trực tiếp một thực thể Player chung chung (ví dụ: new Player(...) sẽ bị lỗi biên dịch), mà bắt buộc phải thông qua các lớp con cụ thể như Warrior, Mage, hay Priest.
// 2. Số = 0 ở cuối biến nó thành hàm thuần ảo, đóng vai trò như một "hợp đồng" bắt buộc mọi lớp con kế thừa phải tự định nghĩa lại (override) hành vi tấn công của riêng mình.
// 3. Từ khóa virtual kích hoạt cơ chế Đa hình (Polymorphism). Tại thời điểm chạy (runtime), khi gọi player->attack(), C++ sẽ tra cứu bảng hàm ảo (vtable) để phát ra câu thoại tấn công chính xác của từng đối tượng.
// 4. Từ khóa const ở cuối cam kết rằng hành vi tấn công này sẽ không làm thay đổi các thuộc tính (dữ liệu) bên trong của đối tượng.