#include <iostream>
#include "SmartHome.hpp"

int main() {
    AlarmClock alarm;
    LightSensor lightSensor;
    WindowBlinds blinds;
    CoffeeMaker coffeeMaker;
    AirConditioner ac;

    SmartHome home(&alarm, &lightSensor, &blinds, &coffeeMaker, &ac);

    std::cout << "--- Kich ban 1: Sang Thu Hai (Troi nang, do sang 80) ---\n";
    home.setDay(DayOfWeek::Monday);
    lightSensor.setBrightness(80);
    alarm.ring();

    std::cout << "\n--- Kich ban 2: Sang Thu Tu (Troi am u, do sang 30) ---\n";
    home.setDay(DayOfWeek::Wednesday);
    lightSensor.setBrightness(30);
    alarm.ring();

    std::cout << "\n--- Kich ban 3: Sang Chu Nhat (Cuoi tuan, do sang 90) ---\n";
    home.setDay(DayOfWeek::Sunday);
    lightSensor.setBrightness(90);
    alarm.ring();

    return 0;
}