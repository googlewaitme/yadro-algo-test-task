#include <string>
#include "time.cpp"


struct Event {
    int type, table_number;
    std::string client_name;
    Time time;

    friend std::istream& operator>>(std::istream& inp, Event& obj) {
        inp >> obj.time >> obj.type >> obj.client_name;
        if (obj.type == 2) {
            inp >> obj.table_number;
        }
        return inp;
    }

    friend std::ostream& operator<<(std::ostream& os, Event& obj) {
        os << obj.time << " " << obj.type << " " << obj.client_name;
        if (obj.type == 2) {
            os << " " << obj.table_number;
        }
        return os;
    }
};
