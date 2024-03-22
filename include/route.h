#ifndef OOP_ROUTE_H
#define OOP_ROUTE_H

#include "station.h"
#include "string"
#include "transportation.h"

class Route {
    Station origin, destination;
    int routeID{}, duration{}, length{};
    double price{};
    Transportation transport;
public:
    Route(int &, Station &, Station &, Transportation &);

    Route() = default;

    friend std::ostream& operator<<(std::ostream &, const Route &);

    [[nodiscard]] double getPrice() const;

    [[nodiscard]] Transportation &getTransport();

    [[nodiscard]] const Station &getOrigin() const;

    [[nodiscard]] const Station &getDestination() const;

    friend std::istream& operator>>(std::istream &, Route &);

    friend bool operator<(const Route&, const Route &);
};

#endif //OOP_ROUTE_H
