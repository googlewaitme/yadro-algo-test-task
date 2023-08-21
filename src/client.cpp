#include <string>
#include <regex>
#include <format>

#include "client.h"


Client::Client() {
    m_name = "default_name";
}

Client::Client(std::string name) {
    m_name = name;
    if (not is_valid_name()) {
        // std::string message = std::format("{} name is not valid", name);
        throw std::invalid_argument("name is not valid");
    }
}

void Client::set_name(std::string name) {
    m_name = name;
}

bool Client::is_valid_name() {
    // TODO error here
    static const std::regex r("[a-z0-9-_]+");
    return regex_match(m_name, r);
}
