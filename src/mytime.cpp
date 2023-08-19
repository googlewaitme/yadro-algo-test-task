#pragma once
#include <iostream>
#include "mytime.h"


bool operator<(Time left, Time right) {
    if (left.hour == right.hour)
        return left.min < right.min;
    return left.hour < right.hour;
}

bool operator>(Time left, Time right) { return right < left; }
bool operator>=(Time left, Time right) { return !(left < right); }
bool operator<=(Time left, Time right) { return !(right < left); }

std::istream& operator>>(std::istream& input, Time& time) {
    input >> time.hour;
    input.ignore();
    input >> time.min;
    return input;
}

std::ostream& operator<<(std::ostream& output, Time& time) {
    return output << time.hour << ":" << time.min;
}


