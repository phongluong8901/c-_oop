#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
using namespace std;

int main()
{
    Dog dog("Rover", 80, "Greyhound");

    // Here is the key line:
    Animal *dogPtr = new Dog("Fido", 115, "Golden Retriever");
    Animal *catPtr = new Cat("Felix", 12);

    cout << "Dog says: " << dogPtr->makeNoise() << endl;
    cout << "Dog eats: " << dogPtr->eat() << endl;

    cout << "Cat says: " << catPtr->makeNoise() << endl;
    cout << "Cat eats: " << catPtr->eat() << endl;

    // (Cat*)catPtr or reinterpret_cat<Cat*>(catPtr)
    Cat *realCat = dynamic_cast<Cat *>(catPtr);
    if (realCat)
    {
        realCat->chaseMouse();
    }

    delete dogPtr;
    dogPtr = nullptr;

    delete catPtr;
    catPtr = nullptr;

    return 0;
}

//
// 2. Khởi tạo đối tượng trên Heap (new)
// Trong hàm main, các dòng sau cấp phát bộ nhớ động trên vùng nhớ Heap:

// C++

// Animal *dogPtr = new Dog("Fido", 115, "Golden Retriever");
// Animal *catPtr = new Cat("Felix", 12);
// Trình biên dịch tạo ra một thực thể Dog và Cat trong bộ nhớ, sau đó trả về địa chỉ của chúng.

// Địa chỉ này được lưu giữ trong các con trỏ dogPtr và catPtr có kiểu Animal*.

//
// 3. Thực thi tính đa hình
// Khi chương trình chạy các lệnh:

// C++

// cout << "Dog says: " << dogPtr->makeNoise() << endl;
// cout << "Cat says: " << catPtr->makeNoise() << endl;
// Trình biên dịch nhận thấy makeNoise() là một hàm ảo (virtual).

// Thay vì gọi hàm của lớp Animal, nó sẽ tra cứu bảng hàm ảo (vtable) tại thời điểm chạy (runtime) để gọi đúng hàm makeNoise() của Dog và Cat.

// Kết quả: In ra Woof! cho chó và Meow! cho mèo.

//
// 4. Ép kiểu động (dynamic_cast)
// Đoạn code này cực kỳ an toàn và phổ biến khi làm việc với con trỏ đa hình:

// C++

// Cat *realCat = dynamic_cast<Cat *>(catPtr);
// if (realCat)
// {
//     realCat->chaseMouse();
// }
// Tại sao phải dùng dynamic_cast? Con trỏ catPtr có kiểu là Animal*. Nó không thể gọi trực tiếp hàm chaseMouse() (vì chaseMouse() chỉ có ở lớp Cat, lớp Animal không biết gì về nó).

// dynamic_cast giúp kiểm tra xem vùng nhớ mà catPtr đang trỏ tới có thực sự là một đối tượng Cat (hoặc lớp con của Cat) hay không.

// Nếu đúng, nó trả về địa chỉ hợp lệ và gán vào realCat. Nếu sai (ví dụ catPtr đang trỏ tới Dog), nó sẽ trả về nullptr.

//
// 5. Dọn dẹp bộ nhớ (Memory Cleanup)
// C++

// delete dogPtr;
// dogPtr = nullptr;

// delete catPtr;
// catPtr = nullptr;
// Khi bạn sử dụng từ khóa new để cấp phát bộ nhớ động, bạn bắt buộc phải dùng delete để giải phóng RAM khi không còn sử dụng, tránh gây ra tình trạng rò rỉ bộ nhớ (Memory Leak).

// Gán con trỏ bằng nullptr sau khi xóa là một thói quen tốt để tránh con trỏ treo (Dangling Pointer), ngăn chặn việc vô tình truy cập lại vùng nhớ đã bị hủy.

//----
// 2. Tác dụng của đoạn code dynamic_cast
// Để hiểu tác dụng của đoạn code này, hãy xem xét giới hạn của con trỏ đa hình:

// Con trỏ catPtr được khai báo là kiểu Animal*. Mặc dù thực tế nó đang trỏ đến một đối tượng Cat (ở vùng nhớ Heap), trình biên dịch chỉ cho phép catPtr gọi những gì có trong khuôn mẫu Animal.

// Trong lớp Animal, không hề có hàm chaseMouse(). Hàm này chỉ xuất hiện ở lớp Cat.

// Nếu bạn viết catPtr->chaseMouse(); trực tiếp, trình biên dịch sẽ báo lỗi ngay lập tức vì nó không tìm thấy hàm này trong Animal.

// Tác dụng của dynamic_cast:
// Đoạn code này giống như một nhân viên bảo vệ kiểm tra thực tế tại vùng nhớ:

// dynamic_cast<Cat*>(catPtr) nhìn vào vùng nhớ mà catPtr đang trỏ tới. Nó hỏi: "Đây có thực sự là một con mèo không?"

// Nếu đúng là mèo, nó sẽ mở khóa và trả về địa chỉ hợp lệ, gán vào con trỏ realCat. Lúc này, realCat có đầy đủ quyền hạn của một con mèo, nên có thể gọi realCat->chaseMouse();.

// Nếu vùng nhớ đó thực chất là một con chó (Dog), dynamic_cast sẽ trả về giá trị nullptr (tức là rỗng/sai). Lệnh if (realCat) sẽ nhận giá trị false, khối lệnh bên trong bị bỏ qua, giúp chương trình không bị treo hay sập đột ngột.