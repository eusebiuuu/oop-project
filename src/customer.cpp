#include "customer.h"
#include <algorithm>
#include <utility>
#include "iostream"

Customer::Customer(std::string citizenID, std::string fullName, std::string type) {
    this->citizenID = std::move(citizenID);
    this->fullName = std::move(fullName);
    this->type = std::move(type);
}

Ticket Customer::buyTicket(Station &stat1, Station &stat2, const std::vector<Route>& possibleRoutes, int neededSeats) {
    std::vector<Route> suitableRoutes;
    for (Route route : possibleRoutes) {
        if ((int) route.getTransport().showAllFreeSeats().size() < neededSeats) {
            continue;
        }
        suitableRoutes.push_back(route);
    }
    std::sort(suitableRoutes.begin(), suitableRoutes.end());
    if (suitableRoutes.empty()) {
        std::cout << "There is no available transportation on the chosen route:((\n";
        return Ticket{};
    }
    std::cout << "Possible routes: \n";
    for (const Route &route : suitableRoutes) {
        std::cout << route;
    }
    // std::cout << "Enter the desired route's ID: \n";
    Route chosenRoute = suitableRoutes[0];
    Transportation& currTransport = chosenRoute.getTransport();
    std::cout << "Choose the seat(s): ";
    const std::vector<int> freeSeats = currTransport.showAllFreeSeats();
    for (const int &seat : freeSeats) {
        std::cout << seat << ' ';
    }
    std::cout << '\n';
    std::vector<int> seatsToOccupy = {freeSeats[0]};
    currTransport.occupySeats(seatsToOccupy);
    double currPrice = chosenRoute.getPrice();
    Ticket boughtTicket(stat1, stat2, currPrice, seatsToOccupy);
    applyDiscount(boughtTicket);
    std::cout << boughtTicket.getTotalPrice() << '\n';
    this->purchasedTickets.push_back(boughtTicket);
    return boughtTicket;
}

void Customer::applyDiscount(Ticket &ticket) {
    const std::vector<std::pair<std::string, int>> discounts =
        {{"student", 90}, {"elder", 50}, {"donor", 50},
         {"family", 10}, {"scholar_group", 10}};
    for (const auto &discount : discounts) {
        if (discount.first == type) {
            ticket *= (double) discount.second;
            break;
        }
    }
}

std::istream &operator>>(std::istream &in, Customer &customer) {
    in >> customer.citizenID >> customer.fullName >> customer.type;
    return in;
}

Customer &Customer::operator=(const Customer & customer) {
    this->fullName = customer.fullName;
    this->citizenID = customer.citizenID;
    this->type = customer.type;
    return *this;
}
