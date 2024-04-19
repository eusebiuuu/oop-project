#include "bus.h"
#include "iostream"

int const AVG_SPEED = 60;
double const PRICE = 0.2;
int const SEATS = 70;

Bus::Bus(const std::string& modelName, const int& num): Transportation(SEATS, PRICE, AVG_SPEED) {
    this->model = modelName;
    this->number = num;
}

void Bus::read(std::istream& in) {
    in >> this->model >> this->number;
}

void Bus::print(std::ostream& out) const {
    out << "Bus:\n";
    out << "  Model: " << this->model << '\n';
    out << "  Number: " << this->number << '\n';
}
