#include <iostream>  // Nạp thư viện nhập/xuất chuẩn
#include "Drone.h"   // Nạp file header lớp Drone
using namespace std; // Sử dụng không gian tên chuẩn

void printFleet(Drone **fleet, int size); // Khai báo nguyên mẫu hàm in danh sách đội bay (nhận con trỏ cấp 2)

int main() // Hàm chính của chương trình
{
    int numDrones = 0;    // Khởi tạo biến lưu số lượng drone
    string model = "";    // Khởi tạo chuỗi tên model rỗng
    double battery = 0.0; // Khởi tạo pin bằng 0.0

    cout << "How many drones are in your fleet?  "; // Hỏi người dùng nhập số lượng
    cin >> numDrones;                               // Nhận số lượng drone

    // Cấp phát mảng con trỏ động trên Heap: tạo một mảng gồm các con trỏ kiểu (Drone*)
    Drone **droneFleet = new Drone *[numDrones];

    for (int i = 0; i < numDrones; i++) // Vòng lặp cho phép nhập thông tin từng drone
    {
        cout << "Enter model name for drone " << (i + 1) << ": ";
        cin.get();           // Đọc ký tự enter còn thừa trong bộ đệm
        getline(cin, model); // Nhận toàn bộ chuỗi tên model (bao gồm cả khoảng trắng)

        cout << "Enter battery life (as a percentage) for " << model << ":  ";
        cin >> battery; // Nhận % pin

        // Khởi tạo đối tượng Drone trên Heap và gán địa chỉ của nó vào ô con trỏ thứ i trong mảng
        droneFleet[i] = new Drone(model, battery);
    } // end of the for loop

    cout << "\nDrone Fleet Summary:" << endl; // Tiêu đề danh sách
    printFleet(droneFleet, numDrones);        // Gọi hàm in mảng đối tượng

    // Dọn dẹp bộ nhớ: Vòng lặp hủy từng đối tượng Drone được tạo bằng từ khóa new
    for (int i = 0; i < numDrones; i++)
    {
        delete droneFleet[i];    // Hủy đối tượng tại địa chỉ thứ i trên Heap
        droneFleet[i] = nullptr; // Trỏ con trỏ về null tránh trỏ lung tung
    }

    // Giải phóng mảng con trỏ chính đã cấp phát bằng từ khóa new[]
    delete[] droneFleet;
    droneFleet = nullptr; // Gán mảng con trỏ về null

    return 0; // Báo cáo chương trình kết thúc thành công
}

// Định nghĩa hàm in thông tin đội bay, sử dụng con trỏ cấp 2 (Drone **fleet) tương đương mảng con trỏ
void printFleet(Drone **fleet, int size)
{
    for (int i = 0; i < size; i++) // Duyệt qua từng phần tử của mảng
    {
        // Dùng toán tử -> để truy xuất hàm thành viên thông qua mảng con trỏ
        cout << "Drone " << (i + 1) << ": " << fleet[i]->getModelName()
             << " | Battery: " << fleet[i]->getBatteryLife() << "%" << endl;
    }
}

// Thực ra, bạn vẫn đang dùng Drone* (một dấu sao) khi khai báo mảng, nhưng bắt buộc phải dùng tới  (hai dấu sao) ở tên biến để chương trình hiểu đó là một mảng các con trỏ.

// Để hiểu rõ sự khác biệt, hãy cùng phân tích 3 cách viết dưới đây:

// 1. Nếu bạn viết: Drone fleet; (Không dấu sao)
// Đây là khởi tạo một đối tượng đơn lẻ tĩnh. Bạn không làm cách nào để thay đổi kích thước của nó theo ý người dùng lúc chạy chương trình được.

// 2. Nếu bạn viết: Drone *droneFleet; (Một dấu sao)
// Đây chỉ là một con trỏ đơn lẻ trỏ đến một chiếc Drone duy nhất (hoặc trỏ đến phần tử đầu tiên của mảng liền kề).

// Nó không đủ cấu trúc để quản lý một danh sách gồm nhiều con trỏ nằm rải rác, nơi mà mỗi con trỏ lại dẫn tới một chiếc Drone được tạo bằng lệnh new ở các thời điểm khác nhau.

// 3. Tại sao phải dùng: Drone droneFleet = new Drone *[numDrones]; (Hai dấu sao)
// Bởi vì bạn đang tạo ra một mảng chứa các con trỏ, và bản thân mảng đó lại được cấp phát động.

// Vế phải new Drone *[numDrones] tạo ra một loạt các ô nhớ chứa địa chỉ (giống như việc bạn xếp sẵn các biển địa chỉ nhà).

// droneFleet ở vế trái phải là con trỏ cấp 2 (Drone) thì mới nắm giữ và quản lý được địa chỉ của cái mảng gồm toàn các con trỏ (Drone*) đó.

// Nói một cách ngắn gọn:

// Drone* ptr quản lý một đối tượng Drone.

// Drone arrayPtr quản lý một mảng chứa nhiều con trỏ Drone*. Vì số lượng drone (numDrones) do người dùng nhập vào thay đổi liên tục, nên ta cần mảng con trỏ cấp 2 này để linh hoạt tạo và xóa từng chiếc drone một cách an toàn.