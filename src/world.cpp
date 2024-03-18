#include "route.h"
#include "world.h"

void World::addRoute(Route &route) {
    this->routes[route.getOrigin().getName()].push_back(route);
}

std::unordered_map<std::string, std::vector<Route>> &World::getRoutes() {
    return routes;
}
