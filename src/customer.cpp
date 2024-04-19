#include "customer.h"
#include <algorithm>
#include "iostream"
#include "bus.h"
#include "train.h"
#include "plane.h"
#include "check-exception.h"
#include "invalid-datatype.h"

Customer::Customer(const std::string& citizenID, const std::string& fullName) {
    this->citizenID = citizenID;
    this->fullName = fullName;
}

// downcast 1
std::vector<Route> Customer::getSuitableRoutes(const Station &stat1, const Station &stat2, World& world, std::vector<std::string>& preferredTransport, int neededSeats) {
    // cout << stat1 << '\n' << stat2 << '\n';
    std::vector<Route> allRoutes = world.getRoutes()[stat1.getName()], suitableRoutes;
    for (Route route : allRoutes) {
        // cout << route << '\n';
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

Ticket Customer::buyTicket(const Station &stat1, const Station &stat2, World& world, std::vector<std::string>& preferredTransport, int neededSeats) {
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
    try {
        if (dynamic_cast<Bus*>(currTransport)) {
            throw CheckException("bus");
        } else if (dynamic_cast<Train*>(currTransport)) {
            throw CheckException("train");
        } else if (dynamic_cast<Plane*>(currTransport)) {
            throw CheckException("plane");
        } else {
            throw std::invalid_argument("Transportation type not in the accepted list");
        }
    } catch (CheckException &err) {
        if (std::count(preferredTransport.begin(), preferredTransport.end(), err.what()) == 0) {
            throw InvalidDatatype();
        }
    } catch (InvalidDatatype &err) {
        std::cout << err.what() << '\n';
        return Ticket{};
    }
    std::cout << "Choose the seat(s): ";
    const std::vector<int> freeSeats = currTransport->showAllFreeSeats();
    // for (const int &seat : freeSeats) {
    //     std::cout << seat << ' ';
    // }
    std::cout << '\n';
    std::vector<int> seatsToOccupy(neededSeats);
    for (int i = 0; i < neededSeats; ++i) {
        seatsToOccupy[i] = freeSeats[i];
    }
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
