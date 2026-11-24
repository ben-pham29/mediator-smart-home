#include "SmartHome.hpp"

SmartHome::SmartHome(AlarmClock* alarm, LightSensor* lightSensor, WindowBlinds* blinds, CoffeeMaker* coffeeMaker, AirConditioner* ac)
    : alarm_(alarm), lightSensor_(lightSensor), blinds_(blinds), coffeeMaker_(coffeeMaker), ac_(ac) {
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
    if (sender == alarm_ && event == Event::AlarmRang) {
        if (!isWeekend()) {
            if (lightSensor_->getBrightness() >= 50) {
                blinds_->open();
            } else {
                blinds_->close();
            }
            coffeeMaker_->brew();
            ac_->turnOff();
        } else {
            blinds_->close();
            ac_->setDegree(26);
        }
    }
}