#include <string>
#include <utility>
#include "iostream"

class Car {
private:
    std::string producer, model;
    int releasePrice;
    int year;
public:
    Car(std::string producer, std::string model, int releasePrice, int year):
        producer(std::move(producer)),
        model(std::move(model)),
        releasePrice(releasePrice),
        year(year) {}
    Car(const Car &car):
        producer(car.producer),
        model(car.model), releasePrice(car.releasePrice), year(car.year) {}
    ~Car()= default;

    // no need for overloading the = operator because we already have defined the
    //copying mechanism with copying constructor

    friend std::ostream& operator<<(std::ostream &out, const Car &car) {
        out << car.producer << '\n' << car.model << '\n';
        out << car.year << '\n' << car.releasePrice << '\n';
        return out;
    }

    friend std::istream& operator>>(std::istream &in, Car &car) {
        in >> car.producer >> car.model;
        in >> car.year >> car.releasePrice;
        return in;
    }

    [[nodiscard]] double computeTheCurrentPrice(int currentYear) const {
        if (currentYear < year) {
            std::cout << "Invalid year provided\n";
            return -1.0;
        }
        double currPrice = releasePrice;
        for (int i = 0; i < currentYear - year; ++i) {
            currPrice *= 95.0 / 100.0;
        }
        return currPrice;
    }
};

int main() {
    Car car("Audi", "X8", 100, 2022);
    std::cout << car.computeTheCurrentPrice(2024) << '\n';
    return 0;
}