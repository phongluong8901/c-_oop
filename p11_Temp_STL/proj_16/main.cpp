#include <iostream>
#include <string>
#include "LanguageTranslator.h"
using namespace std;

// Khai báo các nguyên mẫu hàm xử lý giao diện menu
void printMenu();
void handleAdd(LanguageTranslator &translator);
void handleLookup(const LanguageTranslator &translator);

int main()
{
    LanguageTranslator translator; // Khởi tạo đối tượng quản lý từ điển
    int choice;                    // Biến lưu lựa chọn chức năng của người dùng

    printMenu(); // In menu lần đầu
    cin >> choice;
    cin.ignore(); // Xóa bộ nhớ đệm (loại bỏ ký tự xuống dòng \n còn sót lại)

    // Vòng lặp duy trì chương trình cho đến khi người dùng nhập số 0 để thoát
    while (choice != 0)
    {
        if (choice == 1)
        {
            handleAdd(translator); // Gọi hàm thêm/cập nhật từ
        }
        else if (choice == 2)
        {
            handleLookup(translator); // Gọi hàm tra cứu từ
        }
        else if (choice == 3)
        {
            cout << "All translations:" << endl;
            translator.printAll(); // In toàn bộ danh sách có trong từ điển
        }
        else
        {
            cout << "Invalid choice" << endl; // Thông báo nếu nhập sai lựa chọn
        }

        cout << endl;
        printMenu();   // In lại menu cho lần thao tác tiếp theo
        cin >> choice; // Nhận lựa chọn mới
        cin.ignore();  // Tiếp tục dọn dẹp bộ nhớ đệm
    }

    return 0; // Kết thúc chương trình
}

// Định nghĩa hàm hiển thị giao diện menu
void printMenu()
{
    cout << "Select an option:" << endl;
    cout << "1 - Add or update a translation" << endl;
    cout << "2 - Look up a translation" << endl;
    cout << "3 - Print all translations" << endl;
    cout << "0 - Exit" << endl;
}

// Định nghĩa hàm xử lý việc nhập dữ liệu và thêm từ điển
void handleAdd(LanguageTranslator &translator)
{
    string englishWord;
    string translatedWord;

    cout << "Enter the English word: ";
    getline(cin, englishWord); // Dùng getline để đọc được cả khoảng trắng trong chuỗi

    cout << "Enter the translation: ";
    getline(cin, translatedWord);

    // Gọi phương thức truyền dữ liệu vào đối tượng translator
    translator.addTranslation(englishWord, translatedWord);
}

// Định nghĩa hàm xử lý việc tra cứu từ vựng
void handleLookup(const LanguageTranslator &translator)
{
    string word;
    cout << "Enter the English word to translate: ";
    getline(cin, word);

    // Gọi phương thức getTranslation và in ra kết quả tương ứng
    cout << "Translation: " << translator.getTranslation(word) << endl;
}