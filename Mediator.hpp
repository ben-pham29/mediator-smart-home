#pragma once

// Các sự kiện mà thiết bị có thể gửi cho bộ điều phối.
enum class Event {
    AlarmRang
};

class Device;

// Mediator Interface tiếp nhận sự kiện cùng thiết bị phát sự kiện.
class Mediator {
public:
    virtual ~Mediator() = default;
    virtual void notify(Device* sender, Event event) = 0;
};

// Base Colleague dùng chung cho các thiết bị trong hệ thống.
class Device {
protected:
    // Con trỏ không sở hữu, có thể là nullptr khi thiết bị chưa được gắn.
    // Bộ điều phối phải còn tồn tại khi thiết bị gửi sự kiện qua con trỏ này.
    Mediator* mediator_;

public:
    explicit Device(Mediator* mediator = nullptr) : mediator_(mediator) {}
    virtual ~Device() = default;

    void setMediator(Mediator* mediator) {
        mediator_ = mediator;
    }
};