#pragma once
#include <string>
#include <unordered_map>
#include <fstream>

#include "mytime.h"


class ComputerClub {
private:
    int m_cost_per_hour;
    int m_count_of_tables;
    Time start_time, end_time;
    std::unordered_map<std::string, int> m_clients;
    std::ifstream file;
public:
    ComputerClub(std::string filename);
    void event_handling();
};
