#include "ticket.h"
#include "iostream"

int Ticket::ticketsCount = 0;

Ticket::Ticket(const Station &origin, const Station &dest, const double &price, const std::vector<int> &seats) {
    this->origin = origin;
    this->destination = dest;
    this->seats = seats;
    this->totalPrice = price;
    this->ticketID = Ticket::ticketsCount++;
}

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
