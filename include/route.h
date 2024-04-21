#ifndef OOP_ROUTE_H
#define OOP_ROUTE_H

#include "station.h"
#include "string"
#include "transportation.h"
#include "bus.h"
#include "train.h"
#include "plane.h"

class Route {
    static int routeCount;
    Station *origin{}, *destination{};
    int routeID = 0, duration = 0, length = 0;
    double price{};
    std::vector<std::string> timetable;
    Transportation* transport{};
public:
    Route(int &, Station *, Station *, Transportation*);

    Route() = default;

    friend std::ostream& operator<<(std::ostream &, const Route &);

    [[nodiscard]] double getPrice() const;

    [[nodiscard]] Transportation* getTransport() const;

    [[nodiscard]] const Station *getOrigin() const;

    [[nodiscard]] const Station *getDestination() const;

    friend std::istream& operator>>(std::istream &, Route &);

    friend bool operator<(const Route&, const Route &);

    ~Route() {
        delete transport;
//        delete origin;
//        delete destination;
        timetable.clear();
    }
};

#endif //OOP_ROUTE_H
