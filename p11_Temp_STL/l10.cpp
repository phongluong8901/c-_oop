#include <iostream>
#include <map>           // Thư viện hỗ trợ std::map
#include <unordered_map> // Thư viện hỗ trợ std::unordered_map
#include <string>
using namespace std;

int main()
{
    // In tiêu đề phân cách phần std::map
    cout << "=== std::map ===" << endl;

    // Khởi tạo orderedMap với Khóa (Key) là string và Giá trị (Value) là int
    map<string, int> orderedMap;
    orderedMap["banana"] = 3; // Gán giá trị 3 cho khóa "banana"
    orderedMap["apple"] = 5;  // Gán giá trị 5 cho khóa "apple"
    orderedMap["cherry"] = 2; // Gán giá trị 2 cho khóa "cherry"

    // Thông báo các khóa sẽ được tự động sắp xếp theo thứ tự bảng chữ cái
    cout << "Contents of ordered map (keys will be sorted):" << endl;

    // Duyệt qua từng cặp phần tử trong orderedMap
    for (const auto &pair : orderedMap)
    {
        // In ra Khóa (pair.first) và Giá trị (pair.second)
        cout << pair.first << ": " << pair.second << endl;
    }

    // Tìm kiếm khóa "apple" trong orderedMap
    cout << "\nLooking up 'apple' in orderedMap: ";
    auto it1 = orderedMap.find("apple");

    // Kiểm tra xem iterator trỏ tới có khác vị trí cuối (end) hay không (nghĩa là có tìm thấy)
    if (it1 != orderedMap.end())
    {
        cout << "Found, value = " << it1->second << endl;
    }
    else
    {
        cout << "Not found!" << endl;
    }

    cout << endl
         << endl;
    cout << "=== std::unordered_map ===" << endl;

    // Khởi tạo unorderedMap
    unordered_map<string, int> unorderedMap;
    unorderedMap["banana"] = 3; // Gán giá trị 3 cho khóa "banana"
    unorderedMap["apple"] = 5;  // Gán giá trị 5 cho khóa "apple"
    unorderedMap["cherry"] = 2; // Gán giá trị 2 cho khóa "cherry"

    // Thông báo dữ liệu không được đảm bảo thứ tự
    cout << "Contents of unordered map (no guaranteed order):" << endl;

    // Duyệt và in các phần tử trong unorderedMap
    for (const auto &pair : unorderedMap)
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Tìm kiếm khóa "apple" trong unorderedMap
    cout << "\nLooking up 'apple' in unorderedMap: ";
    auto it2 = unorderedMap.find("apple");

    // Kiểm tra kết quả tìm kiếm
    if (it2 != unorderedMap.end())
    {
        cout << "Found, value = " << it2->second << endl;
    }
    else
    {
        cout << "Not found." << endl;
    }

    // Trả về 0 để kết thúc chương trình thành công
    return 0;
}

//
// std::map
// Khi bạn cần dữ liệu in ra phải có thứ tự hoặc cần duyệt các phần tử theo dải giá trị (range queries).

// std::unordered_map
// Khi bạn chỉ cần tốc độ tra cứu cực nhanh và không quan tâm đến thứ tự của dữ liệu.