#include "route.h"
#include "iostream"
#include "cmath"

int Route::routeCount = 0;

Route::Route(const int &length, Station *origin, Station *destination,
             Transportation *transport, const int &duration):
             origin(origin), destination(destination), routeID(routeCount++),
             duration(duration), length(length), transport(transport) {
    this->price = this->transport->getPrice() * length;
}

std::ostream& operator<<(std::ostream &out, const Route &route) {
    out << "Route ID: " << route.routeID << '\n';
    out << "Start: " << route.origin->getName() << '\n';
    out << "Destination: " << route.destination->getName() << '\n';
    out << "Length (in km): " << route.length << '\n';
    out << "Duration (in min): " << route.duration << '\n';
    out << "Price: " << route.price << '\n';
    return out;
}

double Route::getPrice() const {
    return price;
}

Transportation* Route::getTransport() const {
    return this->transport;
}

Station *Route::getOrigin() const {
    return origin;
}

Station *Route::getDestination() const {
    return destination;
}

bool operator<(const Route &route1, const Route &route2) {
    return route1.duration < route2.duration;
}

int Route::getDuration() const {
    return duration;
}

int Route::getRouteId() const {
    return routeID;
}
