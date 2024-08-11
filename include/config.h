#ifndef OOP_CONFIG_H
#define OOP_CONFIG_H

#include "unordered_map"
#include "string"
#include "vector"

class Config {
public:
    static const std::unordered_map<std::string, int> discounts;
    static const std::vector<std::string> validTransportTypes;
};

#endif //OOP_CONFIG_H
