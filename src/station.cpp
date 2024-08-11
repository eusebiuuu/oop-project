#include "station.h"
#include "iostream"

int Station::stationCount = 0;

Station::Station(const std::string &name) {
    this->name = name;
    this->stationID = stationCount++;
}

const std::string &Station::getName() const {
    return name;
}

std::istream &operator>>(std::istream &in, Station *station) {
    std::cout << "Station name: \n";
    in >> station->name;
    return in;
}

std::ostream &operator<<(std::ostream &out, const Station *station) {
    out << "Station name: " << station->name << '\n';
    return out;
}

int Station::getStationCount() {
    return stationCount;
}

int Station::getStationId() const {
    return stationID;
}


