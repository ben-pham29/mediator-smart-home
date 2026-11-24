#pragma once

#include <iostream>
#include "Mediator.hpp"

// Concrete Colleague phát sự kiện AlarmRang qua giao diện Mediator sau khi reo.
class AlarmClock : public Device {
public:
    void ring() {
        std::cout << "[AlarmClock] Reng reng reng! Bao thuc keu.\n";
        if (mediator_) {
            mediator_->notify(this, Event::AlarmRang);
        }
    }
};

// Concrete Colleague lưu giá trị độ sáng mô phỏng để SmartHome đọc khi cần.
class LightSensor : public Device {
private:
    int brightness = 0;

public:
    void setBrightness(int level) {
        brightness = level;
    }

    int getBrightness() const {
        return brightness;
    }
};

// Concrete Colleague mô phỏng thao tác mở và đóng rèm bằng thông báo trên console.
class WindowBlinds : public Device {
public:
    void open() {
        std::cout << "[WindowBlinds] Da mo rem cua.\n";
    }

    void close() {
        std::cout << "[WindowBlinds] Da dong rem cua.\n";
    }
};

// Concrete Colleague mô phỏng việc bắt đầu pha cà phê khi được gọi brew().
class CoffeeMaker : public Device {
public:
    void brew() {
        std::cout << "[CoffeeMaker] Bat dau pha coffee.\n";
    }
};

// Concrete Colleague lưu nhiệt độ cài đặt và in thông báo khi chỉnh nhiệt độ hoặc tắt.
class AirConditioner : public Device {
private:
    int degree = 0;

public:
    void setDegree(int degree) {
        this->degree = degree;
        std::cout << "[AirConditioner] Da chinh nhiet do len " << degree << "C.\n";
    }

    void turnOff() {
        std::cout << "[AirConditioner] Da tat dieu hoa.\n";
    }
};