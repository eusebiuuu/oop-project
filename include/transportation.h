#ifndef OOP_TRANSPORTATION_H
#define OOP_TRANSPORTATION_H

#include "vector"
#include "string"
#include "bitset"
#include "config.h"

class Transportation {
    static int transportCount;
public:
    int getTotalSeats() const;

private:
    double price;
    int totalSeats, transportID;
    std::string type, model;
    std::vector<std::vector<int>> seatsState;
public:
    Transportation(): price(0), totalSeats(0), transportID(transportCount++) {}

    void read(std::istream &);

    void print(std::ostream &) const;

    [[maybe_unused]] Transportation(const int &, const double &, const std::string &, const std::string &);

    Transportation &operator=(const Transportation &);

    void occupySeats(const std::vector<int> &, const int &);

    [[nodiscard]] std::bitset<Config::MAX_SEATS> getOccupiedSeats(int) const;

    [[nodiscard]] double getPrice() const;

    friend std::istream& operator>>(std::istream &, Transportation*);

    friend std::ostream& operator<<(std::ostream &, const Transportation &);

    virtual ~Transportation();

    [[nodiscard]] const std::string &getType() const;

    [[nodiscard]] int getTransportId() const;
};

#endif //OOP_TRANSPORTATION_H
