#include "ticket.h"
#include "iostream"

int Ticket::ticketsCount = 0;

double Ticket::getTotalPrice() const {
    return totalPrice;
}

std::ostream &operator<<(std::ostream &out, const Ticket &ticket) {
    out << "Ticket ID: " << ticket.ticketID << '\n';
    out << "Start: " << ticket.origin.getName() << '\n';
    out << "Destination: " << ticket.destination.getName() << '\n';
    out << "Seats: ";
    for (int seat : ticket.seats) {
        out << seat << ' ';
    }
    out << "\nTotal price: " << ticket.totalPrice << '\n';
    return out;
}

Ticket Ticket::operator*=(double discount) {
    totalPrice *= discount / 100.0;
    return *this;
}

const Station &Ticket::getOrigin() const {
    return origin;
}
