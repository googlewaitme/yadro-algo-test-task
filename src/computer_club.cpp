#include <string>
#include <fstream>
#include <iostream>

#include "computer_club.h"
#include "event.h"


ComputerClub::ComputerClub(std::string filename) : file(filename) {
    file >> m_count_of_tables >> m_start_time >> m_end_time >> m_cost_per_hour;
}


void ComputerClub::event_handling() {
    Event event;
    std::cout << m_start_time << std::endl;
    while (file >> event) {
        std::cout << event << "\n";
        handle(event);
        
    }
}


void ComputerClub::handle(Event event) {
    switch(event.type) {
        case 1: client_come(event); break;
        case 2: client_sit_at_table(event); break;
        case 3: client_is_waiting(event); break;
        case 4: client_left(event); break;
    }
}


void ComputerClub::client_come (Event event) {
    if (event.time < m_start_time || event.time > m_end_time) {
        std::cout << event.time << " 13 NotOpenYet\n";
    }
}

void ComputerClub::client_sit_at_table(Event event) {

}

void ComputerClub::client_is_waiting(Event event) {

}

void ComputerClub::client_left(Event event) {

}

