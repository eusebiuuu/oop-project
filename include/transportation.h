#ifndef OOP_TRANSPORTATION_H
#define OOP_TRANSPORTATION_H

#include "vector"
#include "string"

class Transportation {
    int totalSeats, speed;
    std::string type;
    std::vector<bool> occupiedSeats;
    double price;
public:
    Transportation() {
        this->totalSeats = 0;
        this->speed = 0;
        this->price = 0.0;
        this->occupiedSeats = {};
    };

    [[maybe_unused]] Transportation(const int &, const double &, const int &, const std::string &);

    Transportation(const Transportation &);

    void occupySeats(const std::vector<int> &);

    [[nodiscard]] std::vector<int> showAllFreeSeats() const;

    [[nodiscard]] int getSpeed() const;

    [[nodiscard]] double getPrice() const;

    friend std::istream& operator>>(std::istream &, Transportation &);

    ~Transportation();
};

#endif //OOP_TRANSPORTATION_H
