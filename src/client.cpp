#include <string>
#include <regex>

#include "client.h"


Client::Client() {
    m_name = "default_name";
}

Client::Client(std::string name) {
    m_name = name;
}

bool Client::is_valid_name() {
    // TODO error here
    static const std::regex r("[a-z0-9-_]");
    return regex_match(m_name, r);
}
