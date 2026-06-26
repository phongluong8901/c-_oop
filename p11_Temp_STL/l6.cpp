#include <iostream>  // Thư viện hỗ trợ nhập xuất cơ bản (std::cout, std::endl)
#include <cstdlib>   // Thư viện hỗ trợ các hàm tạo số ngẫu nhiên (rand, srand)
#include <ctime>     // Thư viện hỗ trợ lấy thời gian thực (time)
#include <vector>    // Thư viện hỗ trợ sử dụng cấu trúc dữ liệu vector (mảng động)
#include <algorithm> // Thư viện hỗ trợ các thuật toán như count, replace, sort

using namespace std;

// Khai báo nguyên mẫu hàm (function prototypes) để trình biên dịch nhận diện các hàm trước khi gọi trong main
void fillVector(vector<int> &myVector);
void printVector(const vector<int> &myVector);
void countFives(const vector<int> &myVector);

int main()
{

    // Khởi tạo một vector rỗng chứa các số nguyên có tên là myVector
    vector<int> myVector;

    // Gọi hàm fillVector để điền 20 số ngẫu nhiên vào vector
    fillVector(myVector);

    // Gọi hàm printVector để in các phần tử trong vector ra màn hình
    printVector(myVector);

    // Gọi hàm countFives để đếm và in ra số lượng số 5 có trong vector
    countFives(myVector);

    // In ra tiêu đề thông báo chuẩn bị thay thế số 5 thành số 99
    cout << "\nReplacing 5s with 99s" << endl;

    // Sử dụng thuật toán replace, duyệt từ phần tử đầu (begin) đến phần tử cuối (end), tìm giá trị 5 đổi thành 99
    replace(myVector.begin(), myVector.end(), 5, 99);

    // Gọi lại hàm countFives để đếm số lượng số 5 sau khi đã thay thế (lúc này sẽ là 0)
    countFives(myVector);

    // In lại vector để thấy các số 5 đã được cập nhật thành 99
    printVector(myVector);

    // In ra tiêu đề thông báo chuẩn bị sắp xếp vector
    cout << "\nNow sorting vector..." << endl;

    // Sử dụng thuật toán sort để sắp xếp các phần tử từ begin đến end theo thứ tự tăng dần
    sort(myVector.begin(), myVector.end());

    // In ra vector sau khi đã được sắp xếp hoàn tất
    printVector(myVector);

    // Trả về 0 để kết thúc chương trình thành công
    return 0;
}

// Định nghĩa hàm điền các số ngẫu nhiên vào vector
void fillVector(vector<int> &myVector)
{
    // Thiết lập hạt giống ngẫu nhiên dựa trên thời gian hiện tại để các lần chạy cho ra số khác nhau
    srand(time(nullptr));

    // Vòng lặp thực hiện 20 lần để thêm 20 phần tử vào cuối vector
    for (int i = 0; i < 20; ++i)
    {
        // rand() % 5 tạo ra số dư từ 0 đến 4, cộng thêm 1 để miền giá trị là từ 1 đến 5
        myVector.push_back(rand() % 5 + 1); // 1 to 5
    }
}

// Định nghĩa hàm duyệt và in từng phần tử trong vector
void printVector(const vector<int> &myVector)
{
    // Sử dụng vòng lặp for nâng cao để lấy ra từng số nguyên (value) trong vector
    for (int value : myVector)
    {
        // In giá trị kèm theo một khoảng trắng để phân cách
        cout << value << " ";
    }
    // In ký tự xuống dòng sau khi xuất xong toàn bộ vector
    cout << endl;
}

// Định nghĩa hàm đếm và in số lần xuất hiện của số 5
void countFives(const vector<int> &myVector)
{
    // Sử dụng hàm count quét vùng nhớ từ begin đến end, đếm số phần tử có giá trị bằng 5
    int countOfFives = count(myVector.begin(), myVector.end(), 5);

    // In kết quả số lượng đếm được ra màn hình
    cout << "Number of 5s: " << countOfFives << endl;
}

//
// Dòng code srand(time(nullptr)); dùng để thiết lập một "hạt giống" (seed) ngẫu nhiên cho bộ tạo số ngẫu nhiên trong C++, đảm bảo rằng mỗi lần bạn chạy chương trình, các con số sinh ra sẽ khác nhau.

// Giải thích chi tiết từng thành phần
// time(nullptr): * Hàm này lấy ra thời gian hiện tại của hệ thống (tính bằng số giây tính từ ngày 1 tháng 1 năm 1970 đến nay).

// Vì thời gian luôn trôi đi liên tục, nên mỗi giây trôi qua con số này sẽ khác nhau.

// srand(...) (viết tắt của Standard Random Seed): * Hàm này nhận con số thời gian ở trên làm "hạt giống" để nạp vào thuật toán sinh số ngẫu nhiên.