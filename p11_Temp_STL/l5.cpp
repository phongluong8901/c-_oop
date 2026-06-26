#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    // Khởi tạo một map có tên là contacts với cả Khóa (Key) và Giá trị (Value) đều là kiểu string
    // Mỗi phần tử trong map sẽ lưu thông tin gồm Tên (Khóa) và Số điện thoại (Giá trị)
    map<string, string> contacts;

    // Thêm các phần tử vào map bằng cách gán Giá trị cho Khóa
    // Map sẽ tự động sắp xếp các phần tử theo thứ tự bảng chữ cái của Khóa (theo tên)
    contacts["John Baugh"] = "313-555-5555";
    contacts["Bob Robinson"] = "734-555-5050";
    contacts["Sally Snorkle"] = "810-555-8888";

    // Sử dụng vòng lặp for nâng cao với từ khóa auto để duyệt qua từng phần tử trong map
    // Mỗi phần tử element trong map thực chất là một cặp giá trị (std::pair)
    for (auto element : contacts)
    {
        // element.first đại diện cho Khóa (Tên người liên hệ)
        // element.second đại diện cho Giá trị (Số điện thoại)
        cout << element.first << " = " << element.second << endl;
    }

    // Trả về 0 để kết thúc chương trình thành công
    return 0;
}

//
// Từ khóa auto trong C++ (từ phiên bản C++11 trở đi) là một tính năng giúp tự động nhận diện kiểu dữ liệu của biến tại thời điểm biên dịch.

// Thay vì bạn phải viết rõ ràng kiểu dữ liệu như int, double, hay string, trình biên dịch sẽ tự động nhìn vào giá trị khởi tạo ở bên phải để suy ra kiểu dữ liệu phù hợp.