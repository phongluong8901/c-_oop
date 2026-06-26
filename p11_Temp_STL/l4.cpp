#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    // Khởi tạo một hàng đợi (queue) có tên là names để lưu trữ các chuỗi (string)
    queue<string> names;

    // Lần lượt đẩy các tên vào cuối hàng đợi (phía sau)
    names.push("John");
    names.push("Sally");
    names.push("Bob");
    names.push("Sam");
    names.push("Ali");
    names.push("Karen");

    // Sử dụng vòng lặp while để kiểm tra xem hàng đợi có còn phần tử hay không
    // Điều kiện !names.empty() có nghĩa là "chừng nào hàng đợi chưa rỗng thì còn lặp"
    while (!names.empty())
    {
        // In ra phần tử nằm ở đầu hàng đợi (phần tử được thêm vào sớm nhất)
        cout << names.front() << endl;

        // Loại bỏ phần tử ở đầu hàng đợi sau khi đã in ra để chuyển sang phần tử tiếp theo
        names.pop();
    }

    // Trả về 0 để kết thúc chương trình thành công
    return 0;
}