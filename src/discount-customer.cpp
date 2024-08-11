#include "discount-customer.h"
#include "config.h"

template<typename T1, typename T2>
[[maybe_unused]] DiscountCustomer<T1, T2>::DiscountCustomer(std::string& citizenID,
                                   std::string& fullName,
                                   const std::string& type):
                                   Customer<T1>(citizenID, fullName) {
    this->discount = Config::discounts.at(type);
}

template<typename T1, typename T2>
Journey *DiscountCustomer<T1, T2>::buyTicket(const Station *stat1, const Station *stat2, World *world, std::vector<std::string> &preferredTransport, const int &neededSeats, const int &tW, const int &pW) {
    Journey *j = Customer<T1>::buyTicket(stat1, stat2, world, preferredTransport, neededSeats, tW, pW);
    *j *= this->discount;
    return j;
}

template<typename T1, typename T2>
void DiscountCustomer<T1, T2>::read(std::istream &in) {
    cout << "Citizen ID: \n";
    in >> this->citizenID;
    cout << "Full name: \n";
    in >> this->fullName;
    cout << "Type of customer (student / elder / family / donor / scholar_group): \n";
    std::string type;
    in >> type;
    this->discount = Config::discounts.at(type);
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
