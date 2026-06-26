#include <iostream> // Thư viện chuẩn để sử dụng các thao tác nhập/xuất (cin, cout)
#include "Node.h"   // Nhập tệp tiêu đề định nghĩa lớp Node vào dự án

using namespace std; // Sử dụng không gian tên chuẩn std để không cần viết std:: trước cout, endl,...

// Khai báo nguyên mẫu các hàm (function prototypes) trước khi sử dụng trong hàm main
Node *createChain();               // Hàm tạo danh sách liên kết và trả về con trỏ trỏ đến node đầu tiên (head)
void printChain(Node *const head); // Hàm in danh sách (head là hằng con trỏ, không cho phép thay đổi địa chỉ head)
void deleteChain(Node *&head);     // Hàm xóa danh sách (head được truyền tham chiếu để có thể gán lại thành nullptr sau khi xóa)

int main() // Hàm main, điểm bắt đầu thực thi của toàn bộ chương trình
{
    // Gọi hàm createChain để khởi tạo chuỗi các node và gán địa chỉ node đầu tiên cho theHead
    Node *theHead = createChain();

    printChain(theHead);  // Gọi hàm duyệt và in ra màn hình các giá trị trong chuỗi node
    deleteChain(theHead); // Gọi hàm giải phóng toàn bộ bộ nhớ đã cấp phát cho chuỗi node
}

// Định nghĩa hàm createChain: Tạo danh sách liên kết gồm 25 phần tử
Node *createChain()
{
    Node *head = nullptr; // Khởi tạo con trỏ head ban đầu trỏ tới nullptr (danh sách rỗng)

    for (int i = 0; i < 25; i++) // Vòng lặp chạy 25 lần (từ 0 đến 24)
    {
        // Tạo một node mới chứa dữ liệu i, và node mới này trỏ tới node mà head đang trỏ.
        // Sau đó cập nhật head trỏ đến node mới vừa tạo (thêm vào đầu danh sách).
        head = new Node(i, head);
    }

    return head; // Trả về địa chỉ của node đầu tiên của danh sách
}

// Định nghĩa hàm printChain: Duyệt qua từng node từ đầu đến cuối để in dữ liệu
void printChain(Node *const head)
{
    Node *walker = head; // Khởi tạo con trỏ walker (con trỏ đi bộ) bắt đầu từ head để duyệt danh sách
    int count = 0;       // Khởi tạo biến đếm số lượng phần tử

    while (walker != nullptr) // Vòng lặp chạy đến khi walker trỏ tới nullptr (hết danh sách)
    {
        cout << walker->getData() << endl; // In ra dữ liệu của node hiện tại
        walker = walker->getNext();        // Chuyển walker sang node tiếp theo
        count++;                           // Tăng biến đếm lên 1
    }

    cout << "Number of elements: " << count << endl; // In ra tổng số phần tử đếm được
}

// Định nghĩa hàm deleteChain: Hủy toàn bộ danh sách liên kết để tránh rò rỉ bộ nhớ (memory leak)
void deleteChain(Node *&head)
{
    Node *nodeToDelete; // Khai báo con trỏ tạm để lưu địa chỉ node cần xóa

    while (head != nullptr) // Lặp cho đến khi danh sách trống rỗng
    {
        nodeToDelete = head;    // Lưu lại địa chỉ node hiện tại chuẩn bị xóa
        head = head->getNext(); // Cho head dịch chuyển sang node tiếp theo
        delete nodeToDelete;    // Giải phóng bộ nhớ của node được lưu trong nodeToDelete
    }
}

//
// Phân tích dòng code: Node *theHead = createChain();
// createChain(): Hàm này chạy và trả về địa chỉ của node đầu tiên trong danh sách (kiểu Node*).

// Node *theHead: Khai báo một biến con trỏ tên là theHead có khả năng lưu địa chỉ.

// Kết quả: Phép gán này có nghĩa là lưu địa chỉ mà hàm trả về vào trong biến theHead.

// Sự khác biệt giữa theHead và *theHead
// Để nhớ lâu, bạn hãy quy ước:

// Bản thân cái tên theHead (đứng một mình): Đại diện cho địa chỉ (nơi cất giữ dữ liệu).

// Khi thêm dấu sao *theHead (toán tử giải tham chiếu - dereference): Có nghĩa là "lấy giá trị nằm tại cái địa chỉ đó".

//---
// 1. Cách bạn đang viết: Node *const head (Hằng con trỏ)
// Từ khóa const nằm sau dấu sao *.

// Ý nghĩa: Bản thân địa chỉ của con trỏ là hằng số và không thể thay đổi.

