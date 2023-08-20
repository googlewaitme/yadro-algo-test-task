#include <string>
#include "mytime.h"
#include "event.h"


Event::Event(Time _time, int _type, std::string _client_name) {
    type = _type;
    client_name = _client_name;
    time = _time;
} 

Event::Event(Time _time, int _type, std::string _client_name, int _table_number) 
    : Event(_time, _type, _client_name)
{
    table_number = _table_number;
}


std::istream& operator>>(std::istream& is, Event& obj) {
    is >> obj.time >> obj.type >> obj.client_name;
    if (obj.type == 2) {
        is >> obj.table_number;
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, Event& obj) {
    os << obj.time << " " << obj.type << " " << obj.client_name;
    if (obj.type == 2) {
        os << " " << obj.table_number;
    }
    return os;
}
