#include "customer.h"
#include <algorithm>
#include "iostream"
#include "transportation.h"
#include "set"
#include "checker.h"

int const INF = 2e9;

template<typename T1>
Customer<T1>::Customer(const T1& citizenID, const std::string& fullName) {
    this->citizenID = citizenID;
    this->fullName = fullName;
}

template<typename T1>
Journey *Customer<T1>::buyTicket(const Station *stat1, const Station *stat2, World *world, std::vector<std::string> &preferredTransport, const int &neededSeats, const int &tW, const int &pW) {
    std::set<std::pair<double, const Station *>> minCost;
    minCost.insert({0, stat1});
    vector<std::pair<int, Route *>> prevStation(Station::getStationCount());
    vector<double> bestCost(Station::getStationCount(), INF);
    bestCost[stat1->getStationId()] = 0;
    auto journey = new Journey({});
    double ans = -1;
    auto worldMap = world->getRoutes();
    while (!minCost.empty()) {
        double currCost = minCost.begin()->first;
        auto currStat = minCost.begin()->second;
        if (currStat->getStationId() == stat2->getStationId()) {
            ans = currCost;
            break;
        }
        minCost.erase(minCost.begin());
        for (const auto currRoute : worldMap[currStat->getName()]) {
            double newCost = currCost + tW * currRoute->getDuration() + pW * currRoute->getPrice();
            auto occupiedSeats = currRoute->getTransport()->getAllFreeSeats(currRoute->getRouteId());
            if ((int) occupiedSeats.size() < neededSeats) {
                continue;
            }
            if (!preferredTransport.empty()) {
                auto iter = std::find(preferredTransport.begin(), preferredTransport.end(), currRoute->getTransport()->getType());
                if (iter == preferredTransport.end()) {
                    continue;
                }
            }
            int nextID = currRoute->getDestination()->getStationId();
            if (bestCost[nextID] > newCost) {
                prevStation[nextID] = {currStat->getStationId(), currRoute};
                bestCost[nextID] = newCost;
            }
            minCost.insert({bestCost[nextID], currRoute->getDestination()});
        }
    }
    if (ans < 0) {
        cout << "No route found\n";
        return journey;
    }
    vector<Route *> optimalRoute;
    int currID = stat2->getStationId();
    while (currID != stat1->getStationId()) {
        optimalRoute.push_back(prevStation[currID].second);
        currID = prevStation[currID].first;
    }
    reverse(optimalRoute.begin(), optimalRoute.end());
    for (const auto currRoute : optimalRoute) {
        auto currTicket = new Ticket();
        currTicket->updateTicket(currRoute, neededSeats);
        auto freeSeats = currRoute->getTransport()->getAllFreeSeats(currRoute->getRouteId());
        std::cout << "Choose the seat(s): ";
        for (int freeSeat : freeSeats) {
            std::cout << freeSeat << ' ';
        }
        std::cout << '\n';
        std::vector<int> seatsToOccupy;
        for (int i = 0; i < neededSeats; ++i) {
            int x;
            cout << "Enter the seat number: \n";
            cin >> x;
            Checker<int>::throwIfNotInList(x, freeSeats, "Seat is occupied");
            freeSeats.erase(std::remove(freeSeats.begin(), freeSeats.end(), x), freeSeats.end());
            seatsToOccupy.push_back(x);
        }
        currRoute->getTransport()->occupySeats(seatsToOccupy, currRoute->getRouteId());
        currTicket->setSeats(seatsToOccupy);
        *journey += currTicket;
    }
    return journey;
}

template<typename T>
std::istream &operator>>(std::istream &in, Customer<T> *customer) {
    customer->read(in);
    return in;
}

template<typename T1>
Customer<T1> &Customer<T1>::operator=(const Customer<T1> &customer) {
    this->fullName = customer.fullName;
    this->citizenID = customer.citizenID;
    return *this;
}

template<typename T1>
void Customer<T1>::read(std::istream &in) {
    std::cout << "Citizen ID: \n";
    in >> this->citizenID;
    std::cout << "Full name: \n";
    in >> this->fullName;
}

template<typename T1>
const T1 &Customer<T1>::getCitizenId() const {
    return citizenID;
}
