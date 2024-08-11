#ifndef OOP_CUSTOMER_H
#define OOP_CUSTOMER_H

#include <string>
#include "ticket.h"
#include "journey.h"
#include "route.h"
#include "world.h"
#include <algorithm>
#include "iostream"
#include "queue"

template<typename T1>
class Customer {
protected:
    T1 citizenID;
    std::vector<Ticket> purchasedTickets;
    std::string fullName;
public:
    Customer(const T1 &, const std::string&);

    Customer() = default;

    template<typename T>
    friend std::istream& operator>>(std::istream &, Customer<T> *);

    virtual void read(std::istream &);

    Customer& operator=(const Customer<T1> &);

    virtual Journey *buyTicket(const Station *, const Station *, World*, std::vector<std::string> &, const int &, const int &, const int &);

    virtual ~Customer() = default;

    [[nodiscard]] const T1 &getCitizenId() const;
};

#endif //OOP_CUSTOMER_H
