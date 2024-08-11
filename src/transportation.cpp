#include "transportation.h"
#include "checker.h"
#include "iostream"
#include "config.h"

int Transportation::transportCount = 0;

[[maybe_unused]] Transportation::Transportation(const int &totalSeats, const double &price, const std::string &model, const std::string &type):
    price(price), totalSeats(totalSeats), transportID(transportCount++), type(type), model(model),
    seatsState(std::vector<std::vector<int>>(totalSeats)) {}

void Transportation::occupySeats(const std::vector<int> &seatsToBeOccupied, const int &currRoute) {
    for (auto seat : seatsToBeOccupied) {
        this->seatsState[seat].push_back(currRoute);
    }
}

std::vector<int> Transportation::getAllFreeSeats(const int &currRoute) const {
    std::vector<int> freeSeats;
    for (int i = 0; i < this->totalSeats; ++i) {
        if (seatsState[i].empty()) {
            freeSeats.push_back(i);
            continue;
        }
        auto iter = std::find(seatsState[i].begin(), seatsState[i].end(), currRoute);
        if (iter == seatsState[i].end()) {
            freeSeats.push_back(i);
        }
    }
    return freeSeats;
}

void Transportation::read(std::istream &in) {
    std::cout << "Total seats: \n";
    in >> totalSeats;
    this->seatsState = std::vector<std::vector<int>>(totalSeats);
    std::cout << "Price per km: \n";
    in >> price;
    std::cout << "Transportation type (bus / train / plane / subway): \n";
    in >> type;
    Checker<std::string>::throwIfNotInList(type, Config::validTransportTypes, "Invalid transportation type");
    std::cout << "Model: \n";
    in >> model;
}

void Transportation::print(std::ostream &out) const {
    out << "Transport ID: " << transportID << '\n';
    out << "Total seats: " << totalSeats << '\n';
    out << "Price per km: " << price << '\n';
    out << "Type: " << type << '\n';
    out << "Model: " << model << '\n';
}

double Transportation::getPrice() const {
    return this->price;
}

std::istream &operator>>(std::istream &in, Transportation* transportation) {
    transportation->seatsState.clear();
    transportation->seatsState = std::vector<std::vector<int>>(transportation->totalSeats);
    transportation->read(in);
    return in;
}

std::ostream &operator<<(std::ostream &out, const Transportation &transportation) {
    transportation.print(out);
    return out;
}

Transportation& Transportation::operator=(const Transportation &transport) {
    if (this != &transport) {
        this->totalSeats = transport.totalSeats;
        this->seatsState = transport.seatsState;
        this->price = transport.price;
        this->type = transport.type;
        this->model = transport.model;
    }
    return *this;
}

Transportation::~Transportation() {
    seatsState.clear();
}

const std::string &Transportation::getType() const {
    return type;
}

int Transportation::getTransportId() const {
    return transportID;
}
