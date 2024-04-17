#include "iostream"
#include "station.h"
#include "ticket.h"
#include "customer.h"
#include "discount-customer.h"
#include "route.h"
#include "world.h"
#include "bus.h"
#include "train.h"
#include "plane.h"
#include "exception"
using namespace std;

vector<Station*> readNStations() {
    vector<Station*> stations;
    int statCount;
    cout << "Stations count: ";
    cin >> statCount;
    for (int i = 0; i < statCount; ++i) {
        auto *stat = new Station();
        cin >> *stat;
        stations.push_back(stat);
    }
    return stations;
}

void readNRoutes(vector<Station*>& stations, World& world) {
    int routesCount;
    cout << "Routes count: ";
    cin >> routesCount;
    // read n objects
    for (int i = 0; i < routesCount; ++i) {
        cout << "1 - bus | 2 - train | 3 - plane\n";
        // upcast
        int type;
        cin >> type;
        cout << type << '\n';
        Transportation* transportation;
        if (type == 1) {
            Bus* bus = new Bus("", -1);
            cin >> *bus;
            transportation = bus;
            delete bus;
        } else if (type == 2) {
            auto* train = new Train("", "");
            cin >> *train;
            transportation = train;
            delete train;
        } else {
            auto* plane = new Plane("", "");
            cin >> *plane;
            transportation = plane;
            delete plane;
        }
        int length, idxStat1, idxStat2;
        cin >> length >> idxStat1 >> idxStat2;
        Route currRoute(length, *stations[idxStat1 - 1], *stations[idxStat2 - 1], transportation);
        world.addRoute(currRoute);
    }
}

Customer* readCustomer() {
    int customerType;
    cin >> customerType;
    if (customerType == 1) {
        auto* customer = new Customer();
        cin >> *customer;
        return customer;
    }
    auto* customer = new DiscountCustomer("", "", "");
    cin >> *customer;
    DiscountCustomer* auxCustomer = customer;
    return auxCustomer;
}

// downcast
Ticket buyTicket(vector<Customer*>& customers, World& world) {
    if (customers.empty()) {
        throw std::invalid_argument("Customers array must not be empty");
    }
    const vector<string> possibleTypes = {"bus", "plane", "train"};
    string customerID;
    auto *stat1 = new Station(), *stat2 = new Station();
    cin >> customerID >> *stat1 >> *stat2;
    int badCount, neededSeats;
    cin >> badCount;
    vector<string> badTransport(badCount);
    for (int i = 0; i < badCount; ++i) {
        cin >> badTransport[i];
        if (count(possibleTypes.begin(), possibleTypes.end(), badTransport[i]) == 0) {
            throw std::logic_error("Invalid transportation");
        }
    }
    cin >> neededSeats;
    for (Customer* customer : customers) {
        if (customer->getCitizenId() != customerID) {
            continue;
        }
        if (auto specialCustomer = dynamic_cast<DiscountCustomer*>(customer)) {
            auto ticket = specialCustomer->buyDiscountTicket(*stat1, *stat2, world, badTransport, neededSeats);
            delete specialCustomer;
            return ticket;
        }
        return customer->buyTicket(*stat1, *stat2, world, badTransport, neededSeats);
    }
    return Ticket{};
}

int main() {
    auto* world = new World();
    vector<Station*> stations;
    vector<Customer*> customers;
    int command;
    do {
        cout << "Interactions:\n";
        cout << "1: Add n station\n";
        cout << "2: Add n routes (between existing stations)\n";
        cout << "3: Add customer\n";
        cout << "4: Buy ticket\n";
        cout << "5: Print all the stations\n";
        cout << "6: Print all transportation\n";
        cout << "7: Exit\n";
        cin >> command;
        if (command == 1) {
            stations = readNStations();
        } else if (command == 2) {
            readNRoutes(stations, *world);
        } else if (command == 3) {
            // upcast
            customers.push_back(readCustomer());
        } else if (command == 4) {
            try {
                Ticket ticket = buyTicket(customers, *world);
                cout << ticket << '\n';
                const Ticket& copyTicket(ticket);
                cout << '\n' << copyTicket;
            } catch (std::logic_error &err) {
                cerr << err.what() << '\n';
            }
        } else if (command == 5) {
            // print n objects
            for (auto station : stations) {
                cout << *station;
            }
        } else if (command == 6) {
            world->printAllTransportMeans(*stations[0], *stations[1]);
        }
    } while (command != 7);
    customers.clear();
    stations.clear();
    delete world;
    return 0;
}
