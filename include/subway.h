#ifndef OOP_SUBWAY_H
#define OOP_SUBWAY_H

#include "transportation.h"
#include "iostream"

class Subway: public Transportation {
    std::string bus;
public:
    explicit Subway(const std::string& = "", const std::string& = "");

    std::string getModel() override {
        return this->model;
    }

    void read(std::istream &) override;

    void print(std::ostream &) const override;

    ~Subway() override = default;
};

#endif //OOP_SUBWAY_H
