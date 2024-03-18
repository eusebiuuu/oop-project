#include "station.h"
#include "iostream"

Station::Station(std::string &name) {
    this->name = name;
}

const std::string &Station::getName() const {
    return name;
}

std::istream &operator>>(std::istream &in, Station &station) {
    in >> station.name;
    return in;
}

std::ostream &operator<<(std::ostream &out, Station &station) {
    out << station.name << '\n';
    return out;
}


