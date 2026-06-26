#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Person
{
public:
    string name;
    int age;

    // Hàm khởi tạo thông thường (Constructor)
    Person(string name, int age) : name(name), age(age)
    {
        cout << "Constructed: " << name << endl;
    }

    // Hàm khởi tạo sao chép (Copy Constructor)
    Person(const Person &other)
    {
        name = other.name;
        age = other.age;
        cout << "Copied: " << name << endl;
    }
};

int main()
{
    // Khởi tạo một vector rỗng chứa các đối tượng Person
    vector<Person> people;

    // In thông báo chuẩn bị chèn phần tử bằng push_back
    cout << "\nUsing push back:" << endl;

    // Tạo sẵn đối tượng p1 ở bên ngoài vector
    Person p1("Alice", 30); // Dòng này sẽ gọi hàm khởi tạo (Constructed: Alice)

    // Đẩy p1 vào vector
    // push_back phải tạo một bản sao (copy) của p1 để đưa vào bộ nhớ của vector
    people.push_back(p1); // Dòng này sẽ gọi hàm copy (Copied: Alice)

    // In thông báo chuẩn bị chèn phần tử bằng emplace_back
    cout << "\nUsing emplace back:" << endl;

    // Truyền trực tiếp tham số ("Bob", 40) vào vector
    // emplace_back sẽ gọi trực tiếp hàm khởi tạo ngay bên trong bộ nhớ của vector mà không cần tạo bản sao tạm thời
    people.emplace_back("Bob", 40); // Dòng này chỉ gọi hàm khởi tạo (Constructed: Bob)

    // Trả về 0 để kết thúc chương trình thành công
    return 0;
}

//
// push_back Thấp hơn vì tốn thêm tài nguyên và thời gian để copy/di chuyển đối tượng.
// emplace_back Tối ưu hơn vì không phải qua bước tạo bản sao trung gian.

// --
// Dòng code Person p1("Alice", 30); là lệnh khởi tạo một đối tượng (một thực thể) có tên là p1 thuộc lớp Person.

// Khi hệ thống (trình biên dịch và máy tính) thực thi dòng lệnh này, quy trình diễn ra như sau:

// 1. Cấp phát bộ nhớ
// Hệ thống tìm một vùng nhớ trống đủ lớn để chứa đối tượng p1.

// Kích thước vùng nhớ này sẽ bằng tổng kích thước các thuộc tính bên trong lớp Person (trong trường hợp này là kích thước của chuỗi string name cộng với số nguyên int age).

// 2. Gọi hàm tạo (Constructor)
// Hệ thống sẽ tìm đến hàm khởi tạo của lớp Person có cấu trúc khớp với tham số truyền vào, cụ thể là:
// Person(string name, int age) : name(name), age(age)

// Các giá trị "Alice" và 30 được truyền vào các tham số tương ứng.

// 3. Gán giá trị cho thuộc tính
// Danh sách khởi tạo : name(name), age(age) thực hiện việc gán trực tiếp dữ liệu vào các thuộc tính bên trong đối tượng p1.

// Lúc này, thuộc tính p1.name mang giá trị "Alice" và p1.age mang giá trị 30.

// 4. Thực thi thân hàm
// Chương trình chạy khối lệnh bên trong hàm khởi tạo.

// Dòng lệnh cout << "Constructed: " << name << endl; được thực thi, in ra màn hình dòng chữ:
// Constructed: Alice