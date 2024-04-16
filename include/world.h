#ifndef OOP_WORLD_H
#define OOP_WORLD_H

#include "iostream"
#include "unordered_map"
#include "station.h"
#include "route.h"

class World {
    std::unordered_map<std::string, std::vector<Route>> routes{};
public:
    World() = default;

    // print n objects
    void printAllTransportMeans(Station&, Station&);

    void addRoute(const Route &route);

    std::unordered_map<std::string, std::vector<Route>> &getRoutes();

    ~World() = default;
};

#endif //OOP_WORLD_H
