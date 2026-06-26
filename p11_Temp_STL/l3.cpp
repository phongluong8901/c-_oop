#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Khai báo nguyên mẫu các hàm (function prototypes)
void storeReverse(const string &origString, stack<char> &reverseStack);
bool isPalindrome(const string &origString);
void printResult(const string &origString);

int main()
{

    // Khởi tạo mảng gồm 5 chuỗi để kiểm tra, bao gồm cả chuỗi đối xứng và không đối xứng
    string strArray[5] = {"racecar", "fudge", "civic", "bob", "dogs"};

    // Sử dụng vòng lặp for nâng cao để duyệt qua từng chuỗi trong mảng
    for (const string &str : strArray)
    {
        // Gọi hàm in kết quả kiểm tra palindrome
        printResult(str);
        // In khoảng trắng phân cách giữa các lần kiểm tra
        cout << endl;
    }

    // Trả về 0 để kết thúc chương trình thành công
    return 0;
}

// Định nghĩa hàm lưu trữ các ký tự của chuỗi vào stack theo thứ tự ngược lại
void storeReverse(const string &origString, stack<char> &reverseStack)
{
    // Duyệt qua từng ký tự c trong chuỗi gốc
    for (char c : origString)
    {
        // Đẩy ký tự vào stack (ký tự đầu tiên nằm ở đáy stack, ký tự cuối nằm ở đỉnh stack)
        reverseStack.push(c);
    }
}

// Định nghĩa hàm kiểm tra xem một chuỗi có phải là palindrome hay không
bool isPalindrome(const string &origString)
{
    // Khởi tạo một stack chứa các ký tự kiểu char
    stack<char> reverseStack;

    // Gọi hàm lưu ngược chuỗi vào stack
    storeReverse(origString, reverseStack);

    // Duyệt lại từng ký tự c trong chuỗi gốc từ trái sang phải
    for (char c : origString)
    {
        // So sánh ký tự ở đỉnh stack với ký tự hiện tại của chuỗi gốc
        // Nếu khác nhau, chứng tỏ không phải là palindrome, trả về false ngay lập tức
        if (reverseStack.top() != c)
        {
            return false;
        }
        // Loại bỏ ký tự vừa kiểm tra khỏi đỉnh stack để chuẩn bị so sánh ký tự tiếp theo
        reverseStack.pop();
    }

    // Nếu duyệt hết mà không có cặp nào khác nhau, đây là palindrome, trả về true
    return true;
}

// Định nghĩa hàm in kết quả ra màn hình
void printResult(const string &origString)
{
    // In chuỗi gốc và gọi hàm isPalindrome để lấy kết quả (true/false)
    // boolalpha giúp hiển thị giá trị boolean dưới dạng chữ "true" hoặc "false" thay vì số 1 hoặc 0
    cout << "Is \"" << origString << "\" a palindrome? "
         << boolalpha << isPalindrome(origString) << endl;
}