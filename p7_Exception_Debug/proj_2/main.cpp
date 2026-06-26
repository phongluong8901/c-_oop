#include <iostream>>
#include <stdexcept>
#include "Person.h"
using namespace std;

int main()
{
    try
    {
        Person person1("Bob");
        Person person2("Sally");
        // Person person3("John"); // Bị chú thích (comment), nếu bỏ chú thích sẽ gây lỗi ném ngoại lệ
        Person person4("William");

        cout << person1.getName() << endl;
        cout << person2.getName() << endl;
        // cout << person3.getName() << endl;
        cout << person4.getName() << endl;
    }
    catch (const runtime_error &err)
    {
        cout << err.what() << endl;
    }
}

//---  noexcept
// Nếu bạn bỏ dấu chú thích (comment) để tạo đối tượng tên "John", chương trình sẽ hoạt động như sau:

// Chương trình bị dừng đột ngột (crash): Khi chạy đến lệnh Person person3("John");, hàm tạo sẽ gọi setName("John"). Bên trong setName, điều kiện name != "John" không thỏa mãn, chương trình nhảy vào nhánh else và thực thi lệnh throw runtime_error(...).

// Khối catch không kịp bắt lỗi: Do ngoại lệ được ném ra từ hàm Person::setName (được gọi ngầm bên trong hàm khởi tạo của đối tượng toàn cục/cục bộ), cơ chế dọn dẹp bộ nhớ và thoát khỏi khối try sẽ xảy ra xung đột với hàm khởi tạo. Lỗi này sẽ không được xử lý bình thường mà sẽ kích hoạt cơ chế terminate() của C++, dẫn đến việc ứng dụng của bạn bị đóng ngay lập tức.