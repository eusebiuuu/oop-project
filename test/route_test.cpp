#include <gtest/gtest.h>
#include "route.h"

TEST(GeneralRoute, ProperRouteCreation) {
    int len = 100;
    Station station1("Start");
    Station station2("Finish");
    Bus* bus = new Bus("Solaris", 201);
    auto* route = new Route(len, &station1, &station2, bus);
    EXPECT_EQ(station1.getName(), "Start");
    EXPECT_EQ(route->getTransport()->getSpeed(), 60);
    EXPECT_EQ(route->getTransport()->getModel(), "Solaris");
    EXPECT_EQ((int) route->getPrice(), 20);
    EXPECT_EQ(route->getOrigin()->getName(), "Start");
    EXPECT_EQ(route->getDestination()->getName(), "Finish");
    delete route;
}