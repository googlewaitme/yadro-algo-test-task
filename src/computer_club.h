#pragma once
#include <queue>
#include <string>
#include <unordered_map>
#include <fstream>

#include "mytime.h"
#include "event.h"
#include "table.h"


class ComputerClub {
private:
    int m_cost_per_hour;
    Time m_start_time, m_end_time;
    std::unordered_map<std::string, int> m_client_to_table;
    std::ifstream file;
    std::queue<std::string> m_clients_queue;

    int m_number_of_occupied_computers = 0;
    int m_count_of_tables;
    std::vector<Table> m_tables;

    void client_come (Event event);
    void client_sit_at_table(Event event);
    void client_is_waiting(Event event);
    void client_left(Event event);
public:
    ComputerClub(std::string filename);
    
    void run_work_day();

    void event_handling();

    void handle(Event event);

    void go_away_last_clients();
    void make_conclusion();
};
