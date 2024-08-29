#include "customer.h"
#include <algorithm>
#include "iostream"
#include "transportation.h"
#include "set"
#include "checker.h"
#include "bitset"

int const INF = 2e9;

template<typename T1>
Customer<T1>::Customer(const T1& citizenID, const std::string& fullName) {
    this->citizenID = citizenID;
    this->fullName = fullName;
}

struct TravelInfo {
    double cost;
    bitset<Config::MAX_SEATS> seats;
    int transport_id;
    const Station *station;
    TravelInfo(): cost(0), seats(0), transport_id(-1), station() {}
    TravelInfo(double c, const bitset<Config::MAX_SEATS> sts, int t, const Station *s): cost(c), seats(sts), transport_id(t), station(s) {}
};

template<typename T1>
Journey *Customer<T1>::buyTicket(const Station *stat1, const Station *stat2, World *world, std::vector<std::string> &preferredTransport, const int &neededSeats, const int &tW, const int &pW) {
    auto compareInfo = [](TravelInfo a, TravelInfo b) {
        return a.cost < b.cost;
    };
    set<TravelInfo, decltype(compareInfo)> minCost;
    TravelInfo start(0, 0, -1, stat1);
    minCost.insert(start);
    vector<std::pair<int, Route *>> prevStation(Station::getStationCount());
    vector<double> bestCost(Station::getStationCount(), INF);
    bestCost[stat1->getStationId()] = 0;
    auto journey = new Journey({});
    double ans = -1;
    auto worldMap = world->getRoutes();
    while (!minCost.empty()) {
        double currCost = minCost.begin()->cost;
        auto currStat = minCost.begin()->station;
        auto currSeats = minCost.begin()->seats;
        auto currTransportID = minCost.begin()->transport_id;
        if (currStat->getStationId() == stat2->getStationId()) {
            ans = currCost;
            break;
        }
        minCost.erase(minCost.begin());
        for (Route *currRoute : worldMap[currStat->getName()]) {
            double newCost = currCost + tW * currRoute->getDuration() + pW * currRoute->getPrice();
            if (currRoute->getTransport()->getTransportId() != currTransportID) {
                currSeats = 0;
            }
            bitset<Config::MAX_SEATS> seatsToUpdate = currRoute->getTransport()->getOccupiedSeats(currRoute->getRouteId());
            currSeats |= seatsToUpdate;
            if (currRoute->getTransport()->getTotalSeats() - (int) currSeats.count() < neededSeats) {
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
            TravelInfo newInfo(bestCost[nextID], currSeats, currRoute->getTransport()->getTransportId(), currRoute->getDestination());
            minCost.insert(newInfo);
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
    int sz = (int) optimalRoute.size();
    for (int i = 0; i < sz; ++i) {
        const auto currRoute = optimalRoute[i];
        int currTransportID = currRoute->getTransport()->getTransportId(), j = i, totalDuration = 0;
        double totalPrice = 0;
        bitset<Config::MAX_SEATS> occupiedSeats;
        while (j < sz and optimalRoute[j]->getTransport()->getTransportId() == currTransportID) {
            totalPrice += optimalRoute[j]->getPrice();
            totalDuration += optimalRoute[j]->getDuration();
            occupiedSeats |= optimalRoute[j]->getTransport()->getOccupiedSeats(optimalRoute[j]->getRouteId());
            j++;
        }
        j--;
        auto currTicket = new Ticket(totalPrice, optimalRoute[i]->getOrigin(), optimalRoute[j]->getDestination(), totalDuration);
        vector<int> freeSeats;
        for (int s = 0; s < currRoute->getTransport()->getTotalSeats(); ++s) {
            if (!occupiedSeats[s]) {
                freeSeats.push_back(s);
            }
        }
        std::cout << "Choose the seat(s): ";
        for (int freeSeat : freeSeats) {
            std::cout << freeSeat << ' ';
        }
        std::cout << '\n';
        std::vector<int> seatsToOccupy;
        for (int _ = 0; _ < neededSeats; ++_) {
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
        i = j;
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
