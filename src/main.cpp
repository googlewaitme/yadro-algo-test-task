#include <iostream>
#include <fstream>

#include "computer_club.h"


int main(int argc, char* argv[]) {
    if (argc != 2) {
        // TODO check file is exists
        std::cout << "ERROR need filename" << "\n";
    }
    
    ComputerClub club(argv[1]);
    club.run_work_day();
	return 0;
}
