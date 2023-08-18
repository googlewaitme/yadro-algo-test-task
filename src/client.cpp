#pragma once
#include <string>
#include <regex>


class Client {
private:
    std::string m_name;
    int m_id;
public:
    Client() {
        m_name = "default_name";
        m_id = 0;
    }

    Client(std::string name, int id) {
        m_name = name;
        m_id = id;
    }

    bool is_valid_name() {
        // TODO error here
        static const std::regex r("[a-z0-9-_]");
        return regex_match(m_name, r);
    }
};
