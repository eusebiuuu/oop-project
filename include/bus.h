#ifndef OOP_BUS_H
#define OOP_BUS_H

#include "transportation.h"

class Bus: public Transportation {
    int number;
public:
    explicit Bus(const std::string&, const int&);

    std::string getModel() override {
        return this->model;
    }

    void read(std::istream &) override;

    void print(std::ostream &) const override;

    ~Bus() override = default;
};

#endif //OOP_BUS_H
