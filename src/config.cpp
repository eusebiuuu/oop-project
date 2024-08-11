#include "config.h"

const std::unordered_map<std::string, int> Config::discounts = {
        {"student", 90},
        {"elder", 50},
        {"donor", 50},
        {"family", 10},
        {"scholar_group", 40}
};

const std::vector<std::string> Config::validTransportTypes = {"bus", "plane", "train", "subway"};
