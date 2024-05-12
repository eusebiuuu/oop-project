#include "menu.h"

void Menu::printMenu() {
    std::cout << "Interactions:\n";
    std::cout << "1: Add n station\n";
    std::cout << "2: Add n routes (between existing stations)\n";
    std::cout << "3: Add customer with string id\n";
    std::cout << "4: Add customer with int id\n";
    std::cout << "5: Buy ticket - customers with string id\n";
    std::cout << "6: Buy ticket - customers with int id \n";
    std::cout << "7: Print all the stations\n";
    std::cout << "8: Print all transportation\n";
    std::cout << "9: Exit\n";
}

void Menu::controlPanel() {
    int command;
    do {
        printMenu();
        cin >> command;
        if (command == 1) {
            stations = readNStations();
        } else if (command == 2) {
            readNRoutes();
        } else if (command == 3) {
            customersStr.push_back(readCustomer<string, int>());
        } else if (command == 4) {
            customersInt.push_back(readCustomer<int, double>());
        } else if (command == 5) {
            try {
                Ticket ticket = buyTicket(customersStr);
                cout << ticket << '\n';
                const Ticket& copyTicket(ticket);
                cout << '\n' << copyTicket;
            } catch (TransportationException &err) {
                cerr << err.what() << '\n';
            } catch (std::exception &err) {
                cerr << "Unknown error occurred: " << err.what() << '\n';
                break;
            }
        } else if (command == 6) {
            try {
                Ticket ticket = buyTicket(customersInt);
                cout << ticket << '\n';
                const Ticket& copyTicket(ticket);
                cout << '\n' << copyTicket;
            } catch (TransportationException &err) {
                cerr << err.what() << '\n';
            } catch (std::exception &err) {
                cerr << "Unknown error occurred: " << err.what() << '\n';
                break;
            }
        } else if (command == 7) {
            // print n objects
            for (const Station* station : stations) {
                cout << station;
            }
        } else if (command == 8) {
            world->printAllTransportMeans(*stations[0], *stations[1]);
        }
    } while (command != 9);
}

vector<Station*> Menu::readNStations() {
    int statCount;
    cout << "Stations count: ";
    cin >> statCount;
    for (int i = 0; i < statCount; ++i) {
        auto* stat = new Station();
        cin >> stat;
        stations.push_back(stat);
    }
    return stations;
}

void Menu::readNRoutes() {
    int routesCount;
    cout << "Routes count: ";
    cin >> routesCount;
    // read n objects
    for (int i = 0; i < routesCount; ++i) {
        int length, idxStat1, idxStat2;
        cin >> length >> idxStat1 >> idxStat2;
        cout << "1 - bus | 2 - train | 3 - plane\n";
        // upcast
        int type;
        cin >> type;
        if (type == 1) {
            auto bus = new Bus();
            cin >> bus;
            auto* currRoute = new Route(length, stations[idxStat1 - 1], stations[idxStat2 - 1], bus);
            world->addRoute(currRoute);
        } else if (type == 2) {
            auto train = new Train();
            cin >> train;
            auto* currRoute = new Route(length, stations[idxStat1 - 1], stations[idxStat2 - 1], train);
            world->addRoute(currRoute);
        } else {
            auto plane = new Plane();
            cin >> plane;
            auto* currRoute = new Route(length, stations[idxStat1 - 1], stations[idxStat2 - 1], plane);
            world->addRoute(currRoute);
        }
    }
}

// upcast with pointers on template classes
template<typename T, typename U>
Customer<T>* Menu::readCustomer() {
    int customerType;
    cin >> customerType;
    if (customerType == 1) {
        auto* customer = new Customer<T>();
        cin >> customer;
        return customer;
    }
    auto* customer = new DiscountCustomer<T, U>();
    cin >> customer;
    DiscountCustomer<T, U>* auxCustomer = customer;
    return auxCustomer;
}

// downcast
template<typename T>
Ticket Menu::buyTicket(const vector<Customer<T>*>& customers) {
    if (customers.empty()) {
        throw std::invalid_argument("Customers array must not be empty");
    }
    const vector<string> possibleTypes = {"bus", "plane", "train"};
    T customerID;
    Station stat1, stat2;
    cin >> customerID >> &stat1 >> &stat2;
    int badCount, neededSeats;
    cin >> badCount;
    vector<string> badTransport(badCount);
    for (int i = 0; i < badCount; ++i) {
        cin >> badTransport[i];
        if (std::count(possibleTypes.begin(), possibleTypes.end(), badTransport[i]) == 0) {
            throw std::logic_error("Invalid transportation");
        }
    }
    cin >> neededSeats;
    for (Customer<T> *customer: customers) {
        if (customer->getCitizenId() != customerID) {
            continue;
        }
        if (auto specialCustomer = dynamic_cast<DiscountCustomer<T, int> *>(customer)) {
            auto ticket = specialCustomer->buyDiscountTicket(&stat1, &stat2, world, badTransport, neededSeats);
            delete specialCustomer;
            return ticket;
        }
        return customer->buyTicket(&stat1, &stat2, world, badTransport, neededSeats);
    }
    return Ticket{};
}