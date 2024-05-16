#ifndef OOP_TICKET_BUILDER_H
#define OOP_TICKET_BUILDER_H

#include "ticket.h"

class TicketBuilder {
    Ticket ticket;
public:
    TicketBuilder() {
        this->ticket.ticketID = Ticket::ticketsCount++;
    }

    TicketBuilder &setOrigin(const Station &station) {
        this->ticket.origin = station;
        return *this;
    }

    TicketBuilder &setDestination(const Station &station) {
        this->ticket.destination = station;
        return *this;
    }

    TicketBuilder &setPrice(const double &price) {
        this->ticket.totalPrice = price;
        return *this;
    }

    TicketBuilder &setSeats(std::queue<int> &seats) {
        while (!seats.empty()) {
            this->ticket.seats.push_back(seats.back());
            seats.pop();
        }
        return *this;
    }

    Ticket build() {
        return ticket;
    }
};

#endif //OOP_TICKET_BUILDER_H
