#ifndef OOP_CUSTOMER_H
#define OOP_CUSTOMER_H

#include <string>
#include "ticket.h"
#include "route.h"

class Customer {
    std::string type;
    std::string citizenID;
    std::vector<Ticket> purchasedTickets;
    std::string fullName;
public:
    // overloading constructor
    Customer(std::string, std::string, std::string);

    // initialisation constructor
    Customer() = default;

    // read operator
    friend std::istream& operator>>(std::istream &, Customer &);

    Customer& operator=(const Customer &);

    void applyDiscount(Ticket &);

    Ticket buyTicket(Station &, Station &, const std::vector<Route> &, int = 1);
};

#endif //OOP_CUSTOMER_H
