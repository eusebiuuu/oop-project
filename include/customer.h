#ifndef OOP_CUSTOMER_H
#define OOP_CUSTOMER_H

#include <string>
#include "ticket.h"
#include "ticket-builder.h"
#include "route.h"
#include "world.h"
#include <algorithm>
#include "iostream"
#include "queue"
#include "bus.h"
#include "train.h"
#include "plane.h"
#include "check-exception.h"
#include "invalid-datatype.h"

template<typename T1>
class Customer {
protected:
    T1 citizenID;
    std::vector<Ticket> purchasedTickets;
    std::string fullName;
public:
    // overloading constructor
    Customer(const T1 &, const std::string&);

    // initialisation constructor
    Customer() = default;

    // read operator
    template<typename T>
    friend std::istream& operator>>(std::istream &, Customer<T> *);

    virtual void read(std::istream &);

    Customer& operator=(const Customer<T1> &);

    static std::vector<Route*> getSuitableRoutes(const Station *, const Station *, World*, std::vector<std::string>&, int);

    Ticket buyTicket(const Station*, const Station*, World*, std::vector<std::string>&, int = 1);

    virtual ~Customer() = default;

    [[nodiscard]] const T1 &getCitizenId() const;
};

#endif //OOP_CUSTOMER_H
