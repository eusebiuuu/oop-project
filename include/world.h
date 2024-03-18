#ifndef OOP_WORLD_H
#define OOP_WORLD_H

#include "unordered_map"
#include "station.h"
#include "route.h"

class World {
    std::unordered_map<std::string, std::vector<Route>> routes;
public:
    World() = default;

    void addRoute(Route &route);

    std::unordered_map<std::string, std::vector<Route>> &getRoutes();
};

#endif //OOP_WORLD_H
