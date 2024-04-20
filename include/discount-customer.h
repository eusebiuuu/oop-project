#ifndef OOP_DISCOUNT_CUSTOMER_H
#define OOP_DISCOUNT_CUSTOMER_H

#include "customer.h"
#include "unordered_map"

class DiscountCustomer : public Customer {
    int discount;
    std::unordered_map<std::string, int> discounts =
            {{"student", 90}, {"elder", 50}, {"donor", 50},
             {"family", 10}, {"scholar_group", 10}};
public:
    DiscountCustomer(): discount(0){}

    [[maybe_unused]] DiscountCustomer(std::string&, std::string&, const std::string&);

    Ticket buyDiscountTicket(const Station &, const Station &, World *,
                             std::vector<std::string>&, int = 1);

    void read(std::istream &in) override;

    // overload `=` operator
    DiscountCustomer &operator=(const DiscountCustomer &);

    ~DiscountCustomer() override = default;
};

#endif //OOP_DISCOUNT_CUSTOMER_H
