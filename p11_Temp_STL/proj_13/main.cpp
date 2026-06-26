#include "Buffer.h" // Nạp tập tin tiêu đề Buffer.h
#include <iostream>
using namespace std;

int main()
{

    cout << "\nCreating Buffer a...." << endl;
    Buffer a("Hello"); // Gọi Constructor (Khởi tạo vùng nhớ chứa "Hello")

    cout << "\nCopying a to b ..." << endl;
    Buffer b = a; // Gọi Copy Constructor (Tạo bản sao sâu của 'a' gán cho 'b')

    cout << "\nMoving a to c..." << endl;
    Buffer c = move(a); // Gọi Move Constructor (Chuyển giao tài nguyên từ 'a' sang 'c', 'a' bị vô hiệu hóa)

    cout << "\nAssigning b to d..." << endl;
    Buffer d("Temp"); // Gọi Constructor thông thường cho 'd'
    d = b;            // Gọi Copy Assignment (Gán chép đè nội dung từ 'b' sang 'd')

    cout << "\nMoving c to e..." << endl;
    Buffer e("Temp"); // Gọi Constructor thông thường cho 'e'
    e = move(c);      // Gọi Move Assignment (Di chuyển tài nguyên từ 'c' sang 'e')

    cout << "\nPrinting all buffers..." << endl;

    // In ra màn hình nội dung của các Buffer còn giữ tài nguyên
    b.print();
    d.print();
    e.print();

    cout << "\nEnd of main" << endl;

    return 0; // Kết thúc chương trình, các biến (b, d, e) sẽ tự động gọi Destructor theo thứ tự ngược lại khi ra khỏi scope
}