#pragma once
#include "mytime.h"

struct Table {
    bool is_busy = false;
    int income = 0;
    Time start_use;
    int used_time = 0;

    Table();
};
