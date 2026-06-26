#include "Drone.h" // Nạp file header Drone.h

Drone::Drone(string modelName, double batteryLife) // Định nghĩa hàm khởi tạo
{
    this->modelName = modelName; // Gán tham số vào biến thành viên của đối tượng
    this->batteryLife = batteryLife;
}

string Drone::getModelName() const // Định nghĩa hàm lấy tên model
{
    return modelName; // Trả về tên model
}

double Drone::getBatteryLife() const // Định nghĩa hàm lấy thời lượng pin
{
    return batteryLife; // Trả về pin
}