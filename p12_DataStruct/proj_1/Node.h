#ifndef NODE_H // Kiểm tra xem macro NODE_H đã được định nghĩa hay chưa để tránh khai báo lại thư viện
#define NODE_H // Định nghĩa macro NODE_H

class Node // Khai báo lớp Node đại diện cho một phần tử trong danh sách liên kết
{
public: // Các phương thức công khai có thể truy cập từ bên ngoài lớp
    // Hàm khởi tạo (constructor) nhận vào dữ liệu và con trỏ trỏ tới node tiếp theo
    Node(int data, Node *next) : data(data), next(next)
    {
    }

    // Phương thức gán dữ liệu mới cho node
    void setData(int data)
    {
        this->data = data; // Sử dụng con trỏ 'this' để trỏ tới thuộc tính của đối tượng hiện tại
    }

    // Phương thức trỏ con trỏ 'next' tới một node khác
    void setNext(Node *next)
    {
        this->next = next;
    }

    // Phương thức trả về dữ liệu của node (khai báo const để đảm bảo không làm thay đổi dữ liệu)
    int getData() const
    {
        return data;
    }

    // Phương thức trả về con trỏ trỏ tới node tiếp theo (khai báo const)
    Node *getNext() const
    {
        return next;
    }

private:        // Các thuộc tính riêng tư, chỉ có thể truy cập bên trong lớp
    int data;   // Biến lưu trữ giá trị số nguyên của node
    Node *next; // Con trỏ lưu địa chỉ của node tiếp theo trong chuỗi
};

#endif // Kết thúc khối điều kiện của tiền xử lý #ifndef

//---
// Phần data(data), next(next) phía sau dùng để gán giá trị trực tiếp cho các thuộc tính data và next của đối tượng. Cụ thể từng phần như sau:

// data(data): Gán giá trị của tham số đầu vào data cho thuộc tính data của class.

// ,: Dấu phẩy dùng để phân tách giữa các thuộc tính cần khởi tạo.

// next(next): Gán giá trị của tham số đầu vào next cho thuộc tính con trỏ next của class.

//---
// 1. Trường hợp dùng con trỏ: void setNext(Node *next)
// Ý nghĩa: Hàm này nhận vào địa chỉ của một đối tượng Node.

// Đặc điểm:

// Vì nó nhận địa chỉ, bạn có thể truyền vào giá trị nullptr (tương đương với việc trỏ vào khoảng trống, không có node nào đứng sau nữa). Điều này cực kỳ quan trọng đối với node cuối cùng trong danh sách liên kết.

// Bạn có thể thay đổi địa chỉ mà con trỏ next đang trỏ tới bất cứ lúc nào (cho nó trỏ sang một node khác).

// 2. Trường hợp dùng tham chiếu: void setNext(Node &next)
// Ý nghĩa: Hàm này nhận vào bí danh (đại diện trực tiếp) của một đối tượng Node đã tồn tại trong bộ nhớ.

// Đặc điểm:

// Tham chiếu bắt buộc phải gắn liền với một đối tượng thực tế. Bạn không thể truyền nullptr vào đây. Nếu dùng cách này, bạn sẽ gặp khó khăn lớn khi muốn đánh dấu điểm kết thúc của danh sách liên kết (kết thúc chuỗi).

// Khi bạn thao tác với next bên trong hàm, bạn đang thao tác trực tiếp lên đối tượng gốc.