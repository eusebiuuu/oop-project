#include "discount-customer.h"

DiscountCustomer::DiscountCustomer(const std::string& citizenID,
                                   const std::string& fullName,
                                   const std::string& type):
                                   Customer(citizenID, fullName) {
    this->discount = discounts[type];
}

Ticket DiscountCustomer::buyDiscountTicket(Station& stat1, Station& stat2, World& world,
                 std::vector<std::string>& transport, int seats) {
    Ticket ticket = this->buyTicket(stat1, stat2, world, transport, seats);
    ticket *= (double) this->discount;
    return ticket;
}

void DiscountCustomer::read(std::istream &in) {
    std::string type;
    in >> this->citizenID >> this->fullName >> type;
    this->discount = discounts[type];
}

DiscountCustomer &DiscountCustomer::operator=(const DiscountCustomer &customer) {
    if (this != &customer) {
        this->fullName = customer.fullName;
        this->citizenID = customer.citizenID;
        this->discount = customer.discount;
    }
    return *this;
}