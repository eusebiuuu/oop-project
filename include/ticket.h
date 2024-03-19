#ifndef OOP_TICKET_H
#define OOP_TICKET_H

#include "station.h"

class Ticket {
    double totalPrice{};
    std::vector<int> seats{};
    Station origin{}, destination{};
    int ticketID{};
public:
    Ticket(Station &, Station &, double &, std::vector<int> &);

    // copy constructor
    Ticket(const Ticket &);

    Ticket() = default;

    [[nodiscard]] double getTotalPrice() const;

    // print operator
    friend std::ostream& operator<<(std::ostream &, const Ticket &);

    Ticket operator*=(double discount);
};

#endif //OOP_TICKET_H
