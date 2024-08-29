#include "ticket.h"
#include "iostream"

int Ticket::ticketsCount = 0;

double Ticket::getTotalPrice() const {
    return totalPrice;
}

std::ostream &operator<<(std::ostream &out, const Ticket *ticket) {
    out << "Ticket ID: " << ticket->getTicketId() << '\n';
    out << "Start: " << ticket->getOrigin()->getName() << '\n';
    out << "Destination: " << ticket->getDestination()->getName() << '\n';
    out << "Seats: ";
    for (int seat : ticket->getSeats()) {
        out << seat << ' ';
    }
    out << '\n';
    out << "Total price: " << ticket->getTotalPrice() << '\n';
    out << "Duration: " << ticket->getDuration() << '\n';
    return out;
}

Ticket Ticket::operator*=(int discount) {
    totalPrice *= (double) discount / 100.0;
    return *this;
}

int Ticket::getDuration() const {
    return duration;
}

const std::vector<int> &Ticket::getSeats() const {
    return seats;
}

Station *Ticket::getOrigin() const {
    return origin;
}

Station *Ticket::getDestination() const {
    return destination;
}

int Ticket::getTicketId() const {
    return ticketID;
}

void Ticket::setSeats(const std::vector<int> &s) {
    Ticket::seats = s;
}