#include <iostream>
#include <fstream>
#include "time.cpp"
#include "event.cpp"


int main(int argc, char* argv[]) {
    if (argc != 2) {
        // TODO check file is exists
        std::cout << "ERROR need filename" << "\n";
    }
    /*
    */
    std::ifstream fin(argv[1]);

    int count_of_computers;
    Time start_time, end_time;
    int cost_per_hour;
    // TODO check is >= 0
    fin >> count_of_computers;
    fin >> start_time >> end_time;
    fin >> cost_per_hour;
    Event event;
    std::cout << "cost_per_hour: " << cost_per_hour << "\n";
    while (fin >> event) {
        std::cout << event << "\n";
    }
	return 0;
}
