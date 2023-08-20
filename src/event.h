#pragma once
#include <string>
#include "mytime.h"


struct Event {
    int type, table_number;
    std::string client_name;
    Time time;

    friend std::istream& operator>>(std::istream& is, Event& obj);
    friend std::ostream& operator<<(std::ostream& os, Event& obj);
};
