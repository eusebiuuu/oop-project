#ifndef OOP_DISCOUNT_CUSTOMER_H
#define OOP_DISCOUNT_CUSTOMER_H

#include "customer.h"
#include "unordered_map"
#include "journey.h"

template<typename T1 = std::string, typename T2 = int>
class DiscountCustomer : public Customer<T1> {
    T2 discount;
public:
    DiscountCustomer(): discount(0) {}

    [[maybe_unused]] DiscountCustomer(std::string&, std::string&, const std::string&);

    Journey *buyTicket(const Station *, const Station *, World*, std::vector<std::string> &, const int &, const int &, const int &) override;

    void read(std::istream &in) override;

    DiscountCustomer<T1, T2> &operator=(const DiscountCustomer<T1, T2> &);

    ~DiscountCustomer() override = default;
};

#endif //OOP_DISCOUNT_CUSTOMER_H
