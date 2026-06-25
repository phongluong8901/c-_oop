#include <iostream>
#include <array>
using namespace std;

int main()
{

    array<int, 5> myIntArray{1, 2}; //

    myIntArray[0] = 2;
    myIntArray[1] = 5;
    myIntArray[2] = 10;
    myIntArray[3] = 1;
    myIntArray[4] = 17;

    for (int a : myIntArray)
    {
        cout << a << endl;
    }

    cout << "Size of the array: " << myIntArray.size() << endl;

    return 0;
}

// Chỉ số (Index): Mảng trong C++ bắt đầu từ chỉ số 0 đến 4 (với kích thước 5 phần tử).

// Giá trị khởi tạo {1, 2}: * Hai phần tử đầu tiên nhận giá trị tương ứng là 1 và 2.

// Các phần tử còn lại: Các chỉ số 2, 3, và 4 không được gán giá trị cụ thể trong ngoặc nhọn nên sẽ tự động được khởi tạo giá trị mặc định là 0.
//--
// Sau bước này, khi chương trình chạy qua các lệnh:

// C++

// myIntArray[0] = 2;
// myIntArray[1] = 5;
// myIntArray[2] = 10;
// myIntArray[3] = 1;
// myIntArray[4] = 17;
// Các giá trị cũ (1, 2, 0, 0, 0) sẽ bị ghi đè hoàn toàn bởi các giá trị mới tương ứng là 2, 5, 10, 1, và 17