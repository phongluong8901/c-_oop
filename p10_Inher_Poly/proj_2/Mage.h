#ifndef MAGE_H
#define MAGE_H // Ngăn chặn việc file Mage.h bị include lặp lại nhiều lần trong project.

#include "Player.h" // Nạp file Player.h để lớp Mage biết Player là gì và có thể kế thừa.

// Khai báo lớp Mage (Pháp sư) kế thừa công khai (public) từ lớp Player (Player là lớp cha).
class Mage : public Player
{
public:
    // Constructor của Mage: Nhận vào tên và chủng tộc.
    // Ngay lập tức chuyển tiếp thông tin này lên constructor của lớp cha Player bằng cách truyền:
    // tên, chủng tộc, 150 (máu), và 150 (mana). Thân hàm `{}` rỗng vì mọi thứ đã được khởi tạo xong.
    Mage(string name, Race race) : Player(name, race, 150, 150) {}

    // Ghi đè (override) hàm attack() thuần ảo từ lớp cha.
    // Cung cấp câu thoại tấn công riêng biệt của Pháp sư.
    string attack() const override
    {
        return "I will crush you with the power of my arcane missiles!";
    }
};

#endif // Kết thúc khối lệnh #ifndef MAGE_H.

//--string attack() const override
// 1. string
// Ý nghĩa: Đây là kiểu dữ liệu trả về của phương thức. Nó thông báo rằng khi hàm attack() được gọi, nó sẽ trả về một chuỗi văn bản (cụ thể là câu thoại của pháp sư).

// 2. attack()
// Ý nghĩa: Đây là tên của phương thức (hàm). Tên này phải khớp chính xác với nguyên mẫu hàm thuần ảo đã được khai báo bên trong lớp cha Player.

// 3. const
// Ý nghĩa: Từ khóa này đặt ở cuối thân hàm nhằm cam kết rằng phương thức này không làm thay đổi bất kỳ thuộc tính nào của đối tượng (như không làm thay đổi tên, máu hay mana của nhân vật). Nếu bạn vô tình viết code làm thay đổi dữ liệu bên trong hàm này, trình biên dịch sẽ báo lỗi.

// 4. override
// Ý nghĩa: Báo cho trình biên dịch biết rằng hàm này đang thực hiện việc ghi đè (override) một hàm ảo có sẵn từ lớp cha (Player).

// Tại sao nên dùng override: Mặc dù không bắt buộc, nhưng đây là một thói quen cực kỳ tốt. Nó giúp trình biên dịch kiểm tra giúp bạn: Liệu ở lớp cha có thực sự tồn tại hàm ảo attack() nguyên bản hay không? Nếu bạn vô tình gõ sai tên hàm ở lớp con (ví dụ: gõ nhầm thành atak()), trình biên dịch sẽ lập tức báo lỗi, giúp bạn phát hiện sớm lỗi sai trước khi chạy chương trình.

//---
// Đúng rồi bạn nhé. Trong C++, để có thể ghi đè (override) một hàm, lớp cha bắt buộc phải khai báo hàm đó là hàm ảo (sử dụng từ khóa virtual).
