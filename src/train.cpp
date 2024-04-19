#include "train.h"

int const AVG_SPEED = 200;
double const PRICE = 0.4;
int const SEATS = 500;

Train::Train(const std::string& modelName, const std::string& code): Transportation(SEATS, PRICE, AVG_SPEED) {
    this->model = modelName;
    this->code = code;
}

void Train::read(std::istream& in) {
    in >> this->model >> this->code;
}

void Train::print(std::ostream& out) const {
    out << "Train:\n";
    out << "  Model: " << this->model << '\n';
    out << "  Code: " << this->code << '\n';
}