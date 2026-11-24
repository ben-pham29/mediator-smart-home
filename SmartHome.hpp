#pragma once
#include "Mediator.hpp"
#include "Devices.hpp"

enum class DayOfWeek {
    Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};

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
    SmartHome(AlarmClock* alarm, LightSensor* lightSensor, WindowBlinds* blinds, CoffeeMaker* coffeeMaker, AirConditioner* ac);
    void setDay(DayOfWeek day);
    void notify(Device* sender, Event event) override;
};