#pragma once
#include "Mediator.hpp"
#include "Devices.hpp"

// Ngày trong tuần dùng làm ngữ cảnh xử lý báo thức.
enum class DayOfWeek {
    Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};

// Concrete Mediator tập trung quy tắc phối hợp giữa năm thiết bị.
class SmartHome : public Mediator {
private:
    AlarmClock* alarm_;
    LightSensor* lightSensor_;
    WindowBlinds* blinds_;
    CoffeeMaker* coffeeMaker_;
    AirConditioner* ac_;
    DayOfWeek currentDay_ = DayOfWeek::Monday;
    bool isWeekend() const;

public:
    // Cả năm con trỏ phải trỏ tới các thiết bị còn sống trong suốt vòng đời SmartHome.
    // SmartHome mượn các thiết bị và thiết lập liên kết để chúng gửi sự kiện về nó.
    SmartHome(AlarmClock* alarm, LightSensor* lightSensor, WindowBlinds* blinds, CoffeeMaker* coffeeMaker, AirConditioner* ac);
    void setDay(DayOfWeek day);
    void notify(Device* sender, Event event) override;
};