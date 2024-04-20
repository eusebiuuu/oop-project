#include "transportation.h"
#include "iostream"

[[maybe_unused]] Transportation::Transportation(const int &totalSeats, const double &price, const int &speed) {
    this->occupiedSeats = std::vector<bool>(totalSeats);
    this->totalSeats = totalSeats;
    this->price = price;
    this->speed = speed;
}

void Transportation::occupySeats(const std::vector<int> &seatsToBeOccupied) {
    for (int x : seatsToBeOccupied) {
        this->occupiedSeats[x] = true;
    }
}

std::vector<int> Transportation::showAllFreeSeats() const {
    std::vector<int> freeSeats;
    // std::cout << this->occupiedSeats.size() << '\n';
    // std::cout << sizeof(occupiedSeats) <<'\n';
    for (int i = 1; i <= this->totalSeats; ++i) {
        if (!occupiedSeats[i - 1]) {
            freeSeats.push_back(i);
        }
    }
    std::cout << freeSeats.size() << '\n';
    return freeSeats;
}

int Transportation::getSpeed() const {
    return this->speed;
}

double Transportation::getPrice() const {
    return this->price;
}

std::istream &operator>>(std::istream &in, Transportation &transportation) {
    transportation.occupiedSeats.clear();
    transportation.occupiedSeats = std::vector<bool>(transportation.totalSeats);
    transportation.read(in);
    return in;
}

std::ostream &operator<<(std::ostream &out, const Transportation &transportation) {
    transportation.print(out);
    return out;
}

Transportation& Transportation::operator=(const Transportation &transport) {
    if (this != &transport) {
        this->speed = transport.speed;
        this->totalSeats = transport.totalSeats;
        this->occupiedSeats = transport.occupiedSeats;
        this->price = transport.price;
    }
    return *this;
}

Transportation::~Transportation() {
    occupiedSeats.clear();
    totalSeats = 0;
    price = 0.0;
    speed = 0;
}
