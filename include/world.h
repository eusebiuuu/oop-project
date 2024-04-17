#ifndef OOP_WORLD_H
#define OOP_WORLD_H

#include "iostream"
#include "unordered_map"
#include "station.h"
#include <route.h>

using namespace std;

class World {
    unordered_map<string, vector<Route>> routes{};
public:
    World() = default;

    // print n objects
    void printAllTransportMeans(Station&, Station&);

    void addRoute(Route &);

    unordered_map<string, vector<Route>> &getRoutes();

    ~World() = default;
};

#endif //OOP_WORLD_H
