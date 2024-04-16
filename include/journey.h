#ifndef OOP_JOURNEY_H
#define OOP_JOURNEY_H

#include "route.h"

class Journey {
    std::vector<Route> routes;
public:
    std::string newTime(std::string &, int) const;

    int convertStrDateToInt(std::string &) const;
};


#endif //OOP_JOURNEY_H
