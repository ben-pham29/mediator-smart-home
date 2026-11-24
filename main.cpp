#include <iostream>
#include "SmartHome.hpp"

// Điểm chạy demo cấu hình dữ liệu cho từng kịch bản rồi phát sự kiện báo thức.
int main() {
    AlarmClock alarm;
    LightSensor lightSensor;
    WindowBlinds blinds;
    CoffeeMaker coffeeMaker;
    AirConditioner ac;

    // Khởi tạo SmartHome sau các thiết bị để chúng tồn tại suốt vòng đời bộ điều phối.
    SmartHome home(&alarm, &lightSensor, &blinds, &coffeeMaker, &ac);

    // Ngày thường đủ sáng sẽ mở rèm, pha cà phê và tắt điều hòa.
    std::cout << "--- Kich ban 1: Sang Thu Hai (Troi nang, do sang 80) ---\n";
    home.setDay(DayOfWeek::Monday);
    lightSensor.setBrightness(80);
    alarm.ring();

    // Ngày thường thiếu sáng sẽ đóng rèm, pha cà phê và tắt điều hòa.
    std::cout << "\n--- Kich ban 2: Sang Thu Tu (Troi am u, do sang 30) ---\n";
    home.setDay(DayOfWeek::Wednesday);
    lightSensor.setBrightness(30);
    alarm.ring();

    // Cuối tuần dù độ sáng cao vẫn đóng rèm, bỏ qua pha cà phê và đặt điều hòa 26°C.
    std::cout << "\n--- Kich ban 3: Sang Chu Nhat (Cuoi tuan, do sang 90) ---\n";
    home.setDay(DayOfWeek::Sunday);
    lightSensor.setBrightness(90);
    alarm.ring();

    return 0;
}