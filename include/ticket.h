#ifndef OOP_TICKET_H
#define OOP_TICKET_H

#include "station.h"

class Ticket {
    static int ticketsCount;
    double totalPrice;
    std::vector<int> seats;
    Station origin, destination;
    int ticketID;
public:
    Ticket(Station &, Station &, double &, std::vector<int> &);

    Ticket() {
        totalPrice = 0;
        seats = {};
        origin = destination = {};
        ticketID = 0;
    };

    [[nodiscard]] double getTotalPrice() const;

    // print operator
    friend std::ostream& operator<<(std::ostream &, const Ticket &);

    Ticket operator*=(double discount);

    [[nodiscard]] const Station &getOrigin() const;
};

#endif //OOP_TICKET_H
