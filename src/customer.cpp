#include "customer.h"
#include <algorithm>
#include <utility>
#include "iostream"
#include "bus.h"
#include "train.h"
#include "plane.h"

Customer::Customer(std::string citizenID, std::string fullName) {
    this->citizenID = std::move(citizenID);
    this->fullName = std::move(fullName);
}

// downcast 1
std::vector<Route> Customer::getSuitableRoutes(Station &stat1, Station &stat2, World& world, const std::vector<std::string>& preferredTransport, int neededSeats) {
    std::vector<Route> allRoutes = world.getRoutes()[stat1.getName()], suitableRoutes;
    for (Route route : allRoutes) {
        if ((int) route.getTransport()->showAllFreeSeats().size() < neededSeats) {
            continue;
        }
        if (route.getDestination().getName() != stat2.getName()) {
            continue;
        }
        if (preferredTransport.empty()) {
            suitableRoutes.push_back(route);
            continue;
        }
        if (dynamic_cast<Bus*>(route.getTransport())) {
            if (std::count(preferredTransport.begin(), preferredTransport.end(), "bus") > 0) {
                suitableRoutes.push_back(route);
            }
        } else if (dynamic_cast<Train*>(route.getTransport())) {
            if (std::count(preferredTransport.begin(), preferredTransport.end(), "train") > 0) {
                suitableRoutes.push_back(route);
            }
        } else if (dynamic_cast<Plane*>(route.getTransport())) {
            if (std::count(preferredTransport.begin(), preferredTransport.end(), "plane") > 0) {
                suitableRoutes.push_back(route);
            }
        }
    }
    return suitableRoutes;
}

Ticket Customer::buyTicket(Station &stat1, Station &stat2, World& world, const std::vector<std::string>& preferredTransport, int neededSeats) {
    std::vector<Route> suitableRoutes = getSuitableRoutes(stat1, stat2, world, preferredTransport, neededSeats);
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
    Transportation* currTransport = chosenRoute.getTransport();
    std::cout << "Choose the seat(s): ";
    const std::vector<int> freeSeats = currTransport->showAllFreeSeats();
    for (const int &seat : freeSeats) {
        std::cout << seat << ' ';
    }
    std::cout << '\n';
    std::vector<int> seatsToOccupy = {freeSeats[0]};
    currTransport->occupySeats(seatsToOccupy);
    double currPrice = chosenRoute.getPrice();
    Ticket boughtTicket(stat1, stat2, currPrice, seatsToOccupy);
    std::cout << boughtTicket.getTotalPrice() << '\n';
    this->purchasedTickets.push_back(boughtTicket);
    return boughtTicket;
}

std::istream &operator>>(std::istream &in, Customer &customer) {
    customer.read(in);
    return in;
}

Customer &Customer::operator=(const Customer & customer) {
    this->fullName = customer.fullName;
    this->citizenID = customer.citizenID;
    return *this;
}

void Customer::read(std::istream &in) {
    in >> this->citizenID >> this->fullName;
}

const std::string &Customer::getCitizenId() const {
    return citizenID;
}
