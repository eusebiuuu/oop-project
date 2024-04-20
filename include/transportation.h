#ifndef OOP_TRANSPORTATION_H
#define OOP_TRANSPORTATION_H

#include "vector"
#include "string"

class Transportation {
    int totalSeats, speed;
    std::vector<bool> occupiedSeats;
    double price;
protected:
    std::string model;
public:
    Transportation() {
        this->totalSeats = 0;
        this->speed = 0;
        this->price = 0.0;
        this->occupiedSeats = {};
    };

    [[maybe_unused]] virtual std::string getModel() = 0;

    virtual void read(std::istream &) = 0;

    virtual void print(std::ostream &) const = 0;

    [[maybe_unused]] Transportation(const int &, const double &, const int &);

    Transportation &operator=(const Transportation &);

    void occupySeats(const std::vector<int> &);

    [[nodiscard]] std::vector<int> showAllFreeSeats() const;

    [[nodiscard]] int getSpeed() const;

    [[nodiscard]] double getPrice() const;

    friend std::istream& operator>>(std::istream &, Transportation*);

    friend std::ostream& operator<<(std::ostream &, const Transportation &);

    virtual ~Transportation();
};

#endif //OOP_TRANSPORTATION_H