// Được phép: Bạn có thể dùng head->setData(10) để sửa đổi dữ liệu bên trong node.

// Bị cấm: Bạn không thể gán head = anotherNode; (không cho phép đổi địa chỉ trỏ tới).

// Ứng dụng: Dùng trong hàm in danh sách (printChain) như code của bạn, để đảm bảo không làm mất dấu vết của node đầu tiên.

// 2. Cách bạn đang tưởng tượng: const Node *head (Con trỏ trỏ tới hằng)
// Từ khóa const nằm trước kiểu dữ liệu Node (hoặc viết là Node const *head).

// Ý nghĩa: Đối tượng mà con trỏ đang trỏ tới là hằng số, không thể bị sửa đổi.

// Được phép: Bạn có thể cho head trỏ sang một node khác (head = anotherNode;).

// Bị cấm: Bạn không thể dùng head->setData(10) để sửa dữ liệu, trình biên dịch sẽ báo lỗi vì dữ liệu lúc này chỉ được phép đọc (read-only).

// Ứng dụng: Dùng khi bạn muốn duyệt qua một danh sách và cam kết với chương trình rằng hàm của bạn tuyệt đối không làm thay đổi nội dung của các node đó.

//---
// Đoạn mã void printChain(Node *const head) là khai báo một hàm dùng để duyệt và in ra màn hình danh sách các node. Điểm đặc biệt và cốt lõi ở đây chính là từ khóa const nằm ở giữa.

// Để hiểu rõ ý nghĩa của nó, chúng ta cùng phân tích chi tiết cấu trúc này:

// void: Hàm này chỉ thực hiện công việc (duyệt và in) mà không trả về bất kỳ giá trị nào.

// printChain: Tên của hàm.

// Node *: Đây là một con trỏ trỏ tới đối tượng Node, cụ thể là nhận địa chỉ của node đầu tiên (head) trong danh sách.

// const: Đứng ở vị trí này, nó biến con trỏ head thành một hằng con trỏ (constant pointer).

// Ý nghĩa của hằng con trỏ Node *const head
// Khi bạn khai báo Node *const head, điều này có nghĩa là:

// Cho phép: Bạn được phép đọc dữ liệu của node, hoặc đi tới các node tiếp theo thông qua con trỏ này (ví dụ: dùng head->getData()).

// Cấm tuyệt đối: Bạn không được phép thay đổi địa chỉ mà head đang trỏ tới. Tức là bên trong thân hàm printChain, bạn không thể viết các lệnh như head = someOtherNode;.

//---
// Đoạn mã void deleteChain(Node *&head) là khai báo hàm dùng để giải phóng toàn bộ danh sách liên kết. Điểm mấu chốt nằm ở ký hiệu & đặt cạnh dấu sao *. Để hiểu rõ, chúng ta cùng phân tích chi tiết:

// void: Hàm thực hiện công việc dọn dẹp bộ nhớ và không trả về giá trị.

// deleteChain: Tên của hàm.

// Node *: Đây là con trỏ nhận địa chỉ của node đầu tiên (head) trong danh sách.

// & (Tham chiếu - Reference): Ký hiệu này nằm giữa dấu sao và tên biến, biến head thành một tham chiếu tới con trỏ.

// Ý nghĩa của tham chiếu con trỏ Node *&head
// Khi bạn truyền con trỏ bằng tham chiếu, điều này có nghĩa là:

// Thao tác trực tiếp trên biến gốc: Thay vì tạo một bản sao của con trỏ head khi truyền vào hàm, chương trình đang sử dụng trực tiếp con trỏ theHead nằm ở hàm main.

// Cho phép gán lại địa chỉ: Bên trong hàm deleteChain, sau khi xóa hết các node, dòng lệnh cuối cùng thường sẽ gán head = nullptr (như trong thuật toán của bạn). Nhờ có dấu &, giá trị nullptr này sẽ được cập nhật trực tiếp cho con trỏ theHead ở main.

// Tại sao không dùng Node *head (truyền giá trị thông thường)?
// Nếu bạn bỏ dấu & và chỉ viết void deleteChain(Node *head):

// Hàm vẫn xóa được các node trong danh sách.

// Tuy nhiên, con trỏ theHead ở hàm main sau khi gọi hàm xong sẽ vẫn trỏ vào vùng nhớ cũ vừa bị xóa. Tình trạng này gọi là con trỏ lơ lửng (dangling pointer), rất nguy hiểm vì nếu vô tình truy cập vào, chương trình có thể bị lỗi hoặc treo máy.

// Việc dùng Node *&head giúp hàm dọn dẹp sạch sẽ cả cấu trúc danh sách và đưa con trỏ quản lý về trạng thái an toàn (nullptr).