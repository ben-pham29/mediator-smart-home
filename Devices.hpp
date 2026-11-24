#pragma once

#include <iostream>
#include "Mediator.hpp"

class AlarmClock : public Device {
public:
    void ring() {
        std::cout << "[AlarmClock] Reng reng reng! Bao thuc keu.\n";
        if (mediator_) {
            mediator_->notify(this, Event::AlarmRang);
        }
    }
};

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

class WindowBlinds : public Device {
public:
    void open() {
        std::cout << "[WindowBlinds] Da mo rem cua.\n";
    }

    void close() {
        std::cout << "[WindowBlinds] Da dong rem cua.\n";
    }
};

class CoffeeMaker : public Device {
public:
    void brew() {
        std::cout << "[CoffeeMaker] Bat dau pha coffee.\n";
    }
};

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