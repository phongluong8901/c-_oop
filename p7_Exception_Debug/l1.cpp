#include <iostream>  // Nạp thư viện nhập/xuất chuẩn (cho phép dùng cout, cerr, endl)
#include <vector>    // Nạp thư viện quản lý mảng động vector
#include <stdexcept> // Nạp thư viện xử lý ngoại lệ (cho phép dùng length_error)

using namespace std; // Sử dụng không gian tên chuẩn để khỏi viết std::

int main()
{ // Hàm chính, điểm bắt đầu chạy chương trình

    vector<int> myNums; // Khởi tạo vector số nguyên rỗng tên là myNums

    try
    {                                         // Mở đầu khối theo dõi lỗi
        myNums.resize(myNums.max_size() + 1); // Cố gắng tăng kích thước vượt mức tối đa -> gây lỗi
    }
    catch (const length_error &err)
    {                                                            // Bắt lỗi length_error nếu xảy ra và lưu vào biến err
        cerr << "Caught a length_error: " << err.what() << endl; // In chi tiết lỗi ra màn hình
    }

    cout << "Yay it's a big vector!" << endl; // In thông báo tiếp theo ra màn hình

    return 0; // Báo cáo chương trình kết thúc thành công
}