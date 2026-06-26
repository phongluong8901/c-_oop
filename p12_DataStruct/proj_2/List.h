#ifndef LIST_H // Kiểm tra để ngăn việc định nghĩa lại tệp tiêu đề
#define LIST_H

// Lớp giao diện thuần túy trừu tượng (Interface) định nghĩa các quy tắc cho danh sách
class List
{
public:
    // Các hàm thuần túy ảo (pure virtual functions) bắt buộc lớp con phải triển khai
    virtual void add(int newEntry) = 0;
    virtual void add(int newEntry, int position) = 0;
    virtual void set(int newEntry, int position) = 0;

    virtual bool contains(int entry) const = 0;
    virtual int find(int entry) const = 0;
    virtual int remove(int position) = 0;
    virtual void makeEmpty() = 0;

    virtual int size() const = 0;
    virtual bool isEmpty() const = 0;
    virtual void printList() const = 0;
};

#endif