#ifndef OOP_STATION_H
#define OOP_STATION_H

#include "vector"
#include "string"


class Station {
    static int stationCount;
    std::string name;
    int stationID;
public:
    explicit Station(const std::string &);

    Station(): stationID(stationCount++) {}

    [[nodiscard]] const std::string &getName() const;

    friend std::istream& operator>>(std::istream &, Station *);

    friend std::ostream& operator<<(std::ostream&, const Station *);

    static int getStationCount();

    [[nodiscard]] int getStationId() const;
};

#endif //OOP_STATION_H
