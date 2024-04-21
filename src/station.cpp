#include "station.h"
#include "iostream"

Station::Station(const std::string &name) {
    this->name = name;
}

const std::string &Station::getName() const {
    return name;
}

std::istream &operator>>(std::istream &in, Station *station) {
    in >> station->name;
    return in;
}

std::ostream &operator<<(std::ostream &out, const Station *station) {
    out << station->name << '\n';
    return out;
}


