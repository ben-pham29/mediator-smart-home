#include "SmartHome.hpp"

SmartHome::SmartHome(AlarmClock* alarm, LightSensor* lightSensor, WindowBlinds* blinds, CoffeeMaker* coffeeMaker, AirConditioner* ac)
    : alarm_(alarm), lightSensor_(lightSensor), blinds_(blinds), coffeeMaker_(coffeeMaker), ac_(ac) {
    // Gắn cùng một bộ điều phối cho cả năm thiết bị.
    alarm_->setMediator(this);
    lightSensor_->setMediator(this);
    blinds_->setMediator(this);
    coffeeMaker_->setMediator(this);
    ac_->setMediator(this);
}

void SmartHome::setDay(DayOfWeek day) {
    currentDay_ = day;
}

bool SmartHome::isWeekend() const {
    return currentDay_ == DayOfWeek::Saturday || currentDay_ == DayOfWeek::Sunday;
}

void SmartHome::notify(Device* sender, Event event) {
    // Chỉ chạy quy trình buổi sáng khi đồng hồ đã đăng ký phát AlarmRang.
    if (sender == alarm_ && event == Event::AlarmRang) {
        if (!isWeekend()) {
            // Ngày thường dùng ngưỡng 50 để chọn trạng thái rèm, sau đó pha cà phê và tắt điều hòa.
            if (lightSensor_->getBrightness() >= 50) {
                blinds_->open();
            } else {
                blinds_->close();
            }
            coffeeMaker_->brew();
            ac_->turnOff();
        } else {
            // Cuối tuần luôn đóng rèm và đặt điều hòa ở 26°C, bỏ qua bước pha cà phê.
            blinds_->close();
            ac_->setDegree(26);
        }
    }
}