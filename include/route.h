#ifndef OOP_ROUTE_H
#define OOP_ROUTE_H

#include "station.h"
#include "string"
#include "transportation.h"

class Route {
    static int routeCount;
    Station *origin, *destination;
    int routeID, duration, length;
    double price;
    Transportation *transport;
public:
    Route(const int &, Station *, Station *, Transportation *, const int &);

    Route(): origin(), destination(), routeID(routeCount++), duration(0), length(0), price(0), transport() {}

    friend std::ostream& operator<<(std::ostream &, const Route &);

    [[nodiscard]] double getPrice() const;

    [[nodiscard]] Transportation* getTransport() const;

    [[nodiscard]] Station *getOrigin() const;

    [[nodiscard]] Station *getDestination() const;

    friend bool operator<(const Route &, const Route &);

    [[nodiscard]] int getDuration() const;

    static int getRouteCount();

    [[nodiscard]] int getRouteId() const;

    [[nodiscard]] int getLength() const;
};

#endif //OOP_ROUTE_H
