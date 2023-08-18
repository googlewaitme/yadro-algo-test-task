#pragma once
#include <iostream>

struct Time {
    int hour, min;

    friend std::istream& operator>>(std::istream &input, Time &time) {
        input >> time.hour;
        input.ignore();
        input >> time.min;
        return input;
    }

    friend std::ostream& operator<<(std::ostream &output, Time& time) {
        return output << time.hour << ":" << time.min;
    }
};


