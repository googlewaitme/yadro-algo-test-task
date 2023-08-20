#pragma once
#include <queue>
#include <string>
#include <unordered_map>
#include <fstream>

#include "mytime.h"
#include "event.h"


class ComputerClub {
private:
    int m_cost_per_hour;
    int m_count_of_tables;
    Time m_start_time, m_end_time;
    std::unordered_map<std::string, int> m_clients;
    std::ifstream file;
    std::queue<std::string> clients_queue;
public:
    ComputerClub(std::string filename);
    void event_handling();

    void handle(Event event);

    void client_come (Event event);
    void client_sit_at_table(Event event);
    void client_is_waiting(Event event);
    void client_left(Event event);
};
