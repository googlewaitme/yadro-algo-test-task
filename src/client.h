#pragma once
#include <string>
#include <regex>


class Client {
private:
    std::string m_name;
public:
    Client();
    Client(std::string name);
    bool is_valid_name();
    void set_name(std::string name);
};
