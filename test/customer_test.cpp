#include <gtest/gtest.h>
#include "customer.h"
#include "customer.cpp"
#include "route.h"
#include "transportation.h"
#include "world.h"
#include "discount-customer.cpp"

TEST(CustomerOverview, CustomerCreation) {
    auto* customer = new Customer<string>("1000", "John");
    EXPECT_EQ(customer->getCitizenId(), "1000");
    Customer<string>* copyCustomer = customer;
    EXPECT_EQ(copyCustomer->getCitizenId(), "1000");
    delete customer;
}

TEST(BuyTicket, CheckTheSortingAndFiltering) {
    auto* world = new World();
    auto* station1 = new Station("Stat 1");
    auto* station2 = new Station("Stat 2");
    int routeLen = 100;
    auto* bus = new Bus("Solaris", 201);
    auto* train = new Train("CFR", "1662");
    auto* route1 = new Route(routeLen, station1, station2, bus);
    auto* route2 = new Route(routeLen, station1, station2, train);
    EXPECT_EQ(route1->getTransport()->getModel(), "Solaris");
    world->addRoute(route1);
    world->addRoute(route2);
    auto* customer = new Customer<string>("1000", "John");
    std::vector<std::string> preferredTransport = {"bus", "train"};
    Ticket ticket = customer->buyTicket(station1, station2, world, preferredTransport);
    EXPECT_EQ((int) ticket.getTotalPrice(), 20);

    std::vector<std::string> preferredTransport2 = {"train"};
    Ticket ticket2 = customer->buyTicket(station1, station2, world, preferredTransport2);
    EXPECT_EQ((int) ticket2.getTotalPrice(), 40);
    delete customer;
    delete station1;
    delete station2;
    delete world;
}

TEST(BuyTicket, CheckDiscountAppliance) {
    auto* world = new World();
    auto* station1 = new Station("Stat 1");
    auto* station2 = new Station("Stat 2");
    int routeLen = 100;
    auto* bus = new Bus("Solaris", 201);
    auto* train = new Train("CFR", "1662");
    auto* route1 = new Route(routeLen, station1, station2, bus);
    auto* route2 = new Route(routeLen, station1, station2, train);
    EXPECT_EQ(route1->getTransport()->getModel(), "Solaris");
    world->addRoute(route1);
    world->addRoute(route2);
    std::string citizenID = "1000", name = "John", type = "donor";
    auto* customer = new DiscountCustomer(citizenID, name, type);
    std::vector<std::string> preferredTransport = {"bus", "train"};
    Ticket ticket = customer->buyDiscountTicket(station1, station2, world, preferredTransport);
    EXPECT_EQ((int) ticket.getTotalPrice(), 10);

    std::vector<std::string> preferredTransport2 = {"train"};
    Ticket ticket2 = customer->buyDiscountTicket(station1, station2, world, preferredTransport2);
    EXPECT_EQ((int) ticket2.getTotalPrice(), 20);
    delete customer;
    delete station1;
    delete station2;
    delete world;
}