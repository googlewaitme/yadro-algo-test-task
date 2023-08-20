#include <iostream>
#include "mytime.h"

Time::Time() {  }


Time::Time(int getted_min) {
    hour = getted_min / 60;
    min = getted_min % 60; 
}


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
    return output << time.hour/10 << time.hour%10 << ":" << time.min/10 << time.min%10;
}

int get_time_delta(Time a, Time b) {
    return abs(a.hour*60 + a.min - b.hour*60 - b.min);
}
