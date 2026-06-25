// ScopeFun

#include <iostream>  // Nạp thư viện nhập/xuất chuẩn
using namespace std; // Sử dụng không gian tên chuẩn

void someFunction(int aParam); // Khai báo nguyên mẫu hàm someFunction

double myGlobalDouble = 3.1415; // Khai báo biến toàn cục (Global variable)

int main() // Hàm chính của chương trình
{
    int localToMain = 20; // Khai báo biến cục bộ trong main

    cout << "The local to main variable is: " << localToMain << endl;
    cout << "The global double (in main) is: " << myGlobalDouble << endl;

    someFunction(25); // Gọi hàm với tham số 25
    someFunction(28); // Gọi hàm với tham số 28
    someFunction(32); // Gọi hàm với tham số 32

    // cout << myLocalNum << endl; // LỖI: myLocalNum chỉ sống trong hàm someFunction, main không dùng được

    return 0; // Kết thúc hàm main thành công
}

void someFunction(int aParam) // Định nghĩa hàm someFunction
{
    int myLocalNum = 100; // Biến cục bộ, được tạo mới mỗi khi hàm này chạy
    myLocalNum++;         // Tăng lên 101

    static int myStatic = 500; // Biến tĩnh: chỉ khởi tạo 1 lần duy nhất, giữ nguyên giá trị qua các lần gọi hàm
    myStatic++;                // Tăng lên (lần 1: 501, lần 2: 502, lần 3: 503)

    myGlobalDouble++; // Tăng biến toàn cục lên 1 (ảnh hưởng toàn bộ chương trình)

    cout << "My local number: " << myLocalNum << endl;
    cout << "The parameter is: " << aParam << endl;
    cout << "Global double (in someFunction) is: " << myGlobalDouble << endl;
    cout << "myStatic: " << myStatic << endl;

    // localToMain++;           // LỖI: someFunction không thể nhìn thấy biến localToMain của hàm main
}

// Giải thích nhanh các khái niệm cốt lõi:
// Biến toàn cục (myGlobalDouble): Được khai báo bên ngoài tất cả các hàm. Mọi hàm trong chương trình (cả main và someFunction) đều có thể truy cập và thay đổi nó.

// Biến cục bộ (localToMain, myLocalNum, aParam): Chỉ tồn tại bên trong hàm chứa nó. Khi hàm kết thúc, các biến này bị hủy. Hàm này không thể gọi biến cục bộ của hàm kia. (Đó là lý do dòng //cout << myLocalNum << endl; trong main hoặc //localToMain++; trong hàm sẽ bị lỗi).

// Biến tĩnh (static int myStatic = 500): Rất đặc biệt! Nó nằm trong hàm, nhưng không bị hủy khi hàm kết thúc. Lần đầu tiên gọi hàm, nó nhận giá trị 500. Ở các lần gọi tiếp theo, máy tính sẽ bỏ qua bước khởi tạo = 500 và giữ nguyên giá trị cũ để tiếp tục xử lý (tăng dần lên 501, 502, 503...).