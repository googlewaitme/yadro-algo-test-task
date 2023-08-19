#pragma once
#include <iostream>

struct Time {
    int hour, min;

    friend bool operator<(Time left, Time right);
    friend bool operator>(Time left, Time right);
    friend bool operator>=(Time left, Time right);
    friend bool operator<=(Time left, Time right);

    friend std::istream& operator>>(std::istream& input, Time& time);
    friend std::ostream& operator<<(std::ostream& output, Time& time);
};


