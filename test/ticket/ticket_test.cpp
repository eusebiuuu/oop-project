#include "gtest/gtest.h"
#include "ticket.h"

TEST(TicketTestSuite, TestTicketFunctionalities) {
    Station station1("Station 1");
    Station station2("Station 2");
    std::vector<int> seats = {1, 2, 3, 4};
    double price = 56.99;
    Ticket ticket1(station1, station2, price, seats);
    EXPECT_EQ(ticket1.getTotalPrice(), price);
    EXPECT_EQ(ticket1.getOrigin().getName(), "Station 1");
    ticket1 *= 100;
    EXPECT_EQ(ticket1.getTotalPrice(), 56.99);
}