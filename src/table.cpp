#include "table.h"
#include "mytime.h"


Table::Table() {
    used_time = 0;    
    income = 0;
}


void Table::end_of_using(int m_cost_per_hour, Time end_time) {
    is_busy = false;
    int count_of_minutes_at_table = get_time_delta(start_use, end_time);
    // added +59 for ceil getted_value purpose
    income += m_cost_per_hour * ((count_of_minutes_at_table + 59) / 60);
    used_time += count_of_minutes_at_table;
}


void Table::start_of_using(Time start_time) {
    is_busy = true;
    start_use = start_time;
}

