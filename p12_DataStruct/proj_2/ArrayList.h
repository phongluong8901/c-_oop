#ifndef ARRAY_LIST_H // Kiểm tra để ngăn việc định nghĩa lại tệp tiêu đề
#define ARRAY_LIST_H

#include <iostream> // Thư viện nhập xuất chuẩn
#include "List.h"   // Nạp tệp giao diện List
using namespace std;

// Lớp ArrayList kế thừa công khai từ lớp trừu tượng List
class ArrayList : public List
{
public:
    // Hàm khởi tạo: Cấp phát mảng tĩnh trên heap với kích thước mặc định là 16
    ArrayList(int s = 16) : MAX_SIZE(s)
    {
        mArray = new int[MAX_SIZE]; // Cấp phát vùng nhớ cho mảng
        mNumElements = 0;           // Đặt số lượng phần tử ban đầu bằng 0
    } // end ctor

    // Phương thức thêm phần tử vào cuối danh sách
    void add(int newEntry) override
    {
        // Kiểm tra xem mảng đã đầy chưa trước khi thêm
        if (mNumElements >= MAX_SIZE)
        {
            cout << "Cannot add any more elements.  List is full." << endl;
            return;
        }

        // Gán giá trị mới, sau đó tăng biến đếm phần tử lên 1
        mArray[mNumElements++] = newEntry;
    } // end add

    // Phương thức thêm phần tử vào một vị trí (position) chỉ định
    void add(int newEntry, int position) override
    {
        // Kiểm tra mảng có đầy không
        if (mNumElements >= MAX_SIZE)
        {
            cout << "List is full.  Cannot add element." << endl;
            return;
        }

        // Kiểm tra vị trí truyền vào có hợp lệ (từ 0 đến mNumElements hiện tại)
        if (position < 0 || position > mNumElements)
        {
            cout << "Position out of range." << endl;
            return;
        }

        // Dịch chuyển các phần tử từ vị trí position sang phải 1 ô để tạo chỗ trống
        for (int i = mNumElements; i > position; i--)
        {
            mArray[i] = mArray[i - 1];
        }

        // Gán giá trị mới vào đúng vị trí cần chèn và tăng tổng số phần tử
        mArray[position] = newEntry;
        mNumElements++;
    } // end add

    // Phương thức thay đổi/ghi đè giá trị tại vị trí chỉ định
    void set(int newEntry, int position) override
    {
        // Kiểm tra vị trí hợp lệ (vị trí phải nằm trong các ô đã có dữ liệu)
        if (position < 0 || position >= mNumElements)
        {
            cout << "Invalid position for set." << endl;
            return;
        }

        mArray[position] = newEntry; // Ghi đè dữ liệu mới
    } // end set

    // Kiểm tra xem một giá trị có tồn tại trong danh sách không
    bool contains(int entry) const override
    {
        // Duyệt qua từng phần tử thực tế
        for (int i = 0; i < mNumElements; i++)
        {
            if (mArray[i] == entry) // Nếu tìm thấy giá trị khớp
            {
                return true; // Trả về true ngay lập tức
            }
        } // end for
        return false; // Trả về false nếu duyệt hết mà không thấy
    } // end contains

    // Tìm kiếm và trả về vị trí (index) của giá trị cần tìm
    int find(int entry) const override
    {
        for (int i = 0; i < mNumElements; i++)
        {
            if (mArray[i] == entry)
            {
                return i; // Trả về chỉ số index
            }
        } // end for
        return -1; // Trả về -1 nếu không tìm thấy
    } // end find

    // Xóa phần tử tại vị trí chỉ định và trả về giá trị vừa xóa
    int remove(int position) override
    {
        // Kiểm tra vị trí hợp lệ trước khi xóa
        if (position < 0 || position >= mNumElements)
        {
            cout << "Position out of range." << endl;
            return -1;
        }

        int value = mArray[position]; // Lưu lại giá trị của phần tử cần xóa

        // Dịch chuyển các phần tử phía sau sang trái 1 ô để lấp đầy chỗ trống
        for (int i = position; i < mNumElements - 1; i++)
        {
            mArray[i] = mArray[i + 1];
        } // end for

        mNumElements--; // Giảm tổng số phần tử đi 1
        return value;   // Trả về giá trị đã xóa
    } // end remove

    // Làm trống danh sách (chỉ cần đặt lại số phần tử về 0)
    void makeEmpty() override
    {
        mNumElements = 0;
    } // end makeEmpty

    // Trả về kích thước số phần tử hiện tại
    int size() const override
    {
        return mNumElements;
    } // end size

    // Kiểm tra danh sách rỗng
    bool isEmpty() const override
    {
        return mNumElements == 0;
    } // end isEmpty

    // In toàn bộ danh sách ra màn hình console
    void printList() const override
    {
        for (int i = 0; i < mNumElements; i++)
        {
            cout << mArray[i] << endl;
        }
    }

private:
    int *mArray;        // Con trỏ quản lý mảng số nguyên trên vùng nhớ heap
    const int MAX_SIZE; // Hằng số quy định sức chứa tối đa của mảng
    int mNumElements;   // Biến đếm số lượng phần tử đang được lưu trữ thực tế
};

#endif