#include "transportation.h"
#include "iostream"

[[maybe_unused]] Transportation::Transportation(const int &totalSeats, const double &price, const int &speed, const std::string &type) {
    this->occupiedSeats = std::vector<bool>(totalSeats);
    this->totalSeats = totalSeats;
    this->type = type;
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
    // std::cout << sizeof(occupiedSeats) <<'\n';
    for (int i = 1; i <= this->totalSeats; ++i) {
        if (!occupiedSeats[i - 1]) {
            freeSeats.push_back(i);
        }
    }
    return freeSeats;
}

int Transportation::getSpeed() const {
    return this->speed;
}

double Transportation::getPrice() const {
    return this->price;
}

std::istream &operator>>(std::istream &in, Transportation &transportation) {
    in >> transportation.totalSeats >> transportation.type;
    in >> transportation.price >> transportation.speed;
    transportation.occupiedSeats.clear();
    transportation.occupiedSeats = std::vector<bool>(transportation.totalSeats);
    // std::cout << sizeof transportation.occupiedSeats << '\n';
    return in;
}

Transportation::~Transportation() {
    occupiedSeats.clear();
    totalSeats = 0;
    type.clear();
    price = 0.0;
    speed = 0;
}

Transportation::Transportation(const Transportation &transport): totalSeats(transport.totalSeats),
speed(transport.speed), type(transport.type), occupiedSeats(std::vector<bool> (std::begin(transport.occupiedSeats), std::end(transport.occupiedSeats))),
price(transport.price){}
