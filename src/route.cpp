#include "route.h"
#include "chrono"
#include "random"
#include "iostream"

std::mt19937
rnd(std::chrono::steady_clock::now().time_since_epoch().count());

Route::Route(int &length, Station &origin, Station &destination, Transportation &transport) {
    this->length = length;
    this->origin = origin;
    this->destination = destination;
    this->duration = length / transport.getSpeed();
    this->price = length * transport.getPrice();
    this->transport = transport;
    this->routeID = (int) (rand() % 1000);
}

std::ostream& operator<<(std::ostream &out, const Route &route) {
    out << "Route ID: " << route.routeID << '\n';
    out << "Start: " << route.origin.getName() << '\n';
    out << "Destination: " << route.destination.getName() << '\n';
    out << "Length (in km): " << route.length << '\n';
    out << "Duration (in min): " << route.duration << '\n';
    out << "Price: " << route.price << '\n';
    return out;
}

double Route::getPrice() const {
    return price;
}

Transportation &Route::getTransport() {
    return this->transport;
}

const Station &Route::getOrigin() const {
    return origin;
}

std::istream &operator>>(std::istream &in, Route &route) {
    in >> route.length >> route.origin >> route.destination >> route.transport;
    route.price = route.length * route.transport.getPrice();
    route.duration = (int) (route.length / route.transport.getSpeed());
    route.routeID = (int) (rnd() % 1000);
    return in;
}

bool operator<(const Route &route1, const Route &route2) {
    return route1.price < route2.price;
}
