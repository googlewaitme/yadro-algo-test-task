#include <string>
#include "mytime.h"


struct Event {
    int type, table_number;
    std::string client_name;
    Time time;

    friend std::istream& operator>>(std::istream& is, Event& obj) {
        is >> obj.time >> obj.type >> obj.client_name;
        if (obj.type == 2) {
            is >> obj.table_number;
        }
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, Event& obj) {
        os << obj.time << " " << obj.type << " " << obj.client_name;
        if (obj.type == 2) {
            os << " " << obj.table_number;
        }
        return os;
    }
};
