#pragma once
#include "mytime.h"

struct Table {
    bool is_busy = false;
    int income = 0;
    Time start_use;
    int used_time = 0;

    Table();

    void end_of_using(int cost_per_hour, Time end_time);
    void start_of_using(Time start_time);
};
