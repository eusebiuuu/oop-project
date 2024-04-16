#ifndef OOP_TRAIN_H
#define OOP_TRAIN_H

#include "transportation.h"
#include "iostream"

class Train: public Transportation {
    std::string code;
public:
    explicit Train(const std::string&, const std::string&);

    std::string getModel() override {
        return this->model;
    }

    void read(std::istream &) override;

    void print(std::ostream &) override;

    ~Train() override = default;
};


#endif //OOP_TRAIN_H
