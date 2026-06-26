#include <iostream>
#include <string>

using namespace std;

// Các dòng bị chú thích dưới đây là ví dụ minh họa nếu không dùng Template.
// Bạn sẽ phải viết chồng hàm (function overloading) cho từng kiểu dữ liệu riêng biệt.
// double getBigger(double a, double b);
// int getBigger(int a, int b);
// string getBigger(string a, string b);

// Khai báo Function Template trả về giá trị lớn hơn giữa hai biến.
// Chữ 'T' đại diện cho một kiểu dữ liệu tổng quát (Generic Data Type).
template <class T>
T getBigger(T a, T b)
{
    // Sử dụng toán tử ba ngôi (ternary operator) để so sánh.
    // Trả về 'a' nếu a > b, ngược lại trả về 'b'.
    return (a > b) ? a : b;
}

// Khai báo Function Template trả về giá trị nhỏ hơn giữa hai biến.
template <class T>
T getSmaller(T a, T b)
{
    // Trả về 'a' nếu a < b, ngược lại trả về 'b'.
    return (a < b) ? a : b;
}

// Hàm main - điểm bắt đầu của chương trình.
int main()
{

    // Khai báo và khởi tạo các biến với nhiều kiểu dữ liệu khác nhau (double, int, string).
    double d1 = 3.14;
    double d2 = 5.55;
    int i1 = 11;
    int i2 = 9;
    string s1 = "Alice";
    string s2 = "John";

    // Gọi hàm template getBigger. Trình biên dịch sẽ tự động nhận diện kiểu dữ liệu truyền vào.
    double biggerDub = getBigger(d1, d2); // T là double
    int biggerInt = getBigger(i1, i2);    // T là int
    string biggerStr = getBigger(s1, s2); // T là string

    // Gọi hàm template getSmaller.
    double smallerDub = getSmaller(d1, d2);
    int smallerInt = getSmaller(i1, i2);
    string smallerString = getSmaller(s1, s2);

    // In tiêu đề ra màn hình console.
    cout << "Bigger items:" << endl;
    // In kết quả các phần tử lớn hơn, sử dụng tab (\t) để căn lề.
    cout << "\t" << biggerDub << "\n\t" << biggerInt << "\n\t" << biggerStr << endl;

    cout << "Smaller items:" << endl;
    cout << "\t" << smallerDub << endl;
    cout << "\t" << smallerInt << endl;
    cout << "\t" << smallerString << endl;

    // Kết thúc chương trình, trả về 0 cho hệ điều hành.
    return 0;
}

// Phần code chú thích này minh họa cách viết truyền thống nếu không dùng template.
// Bạn có thể thấy code bị lặp lại phần thân hàm y hệt nhau cho các kiểu dữ liệu khác nhau.
// double getBigger(double a, double b) {
//  return (a > b) ? a : b;
// }
//
// int getBigger(int a, int b) {
//  return (a > b) ? a : b;
// }
//
// string getBigger(string a, string b) {
//  return (a > b) ? a : b;
// }

//--
// Đoạn code template <class T> trong C++ được dùng để lập trình tổng quát (Generic Programming), hay còn gọi là Function Template (Khuôn mẫu hàm).

// Ý nghĩa và tác dụng của T
// Chữ T (viết tắt của Type - Kiểu dữ liệu) đóng vai trò là một kiểu dữ liệu đại diện tạm thời.

// Tác dụng thay thế: Thay vì bạn phải viết riêng một hàm getSmaller cho kiểu int, một hàm cho kiểu double, và một hàm cho kiểu string, bạn chỉ cần định nghĩa một hàm duy nhất với kiểu T.

// Tự động nhận diện: Khi bạn gọi hàm (ví dụ: truyền vào hai số nguyên i1 và i2), trình biên dịch C++ sẽ tự động hiểu T là int và sinh ra phiên bản hàm tương ứng. Nếu bạn truyền vào hai chuỗi s1 và s2, T sẽ tự động biến thành string.

// Giải mã cú pháp chi tiết
// C++

// template <class T>
// T getSmaller(T a, T b)
// {
//     return (a < b) ? a : b;
// }
// template <class T>: Khai báo cho trình biên dịch biết đây là một khuôn mẫu và có sử dụng một kiểu dữ liệu chung đặt tên là T (bạn cũng có thể dùng từ khóa typename thay cho class: template <typename T>).

// T getSmaller: Chữ T đứng đầu tiên có nghĩa là hàm này sẽ trả về một giá trị có kiểu dữ liệu khớp với kiểu dữ liệu của hai tham số truyền vào.

// T a, T b: Hai tham số đầu vào a và b phải có cùng một kiểu dữ liệu T.

//--
// Mỗi khối template <class T> chỉ có hiệu lực cho ngay cái hàm nằm ngay bên dưới nó mà thôi. Đó là lý do vì sao bạn cần phải viết lặp lại từ khóa này cho cả hàm getBigger và hàm getSmaller.