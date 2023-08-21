#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#include "computer_club.h"
#include "event.h"
#include "client.h"


ComputerClub::ComputerClub(std::string filename) : file(filename) {
    if (not file.is_open()) {
        throw std::invalid_argument("file is not opened");
    }
    file >> m_count_of_tables >> m_start_time >> m_end_time >> m_cost_per_hour;
    if (file.fail()) {
        throw std::invalid_argument("file can't read");
    }
    m_tables = std::vector<Table> (m_count_of_tables+1);
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
    if (m_client_to_table.contains(event.client_name)) {
        std::cout << event.time << " 13 YouShallNotPass\n";
        return;
    }
    // check if name is valid here;
    Client potencial_client(event.client_name);
    // client in club, but not seating at table;
    m_client_to_table[event.client_name] = -1;
}

void ComputerClub::client_sit_at_table(Event event) {
    if (not m_client_to_table.contains(event.client_name)) {
        std::cout << event.time << " 13 ClientUnknown\n";
        return;
    }
    // TODO check table_number is less than count_of_computers
    if (m_tables[event.table_number].is_busy) {
        std::cout << event.time << " 13 PlaceIsBusy\n";
        return;
    }
    int last_table = m_client_to_table[event.client_name];
    if (last_table != -1) {
        m_tables[last_table].end_of_using(m_cost_per_hour, event.time);
    }
    m_tables[event.table_number].start_of_using(event.time);
    m_client_to_table[event.client_name] = event.table_number;
    m_number_of_occupied_computers++;
}

void ComputerClub::client_is_waiting(Event event) {
    if (not m_client_to_table.contains(event.client_name)) {
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
    if (not m_client_to_table.contains(event.client_name)) {
        std::cout << event.time << " 13 ClientUnknown\n";
        return;
    }
    if (m_client_to_table[event.client_name] > 0) {
        int table_id = m_client_to_table[event.client_name];
        m_tables[table_id].end_of_using(m_cost_per_hour, event.time);
        // std::cout << "CHECK_QUEUE_SIZE " << m_clients_queue.size() << "\n";
        if (m_clients_queue.size() > 0) {
            Event new_seater_in_club(event.time, 12, m_clients_queue.front(), table_id);
            m_clients_queue.pop();
            client_sit_at_table(new_seater_in_club);
            std::cout << new_seater_in_club << std::endl;
        }
    }
    m_client_to_table.erase(event.client_name);
}



void ComputerClub::go_away_last_clients() {
    std::vector<std::string> last_clients;
    while (m_clients_queue.size()) {
        last_clients.push_back(m_clients_queue.front());
        m_clients_queue.pop();
    }
    for (auto client: m_client_to_table) {
        if (client.second > 0) {
            last_clients.push_back(client.first);
        }
    }
    sort(last_clients.begin(), last_clients.end());
    Event client_left_event(m_end_time, 11, "bulat");
    for (auto name: last_clients) {
        client_left_event.client_name = name;
        client_left(client_left_event);
        std::cout << client_left_event << std::endl;
    }
}


void ComputerClub::make_conclusion() {
    for (int i=1; i<=m_count_of_tables; i++) {
        Time used_time(m_tables[i].used_time);
        std::cout << i << " " << m_tables[i].income << " " << used_time << "\n";
    }
}

