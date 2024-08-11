#ifndef OOP_TICKET_H
#define OOP_TICKET_H

#include "station.h"
#include "route.h"

class Ticket {
    static int ticketsCount;
    double totalPrice;
    std::vector<int> seats;
    Station *origin, *destination;
    int ticketID, duration;
public:
    Ticket(): totalPrice(0), seats({}), origin(), destination(), ticketID(ticketsCount++), duration(0) {}

    [[nodiscard]] double getTotalPrice() const;

    friend std::ostream& operator<<(std::ostream &, const Ticket *);

    Ticket operator*=(int discount);

    [[nodiscard]] int getDuration() const;

    [[nodiscard]] const std::vector<int> &getSeats() const;

    [[nodiscard]] Station *getOrigin() const;

    [[nodiscard]] Station *getDestination() const;

    [[nodiscard]] int getTicketId() const;

    void updateTicket(const Route *, const int &);

    void setSeats(const std::vector<int> &);
};

#endif //OOP_TICKET_H
