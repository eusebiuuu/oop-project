#include "world.h"

void World::addRoute(Route *route) {
    this->routes[route->getOrigin()->getName()].push_back(route);
}

std::unordered_map<std::string, std::vector<Route*>> &World::getRoutes() {
    return routes;
}

// downcast 2 + print n objects
void World::printAllTransportMeans(const Station& stat1, const Station& stat2) {
    std::cout << stat1.getName() << ' ' << stat2.getName() << '\n';
    std::vector<Route*> allRoutes = this->getRoutes()[stat1.getName()];
    for (const Route* route : allRoutes) {
        if (route->getDestination()->getName() != stat2.getName()) {
            continue;
        }
        if (auto bus = dynamic_cast<Bus*>(route->getTransport())) {
            std::cout << *bus;
        } else if (auto train = dynamic_cast<Train*>(route->getTransport())) {
            std::cout << *train;
        } else if (auto plane = dynamic_cast<Plane*>(route->getTransport())) {
            std::cout << *plane;
        }
    }
}
