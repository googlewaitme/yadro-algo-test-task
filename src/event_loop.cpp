#include <fstream>
#include <iostream>
#include "event.cpp"
// TODO delete iostream 

class EventLoop {
private:
    std::fstream m_inp;
    Event m_event;
public:
    EventLoop(std::string filename) : m_inp(filename) {
        // TODO
    }

    Event get_next() {
        m_inp >> m_event.time >> m_event.type;
        std::cout << "hello: "<< m_event.type << "\n";
        if (m_inp.eof()) {
            std::cout << "palundra!" << std::endl; 
            m_event.type = 0;
            return m_event;    
        }
        read_body();
        return m_event;
    };

    void read_body() {
        m_inp >> m_event.client_name;
        if (m_event.type == 3)
            m_inp >> m_event.table_number;
    } 
};

