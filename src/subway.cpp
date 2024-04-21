#include "subway.h"

int const AVG_SPEED = 500;
double const PRICE = 0.8;
int const SEATS = 200;

Subway::Subway(const std::string& modelName, const std::string& bus): Transportation(SEATS, PRICE, AVG_SPEED) {
    this->model = modelName;
    this->bus = bus;
}

void Subway::read(std::istream& in) {
    in >> this->model >> this->bus;
}

void Subway::print(std::ostream& out) const {
    out << "Train:\n";
    out << "  Model: " << this->model << '\n';
    out << "  Bus: " << this->bus << '\n';
}