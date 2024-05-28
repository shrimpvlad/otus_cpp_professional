#pragma once
class Observer {
public:
    virtual ~Observer() = default;

    virtual void update() = 0;
};

class Observable {
public:
    virtual ~Observable() = default;

    virtual void subscribe(Observer* obs) = 0;
};