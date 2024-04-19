#include "plane.h"

int const AVG_SPEED = 500;
double const PRICE = 0.7;
int const SEATS = 300;

Plane::Plane(const std::string& modelName, const std::string& company): Transportation(SEATS, PRICE, AVG_SPEED) {
    this->model = modelName;
    this->company = company;
}

void Plane::read(std::istream& in) {
    in >> this->model >> this->company;
}

void Plane::print(std::ostream& out) const {
    out << "Plane:\n";
    out << "  Model: " << this->model << '\n';
    out << "  Company: " << this->company << '\n';
}