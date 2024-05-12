#ifndef OOP_DISCOUNT_CUSTOMER_H
#define OOP_DISCOUNT_CUSTOMER_H

#include "customer.h"
#include "unordered_map"

template<typename T1 = std::string, typename T2 = int>
class DiscountCustomer : public Customer<T1> {
    T2 discount;
    std::unordered_map<std::string, int> discounts =
            {{"student", 90}, {"elder", 50}, {"donor", 50},
             {"family", 10}, {"scholar_group", 10}};
public:
    DiscountCustomer(): discount(0){}

    [[maybe_unused]] DiscountCustomer(std::string&, std::string&, const std::string&);

    Ticket buyDiscountTicket(const Station *, const Station *, World *,
                             std::vector<std::string>&, int = 1);

    void read(std::istream &in) override;

    // overload `=` operator
    DiscountCustomer<T1, T2> &operator=(const DiscountCustomer<T1, T2> &);

    ~DiscountCustomer() override = default;
};

#endif //OOP_DISCOUNT_CUSTOMER_H
