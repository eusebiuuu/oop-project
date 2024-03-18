#ifndef OOP_STATION_H
#define OOP_STATION_H

#include "vector"
#include "string"


class Station {
    std::string name;
public:
    explicit Station(std::string &);
    Station() = default;

    [[nodiscard]] const std::string &getName() const;

    friend std::istream& operator>>(std::istream &, Station &);

    friend std::ostream& operator<<(std::ostream&, Station &);
};

#endif //OOP_STATION_H
