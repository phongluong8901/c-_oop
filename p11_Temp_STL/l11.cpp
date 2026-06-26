#include <iostream>
#include <vector>
#include <algorithm> // Thư viện bắt buộc để sử dụng thuật toán remove
using namespace std;

// Khai báo nguyên mẫu hàm xuất vector
void printVector(const vector<int> &vec);

int main()
{
    // Khởi tạo và điền sẵn các phần tử vào vector, chứa nhiều số 2 lặp lại
    vector<int> numbers = {1, 2, 3, 2, 4, 2, 5, 2};

    // In ra vector ban đầu trước khi xử lý
    cout << "Original vector: ";
    printVector(numbers);

    // Bước 1: Sử dụng thuật toán remove để dời các phần tử cần xóa (số 2) ra phía sau
    // Thuật toán này không làm thay đổi kích thước vector thực tế mà chỉ trả về iterator đánh dấu điểm kết thúc mới
    auto newEnd = remove(numbers.begin(), numbers.end(), 2);

    // Bước 2: Xóa các phần tử rác từ điểm mới (newEnd) đến điểm kết thúc cũ (end)
    // Phương thức erase thực sự cắt bỏ các phần tử thừa này và thu nhỏ kích thước của vector
    numbers.erase(newEnd, numbers.end());

    // In ra vector sau khi đã loại bỏ hoàn toàn số 2
    cout << "Vector after removing all 2s: ";
    printVector(numbers);

    // Trả về 0 để kết thúc chương trình thành công
    return 0;
}

// Định nghĩa hàm in từng phần tử trong vector cách nhau bởi khoảng trắng
void printVector(const vector<int> &vec)
{
    for (int value : vec)
    {
        cout << value << " ";
    }
    cout << endl;
}