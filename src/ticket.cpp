#include "ticket.h"
#include "iostream"

Ticket::Ticket(Station &origin, Station &dest, double &price, std::vector<int> &seats) {
    this->origin = origin;
    this->destination = dest;
    this->seats = seats;
    this->totalPrice = price;
    this->ticketID = (int) (rand() % 1000);
}

double Ticket::getTotalPrice() const {
    return totalPrice;
}

const std::vector<int> &Ticket::getSeats() const {
    return seats;
}

const Station &Ticket::getOrigin() const {
    return origin;
}

const Station &Ticket::getDestination() const {
    return destination;
}

const int &Ticket::getTicketId() const {
    return ticketID;
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

// copy constructor
Ticket::Ticket(const Ticket &ticket) {
    ticketID = ticket.ticketID;
    destination = ticket.destination;
    origin = ticket.origin;
    seats = ticket.seats;
    totalPrice = ticket.totalPrice;
}

Ticket Ticket::operator*=(double discount) {
    totalPrice *= discount / 100.0;
    return *this;
}
