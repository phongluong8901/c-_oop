#include <iostream> // Thư viện nhập xuất cơ bản trong C++
#include <deque>    // Thư viện hỗ trợ sử dụng cấu trúc dữ liệu deque (Double-ended queue)
using namespace std;

// Khai báo nguyên mẫu hàm (prototype) để trình biên dịch nhận biết hàm printDeque trước khi hàm main sử dụng
void printDeque(const deque<int> &deck);

int main()
{
    // Khởi tạo một deque rỗng có tên là myDeck để lưu trữ các số nguyên
    deque<int> myDeck;

    // Chèn phần tử số 1 vào cuối deque (deque hiện tại: 1)
    myDeck.push_back(1);

    // Chèn phần tử số 5 vào cuối deque (deque hiện tại: 1, 5)
    myDeck.push_back(5);

    // Chèn phần tử số 10 vào cuối deque (deque hiện tại: 1, 5, 10)
    myDeck.push_back(10);

    // In ra màn hình tiêu đề cho lần in đầu tiên
    cout << "First print:" << endl;

    // Gọi hàm printDeque để xuất các phần tử của myDeck ra màn hình
    printDeque(myDeck);

    // Chèn phần tử số 20 vào đầu deque (deque hiện tại: 20, 1, 5, 10)
    myDeck.push_front(20);

    // Chèn phần tử số 30 vào đầu deque (deque hiện tại: 30, 20, 1, 5, 10)
    myDeck.push_front(30);

    // In ra màn hình tiêu đề cho lần in tiếp theo
    cout << "Next print:" << endl;

    // Gọi hàm printDeque để xuất các phần tử đã cập nhật ra màn hình
    printDeque(myDeck);

    // Trả về 0 để kết thúc chương trình thành công
    return 0;
}

// Định nghĩa chi tiết hàm xuất deque
// Sử dụng const và tham chiếu & để tránh sao chép dữ liệu, giúp chương trình chạy nhanh và an toàn hơn
void printDeque(const deque<int> &deck)
{
    // Sử dụng vòng lặp for nâng cao (range-based for loop) để duyệt qua từng số nguyên num trong deque deck
    for (int num : deck)
    {
        // In giá trị của phần tử hiện tại kèm theo xuống dòng
        cout << num << endl;
    }
    // In thêm một dòng trống để phân cách rõ ràng giữa các lần in
    cout << endl;
}