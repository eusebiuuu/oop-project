#ifndef OOP_PLANE_H
#define OOP_PLANE_H

#include "transportation.h"
#include "iostream"

class Plane: public Transportation {
    std::string company;
public:
    explicit Plane(const std::string&, const std::string&);

    std::string getModel() override {
        return this->model;
    }

    void read(std::istream &) override;

    void print(std::ostream &) const override;

    ~Plane() override = default;
};


#endif //OOP_PLANE_H
