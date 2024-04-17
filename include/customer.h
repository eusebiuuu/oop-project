#ifndef OOP_CUSTOMER_H
#define OOP_CUSTOMER_H

#include <string>
#include "ticket.h"
#include "route.h"
#include "world.h"

class Customer {
protected:
    std::string citizenID;
    std::vector<Ticket> purchasedTickets;
    std::string fullName;
public:
    // overloading constructor
    Customer(std::string, std::string);

    // initialisation constructor
    Customer() = default;

    // read operator
    friend std::istream& operator>>(std::istream &, Customer &);

    virtual void read(std::istream &);

    Customer& operator=(const Customer &);

    std::vector<Route> getSuitableRoutes(Station &stat1, Station &stat2, World&, std::vector<std::string>&, int);

    Ticket buyTicket(Station &, Station &, World&, std::vector<std::string>&, int = 1);

    virtual ~Customer() = default;

    [[nodiscard]] const std::string &getCitizenId() const;
};

#endif //OOP_CUSTOMER_H
