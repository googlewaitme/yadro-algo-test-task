#include <string>
#include <fstream>
#include <iostream>

#include "computer_club.h"
#include "event.cpp"


ComputerClub::ComputerClub(std::string filename) : file(filename) {
    file >> m_count_of_tables >> start_time >> end_time >> m_cost_per_hour;
}


void ComputerClub::event_handling() {
    Event event;
    while (file >> event) {
        std::cout << event << "\n";
        if (event.time < start_time || event.time > end_time) {
            std::cout << event.time << " 13 NotOpenYet\n";
            continue;
        }
    }
}

