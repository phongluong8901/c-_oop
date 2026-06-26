#include <iostream>  // Nạp thư viện nhập xuất cơ bản.
#include <string>    // Nạp thư viện xử lý chuỗi.
#include <vector>    // Nạp thư viện vector (mảng động) để chứa danh sách người chơi.
#include "Player.h"  // Nạp file định nghĩa lớp cha Player.
#include "Warrior.h" // Nạp file định nghĩa lớp Warrior.
#include "Priest.h"  // Nạp file định nghĩa lớp Priest.
#include "Mage.h"    // Nạp file định nghĩa lớp Mage.
using namespace std; // Sử dụng không gian tên std.

// Khai báo trước các nguyên mẫu hàm (function prototypes) để chương trình biết các hàm này tồn tại.
void printMainMenu();
void printRaceMenu();
Race getRace(int raceNum);
Player *createPlayer(string name, int typeNum, int raceNum);
void printAll(const vector<Player *> &playerList);
void doCleanup(vector<Player *> &playerList);

// Hàm main: Điểm bắt đầu thực thi chương trình.
int main()
{
    int choice;        // Biến lưu lựa chọn lớp nhân vật (1, 2, 3 hoặc 0).
    int raceNum;       // Biến lưu lựa chọn chủng tộc (1 đến 5).
    string playerName; // Biến lưu tên nhân vật do người dùng nhập.

    // Tạo một vector chứa các con trỏ kiểu Player*. Việc dùng con trỏ cho phép mảng lưu trữ hỗn hợp Warrior, Priest và Mage.
    vector<Player *> playerList;

    printMainMenu(); // In menu chọn lớp nhân vật ra màn hình.
    cin >> choice;   // Đọc lựa chọn từ bàn phím.
    cin.get();       // Hứng ký tự xuống dòng ('\n') còn sót lại trong bộ nhớ đệm sau khi nhập số.

    // Vòng lặp while: Tiếp tục cho tạo nhân vật cho đến khi người dùng nhập 0 để kết thúc.
    while (choice != 0)
    {
        cout << "What would you like to name your character?" << endl;
        getline(cin, playerName); // Nhập tên nhân vật (có thể chứa khoảng trắng).

        printRaceMenu(); // In menu chọn chủng tộc ra màn hình.
        cin >> raceNum;  // Đọc lựa chọn chủng tộc.
        cin.get();       // Hứng ký tự xuống dòng còn sót lại sau khi nhập số chủng tộc.

        // Gọi hàm createPlayer để tạo đối tượng dưới bộ nhớ Heap và trả về địa chỉ lưu vào con trỏ tempPlayer.
        Player *tempPlayer = createPlayer(playerName, choice, raceNum);

        // Thêm địa chỉ của nhân vật vừa tạo vào mảng quản lý playerList.
        playerList.push_back(tempPlayer);

        printMainMenu(); // In lại menu chính để hỏi người dùng có muốn tạo tiếp hay dừng.
        cin >> choice;
        cin.get();
    } // end while

    printAll(playerList);  // Duyệt và in ra thông tin, câu tấn công của tất cả nhân vật đã tạo.
    doCleanup(playerList); // Dọn dẹp bộ nhớ RAM đã cấp phát, tránh rò rỉ bộ nhớ.

    cout << "Program done!" << endl;

    return 0; // Kết thúc chương trình thành công.
}

// Định nghĩa hàm in menu chọn lớp nhân vật.
void printMainMenu()
{
    cout << "\nChoose a class:\n"
         << "\t1 - Warrior\n"
         << "\t2 - Priest\n"
         << "\t3 - Mage\n"
         << "\t0 - Finish\n";
} // end printMainMenu

// Định nghĩa hàm in menu chọn chủng tộc.
void printRaceMenu()
{
    cout << "Choose a race:\n"
         << "\t1 - Human\n"
         << "\t2 - Elf\n"
         << "\t3 - Dwarf\n"
         << "\t4 - Orc\n"
         << "\t5 - Troll\n";
} // end printRaceMenu

// Định nghĩa hàm chuyển đổi số nguyên sang kiểu enum Race.
Race getRace(int raceNum)
{
    switch (raceNum)
    {
    case 1:
        return Race::HUMAN;
    case 2:
        return Race::ELF;
    case 3:
        return Race::DWARF;
    case 4:
        return Race::ORC;
    case 5:
        return Race::TROLL;
    default:
        return Race::HUMAN;
    }
} // end getRace

// Hàm Factory Method: Dựa vào lựa chọn của người dùng để khởi tạo đúng đối tượng trên vùng nhớ Heap bằng từ khóa 'new'.
Player *createPlayer(string name, int typeNum, int raceNum)
{
    Race race = getRace(raceNum); // Lấy chủng tộc dạng enum.
    switch (typeNum)
    {
    case 1:
        return new Warrior(name, race); // Tạo Chiến binh.
    case 2:
        return new Priest(name, race); // Tạo Tu sĩ.
    case 3:
        return new Mage(name, race); // Tạo Pháp sư.
    default:
        return nullptr;
    }
}

// Hàm duyệt mảng để in thông tin: Sử dụng con trỏ đa hình để tự động gọi đúng hàm attack() của từng nhân vật (tính đa hình).
void printAll(const vector<Player *> &playerList)
{
    for (const Player *player : playerList)
    {
        cout << "My name is " << player->getName()
             << ". I'm a " << player->whatRace()
             << " and my attack is: " << player->attack() << endl;
    }
}

// Hàm dọn dẹp bộ nhớ: Hủy các đối tượng đã tạo bằng 'new' trên Heap thông qua 'delete', sau đó xóa sạch vector.
void doCleanup(vector<Player *> &playerList)
{
    for (Player *player : playerList)
    {
        delete player;
    }
    playerList.clear();
}

//
// playerList.push_back(tempPlayer); trong chương trình của bạn:

// 1. Dòng lệnh này làm gì?
// playerList: Đây là một mảng động (vector) chứa các con trỏ kiểu Player* (được khai báo ở main).

// .push_back(...): Đây là một phương thức có sẵn của vector, dùng để thêm một phần tử vào cuối của mảng.

// tempPlayer: Đây là một con trỏ (lưu địa chỉ) trỏ đến một đối tượng nhân vật (Warrior, Priest, hoặc Mage) vừa được tạo ra trên vùng nhớ Heap.