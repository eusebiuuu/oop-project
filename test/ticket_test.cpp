#include "gtest/gtest.h"
#include "ticket.h"
#include "ticket-builder.h"

TEST(TicketTestSuite, TestTicketFunctionalities) {
    Station station1("Station 1");
    Station station2("Station 2");
    std::queue<int> seats;
    for (int i = 1; i <= 4; ++i) {
        seats.push(i);
    }
    double price = 56.99;
    TicketBuilder builder;
    Ticket ticket1 = builder.setOrigin(station1).setDestination(station2).setPrice(price).setSeats(seats).build();
    EXPECT_EQ(ticket1.getTotalPrice(), price);
    EXPECT_EQ(ticket1.getOrigin().getName(), "Station 1");
    ticket1 *= 100;
    EXPECT_EQ(ticket1.getTotalPrice(), 56.99);
}