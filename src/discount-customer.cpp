#include "discount-customer.h"

template<typename T1, typename T2>
[[maybe_unused]] DiscountCustomer<T1, T2>::DiscountCustomer(std::string& citizenID,
                                   std::string& fullName,
                                   const std::string& type):
                                   Customer<T1>(citizenID, fullName) {
    this->discount = discounts[type];
}

template<typename T1, typename T2>
Ticket DiscountCustomer<T1, T2>::buyDiscountTicket(const Station* stat1, const Station* stat2, World *world,
                 std::vector<std::string>& transport, int seats) {
    Ticket ticket = this->buyTicket(stat1, stat2, world, transport, seats);
    ticket *= (double) this->discount;
    return ticket;
}

template<typename T1, typename T2>
void DiscountCustomer<T1, T2>::read(std::istream &in) {
    std::string type;
    in >> this->citizenID >> this->fullName >> type;
    this->discount = discounts[type];
}

template<typename T1, typename T2>
DiscountCustomer<T1, T2> &DiscountCustomer<T1, T2>::operator=(const DiscountCustomer<T1, T2> &customer) {
    if (this != &customer) {
        this->fullName = customer.fullName;
        this->citizenID = customer.citizenID;
        this->discount = customer.discount;
    }
    return *this;
}
