#include "transportation.h"
#include "iostream"

[[maybe_unused]] Transportation::Transportation(int &totalSeats, double &price, int &speed, std::string &type) {
    this->occupiedSeats = new bool[totalSeats + 1];
    this->totalSeats = totalSeats;
    this->type = type;
    this->price = price;
    this->speed = speed;
}

void Transportation::occupySeats(std::vector<int> &seatsToBeOccupied) {
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
    delete[] transportation.occupiedSeats;
    transportation.occupiedSeats = new bool[transportation.totalSeats];
    // std::cout << sizeof transportation.occupiedSeats << '\n';
    return in;
}

Transportation::~Transportation() {
    // delete[] occupiedSeats;
    totalSeats = 0;
    type.clear();
    price = 0.0;
    speed = 0;
}
