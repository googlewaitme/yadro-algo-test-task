#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

#include "computer_club.h"
#include "event.h"


ComputerClub::ComputerClub(std::string filename) : file(filename) {
    file >> m_count_of_tables >> m_start_time >> m_end_time >> m_cost_per_hour;
    m_table_is_busy = std::vector<bool> (m_count_of_tables + 1, false);
    m_number_of_occupied_computers = 0;
}

void ComputerClub::run_work_day() {
    std::cout << m_start_time << std::endl;
    event_handling();
    go_away_last_clients();
    std::cout << m_end_time << std::endl;
    make_conclusion(); 
}


void ComputerClub::event_handling() {
    Event event;
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
        return;
    }
    if (m_clients.contains(event.client_name)) {
        std::cout << event.time << " 13 YouShallNotPass\n";
        return;
    }
    // client in club, but not seating at table;
    m_clients[event.client_name] = -1;
}

void ComputerClub::client_sit_at_table(Event event) {
    if (not m_clients.contains(event.client_name)) {
        std::cout << event.time << " 13 ClientUnknown\n";
        return;
    }
    // TODO check table_number is less than count_of_computers
    if (m_table_is_busy[event.table_number]) {
        std::cout << event.time << " 13 PlaceIsBusy\n";
        return;
    }
    int last_table = m_clients[event.client_name];
    if (last_table != -1) {
        m_table_is_busy[last_table] = false;
        m_number_of_occupied_computers--;
    }
    m_table_is_busy[event.table_number] = true;
    m_clients[event.client_name] = event.table_number;
    m_number_of_occupied_computers++;
}

void ComputerClub::client_is_waiting(Event event) {
    if (not m_clients.contains(event.client_name)) {
        std::cout << event.time << " 13 ClientUnknown\n";
        return;
    }
    if (m_number_of_occupied_computers < m_count_of_tables) {
        std::cout << event.time << " 13 ICanWaitNoLonger\n";
        return;
    }
    if ((int) m_clients_queue.size() > m_count_of_tables) {
        std::cout << event.time << " 11 " << event.client_name << std::endl; 
        client_left(event);
        return;
    }
    m_clients_queue.push(event.client_name);
}

void ComputerClub::client_left(Event event) {
    if (not m_clients.contains(event.client_name)) {
        std::cout << event.time << " 13 ClientUnknown\n";
        return;
    }
    if (m_clients[event.client_name] > 0) {
        int table_id = m_clients[event.client_name];
        m_table_is_busy[table_id] = false;

        // std::cout << "CHECK_QUEUE_SIZE " << m_clients_queue.size() << "\n";
        if (m_clients_queue.size() > 0) {
            Event new_seater_in_club(event.time, 12, m_clients_queue.front(), table_id);
            m_clients_queue.pop();
            client_sit_at_table(new_seater_in_club);
            std::cout << new_seater_in_club << std::endl;
        }
    }
    m_clients.erase(event.client_name);
}



void ComputerClub::go_away_last_clients() {
    std::vector<std::string> last_clients;
    while (m_clients_queue.size()) {
        last_clients.push_back(m_clients_queue.front());
        m_clients_queue.pop();
    }
    for (auto client: m_clients) {
        if (client.second > 0) {
            last_clients.push_back(client.first);
        }
    }
    sort(last_clients.begin(), last_clients.end());
    for (auto name: last_clients) {
        std::cout << m_end_time << " 11 " << name << std::endl;
    }
}


void ComputerClub::make_conclusion() {
    std::cout << "Here must be conclusion\n";
}

