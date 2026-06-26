#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
using namespace std;

class Animal
{

public:
    Animal(string name, double weight);
    string getName() const;
    void setName(string name);
    double getWeight() const;
    void setWeight(double weight);
    virtual string makeNoise() const = 0;
    virtual string eat() const = 0;

private:
    string name;
    double weight;
};

#endif

//--
// 1. Lớp trừu tượng Animal (Abstract Base Class)
// virtual string makeNoise() const = 0; và virtual string eat() const = 0; được gọi là Hàm thuần ảo (Pure Virtual Function). Việc có các hàm này biến Animal thành một lớp trừu tượng.

// Ý nghĩa: Bạn không thể khởi tạo trực tiếp một đối tượng Animal (ví dụ: Animal a("Bob", 10); sẽ bị lỗi biên dịch). Nó chỉ đóng vai trò là khuôn mẫu chung cho các lớp con.

//---
// 1. Có hay không có từ khóa virtual ảnh hưởng gì?
// Từ khóa virtual quyết định cách C++ liên kết lời gọi hàm: liên kết tĩnh (sớm) hay liên kết động (muộn).

// Trong lớp Animal:

// C++

// virtual string makeNoise() const = 0;
// Nếu bạn bỏ từ khóa virtual, hàm này sẽ trở thành hàm thông thường. C++ sẽ quyết định hàm nào được gọi dựa vào kiểu của con trỏ tại thời điểm biên dịch, chứ không quan tâm đến đối tượng thực tế dưới RAM.

// Nếu có virtual (Đa hình hoạt động): dogPtr->makeNoise() sẽ gọi hàm của Dog (in ra Woof!).

// Nếu không có virtual (Lỗi hoặc sai logic): dogPtr->makeNoise() sẽ cố gọi hàm của Animal. Tuy nhiên, ở đây makeNoise() đang là hàm thuần ảo = 0, chương trình sẽ bị lỗi biên dịch ngay lập tức và không thể chạy được. Nếu nó không phải hàm thuần ảo, chương trình sẽ gọi hàm của Animal và bỏ qua hàm của Dog, dẫn đến kết quả sai.