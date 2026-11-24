#pragma once

enum class Event {
    AlarmRang
};

class Device;

class Mediator {
public:
    virtual ~Mediator() = default;
    virtual void notify(Device* sender, Event event) = 0;
};

class Device {
protected:
    Mediator* mediator_;

public:
    explicit Device(Mediator* mediator = nullptr) : mediator_(mediator) {}
    virtual ~Device() = default;

    void setMediator(Mediator* mediator) {
        mediator_ = mediator;
    }
};