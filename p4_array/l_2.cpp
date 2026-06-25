// Vertor class

#include <iostream>  // Nạp thư viện nhập/xuất chuẩn
#include <string>    // Nạp thư viện hỗ trợ kiểu chuỗi (string)
#include <vector>    // Nạp thư viện vector (mảng động)
using namespace std; // Sử dụng không gian tên chuẩn để khỏi viết std::

int main()
{                                 // Hàm chính của chương trình
    vector<int> someVec;          // Khởi tạo vector số nguyên rỗng
    vector<string> anotherVec(3); // Khởi tạo vector chuỗi có sẵn 3 phần tử rỗng

    someVec.push_back(1); // Thêm số 1 vào cuối someVec
    someVec.push_back(2); // Thêm số 2 vào cuối someVec
    someVec.push_back(3); // Thêm số 3 vào cuối someVec

    cout << "someVec size: " << someVec.size() << endl; // In kích thước someVec (kết quả: 3)

    anotherVec[0] = "John";  // Gán phần tử đầu tiên của anotherVec là "John"
    anotherVec[1] = "Bob";   // Gán phần tử thứ hai là "Bob"
    anotherVec[2] = "Sally"; // Gán phần tử thứ ba là "Sally"

    anotherVec.push_back("Shannon"); // Thêm "Shannon" vào cuối, vector tăng lên 4 phần tử

    for (int val : someVec)
    {                        // Duyệt qua từng số nguyên val trong someVec
        cout << val << endl; // In ra giá trị val
    } // Kết thúc vòng lặp in someVec

    cout << endl; // In một dòng trống để cách biệt

    for (string name : anotherVec)
    {                         // Duyệt qua từng chuỗi name trong anotherVec
        cout << name << endl; // In ra giá trị name
    } // Kết thúc vòng lặp in anotherVec

    cout << endl;                                    // In một dòng trống
    cout << "Front and back of anotherVec:" << endl; // Tiêu đề thông báo
    cout << "front: " << anotherVec.front() << endl; // In phần tử đầu tiên (kết quả: John)
    cout << "back: " << anotherVec.back() << endl;   // In phần tử cuối (kết quả: Shannon)

    anotherVec.pop_back();                        // Xóa bỏ phần tử cuối cùng ("Shannon")
    anotherVec.insert(anotherVec.begin(), "Don"); // Chèn "Don" vào đầu vector

    cout << "\nAfter modification: " << endl;        // Thông báo sau khi sửa đổi
    cout << "front: " << anotherVec.front() << endl; // In phần tử đầu mới (kết quả: Don)
    cout << "back: " << anotherVec.back() << endl;   // In phần tử cuối mới (kết quả: Sally)

    return 0; // Kết thúc hàm main, trả về 0
} // Dấu ngoặc nhọn kết thúc chương trình

// rong đoạn code trên, std::vector đóng vai trò là một mảng động (dynamic array). Cụ thể, nó có các tác dụng và ưu điểm quan trọng sau:

// 1. Tự động thay đổi kích thước (Dynamic Sizing)
// Linh hoạt: Không giống như mảng tĩnh hay std::array (cần cố định kích thước ngay khi khai báo), vector có thể tự động co giãn bộ nhớ.

// Thực tế trong code: * Khởi tạo vector<int> someVec; ban đầu có kích thước bằng 0.

// Lệnh push_back() giúp thêm phần tử vào cuối, vector sẽ tự động cấp phát thêm bộ nhớ mà bạn không cần bận tâm về dung lượng còn lại.

// 2. Quản lý bộ nhớ tự động
// An toàn: Vector tự động cấp phát bộ nhớ trên heap và tự động giải phóng bộ nhớ đó khi vector bị hủy (ra khỏi phạm vi), giúp tránh tình trạng rò rỉ bộ nhớ (memory leak) như khi dùng mảng con trỏ kiểu cũ.

// 3. Cung cấp các phương thức thao tác dữ liệu mạnh mẽ
// Vector hỗ trợ sẵn các hàm dựng sẵn để xử lý mảng cực kỳ tiện lợi:

// Thêm/Xóa cuối: push_back() để thêm phần tử vào cuối, pop_back() để loại bỏ phần tử cuối.

// Truy xuất đầu/cuối: front() lấy phần tử đầu, back() lấy phần tử cuối.

// Chèn vị trí bất kỳ: insert() kết hợp với begin() để chèn dữ liệu vào ngay đầu mảng hoặc vị trí tùy ý.

// Kiểm tra kích thước: size() giúp biết chính xác số lượng phần tử đang có trong mảng bất cứ lúc nào.

//---for (string name : anotherVec)
// Cách nó chạy ngầm:
// Lần lặp 1: Nó tự động lấy phần tử đầu tiên ("John") ra và gán tạm vào biến name, sau đó in biến name ra màn hình (kết quả in ra là John).
// Lần lặp 2: Nó lấy phần tử thứ hai ("Bob") gán vào biến name, rồi in ra Bob.
// Cứ tiếp tục như vậy cho đến hết mảng.

//---someVec.push_back(1)
// Ý nghĩa: Đẩy giá trị 1 vào vị trí cuối cùng của vector someVec.
// Cách hoạt động: Mỗi khi gọi lệnh này, kích thước của vector sẽ tự động tăng lên 1 đơn vị. Trong code của bạn, sau khi gọi push_back(1), tiếp theo là push_back(2) và push_back(3), mảng sẽ lần lượt chứa các số 1, 2, và 3

//---anotherVec.front() và anotherVec.back()
// Đây là hai phương thức có sẵn giúp truy xuất nhanh phần tử đầu tiên và phần tử cuối cùng của vector mà không cần dùng đến chỉ số (index).
// anotherVec.front(): Trả về tham chiếu đến phần tử đầu tiên trong vector (tương đương với việc gọi anotherVec[0]).
// anotherVec.back(): Trả về tham chiếu đến phần tử cuối cùng trong vector.