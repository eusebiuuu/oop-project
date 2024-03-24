#include <gtest/gtest.h>
#include "route.h"

TEST(MySuitName, MyTestName) {
    Route route;
    Station station1("Station 1");
    Station station2("Station 2");
    Transportation transport(30, 49.99, 70, "bus");
    int routeLen = 100;
    Route route2(routeLen, station1, station2, transport);
    EXPECT_EQ(route.getPrice(), 0.0);
    EXPECT_EQ(route2.getOrigin().getName(), "Station 1");
    EXPECT_EQ(route2.getDestination().getName(), "Station 2");
    EXPECT_EQ(route2.getTransport().getSpeed(), 70);
}