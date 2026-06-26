#ifndef LANGUAGE_TRANSLATOR_H // Kiểm tra macro để tránh nạp header file nhiều lần
#define LANGUAGE_TRANSLATOR_H

#include <string>
#include <map>
using namespace std;

class LanguageTranslator
{
public:
    // Thêm hoặc cập nhật từ điển (Khóa: từ tiếng Anh, Giá trị: từ đã dịch)
    void addTranslation(const string &englishWord, const string &translatedWord);

    // Tra cứu từ tiếng Anh (trả về kết quả hoặc "NOT FOUND"), dùng const để bảo vệ trạng thái lớp
    string getTranslation(const string &englishWord) const;

    // In ra toàn bộ danh sách các cặp từ điển, const để không làm thay đổi dữ liệu
    void printAll() const;

private:
    // Sử dụng std::map để lưu trữ các cặp khóa-giá trị (tự động sắp xếp theo từ khóa tiếng Anh)
    map<string, string> translations;
};

#endif