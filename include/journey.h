#ifndef OOP_JOURNEY_H
#define OOP_JOURNEY_H

#include "vector"
#include "ticket.h"
#include "iostream"

class Journey {
    std::vector<Ticket *> tickets;
public:
    explicit Journey(const std::vector<Ticket *> &t): tickets(t) {}

    [[nodiscard]] double getTotalPrice() const {
        double totalPrice = 0;
        for (auto t : tickets) {
            totalPrice += t->getTotalPrice();
        }
        return totalPrice;
    }

    [[nodiscard]] int getTotalDuration() const {
        int totalDuration = 0;
        for (auto t : tickets) {
            totalDuration += t->getDuration();
        }
        return totalDuration;
    }

    Journey &operator*=(int discount) {
        for (auto t : tickets) {
            *t *= discount;
        }
        return *this;
    }

    Journey &operator+=(Ticket *t) {
        this->tickets.push_back(t);
        return *this;
    }

    friend std::ostream& operator<<(std::ostream &out, const Journey *journey) {
        out << "Journey: \n";
        for (auto t : journey->tickets) {
            out << t << '\n';
        }
        out << "Total price: " << journey->getTotalPrice() << '\n';
        out << "Total duration: " << journey->getTotalDuration() << '\n';
        return out;
    }

    ~Journey() {
        for (auto t : tickets) {
            delete t;
        }
    }
};

#endif //OOP_JOURNEY_H
