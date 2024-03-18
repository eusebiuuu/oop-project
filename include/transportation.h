#ifndef OOP_TRANSPORTATION_H
#define OOP_TRANSPORTATION_H

#include "vector"
#include "string"

class Transportation {
    int totalSeats, speed;
    std::string type;
    bool *occupiedSeats;
    double price;
public:
    Transportation() {
        this->totalSeats = 0;
        this->speed = 0;
        this->price = 0.0;
        this->occupiedSeats = new bool[0];
    };

    Transportation(int &, double &, int &, std::string &);

    void occupySeats(std::vector<int> &);

    [[nodiscard]] std::vector<int> showAllFreeSeats() const;

    [[nodiscard]] int getSpeed() const;

    [[nodiscard]] double getPrice() const;

    [[nodiscard]] int getTotalSeats() const;

    [[nodiscard]] const std::string &getType() const;

    [[nodiscard]] bool* getOccupiedSeats() const;

    friend std::istream& operator>>(std::istream &, Transportation &);

    ~Transportation();
};

#endif //OOP_TRANSPORTATION_H
