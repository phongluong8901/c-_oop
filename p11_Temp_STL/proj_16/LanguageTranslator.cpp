#include "LanguageTranslator.h"
#include <iostream>
using namespace std;

// Triển khai phương thức thêm/cập nhật bản dịch
void LanguageTranslator::addTranslation(const string &englishWord, const string &translatedWord)
{
    // Toán tử [] sẽ tạo mới nếu chưa có khóa (key) hoặc ghi đè giá trị (value) nếu khóa đã tồn tại
    translations[englishWord] = translatedWord;
}

// Triển khai phương thức tra cứu từ dịch
string LanguageTranslator::getTranslation(const string &englishWord) const
{
    // Dùng phương thức find của map để tìm kiếm khóa hiệu quả, tránh tạo phần tử thừa
    auto it = translations.find(englishWord);

    // Kiểm tra xem iterator có trỏ tới cuối bản đồ hay không (nghĩa là có tìm thấy hay không)
    if (it != translations.end())
    {
        return it->second; // Trả về phần giá trị (translatedWord) tương ứng
    }
    else
    {
        return "NOT FOUND"; // Trả về thông báo nếu không tìm thấy khóa trong map
    }
}

// Triển khai phương thức in toàn bộ bản dịch
void LanguageTranslator::printAll() const
{
    // Duyệt qua từng cặp khóa-giá trị (pair) trong map bằng vòng lặp for nâng cao
    for (const auto &pair : translations)
    {
        cout << pair.first << " -> " << pair.second << endl;
    }
}