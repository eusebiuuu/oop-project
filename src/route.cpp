#include "route.h"
#include "iostream"
#include "cmath"

int const MIN_IN_HOUR = 60, HOURS_IN_DAY = 24;

int Route::routeCount = 0;

Route::Route(int &length, Station &origin, Station &destination, Transportation* transport) {
    this->length = length;
    this->origin = origin;
    this->destination = destination;
    this->duration = (int) std::ceil((1.0 * length / transport->getSpeed()) * MIN_IN_HOUR);
    this->price = length * transport->getPrice();
    this->transport = transport;
    this->routeID = Route::routeCount++;
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

Transportation* Route::getTransport() {
    return this->transport;
}

const Station &Route::getOrigin() const {
    return origin;
}

const Station &Route::getDestination() const {
    return destination;
}

std::istream &operator>>(std::istream &in, Route &route) {
    in >> route.length >> route.origin >> route.destination >> *route.transport;
    route.price = route.length * route.transport->getPrice();
    route.duration = (int) std::ceil((route.length / route.transport->getSpeed()) * MIN_IN_HOUR);
    route.routeID = Route::routeCount++;
    return in;
}

bool operator<(const Route &route1, const Route &route2) {
    return route1.price < route2.price;
}

// downcast 2 + print n objects

