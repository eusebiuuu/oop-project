#include "world.h"

void World::addRoute(Route &route) {
    this->routes[route.getOrigin().getName()].push_back(route);
}

std::unordered_map<std::string, std::vector<Route>> &World::getRoutes() {
    return routes;
}

void World::printAllTransportMeans(const Station& stat1, const Station& stat2) {
    std::vector<Route> allRoutes = this->getRoutes()[stat1.getName()];
    for (Route route : allRoutes) {
        if (route.getDestination().getName() != stat2.getName()) {
            continue;
        }
        std::cout << *route.getTransport();
    }
}
