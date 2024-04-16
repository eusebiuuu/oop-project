#ifndef OOP_DISCOUNT_CUSTOMER_H
#define OOP_DISCOUNT_CUSTOMER_H

#include "customer.h"
#include "map"

std::map<std::string, int> discounts =
        {{"student", 90}, {"elder", 50}, {"donor", 50},
         {"family", 10}, {"scholar_group", 10}};

class DiscountCustomer : public Customer {
    int discount;
public:
    DiscountCustomer(const std::string&, const std::string&, const std::string&);

    Ticket buyDiscountTicket(Station &, Station &, World &,
                             const std::vector<std::string>&, int = 1);

    void read(std::istream &in) override;

    // overload `=` operator
    DiscountCustomer &operator=(const DiscountCustomer &);

    ~DiscountCustomer() override = default;
};

#endif //OOP_DISCOUNT_CUSTOMER_H
