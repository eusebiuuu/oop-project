#include "menu.h"

void Menu::printMenu() {
    std::cout << "\nInstructions:\n";
    std::cout << "1: Add station\n";
    std::cout << "2: Add route\n";
    std::cout << "3: Add customer\n";
    std::cout << "4: Add transport\n";
    std::cout << "5: Buy ticket\n";
    std::cout << "6: Print all the stations\n";
    std::cout << "7: Print all transportation\n";
    std::cout << "8: Exit\n";
}

void Menu::controlPanel() {
    int command;
    do {
        printMenu();
        cin >> command;
        if (command == 1) {
            try {
                readStation();
            } catch (const std::exception &err) {
                cerr << err.what() << '\n';
            }
        } else if (command == 2) {
            try {
                readRoute();
            } catch (const std::exception &err) {
                cerr << err.what() << '\n';
            }
        } else if (command == 3) {
            try {
                customers.push_back(readCustomer<string, int>());
            } catch (const std::exception &err) {
                cerr << err.what() << '\n';
            }
        } else if (command == 4) {
            try {
                addTransportation();
            } catch (const std::exception &err) {
                cerr << err.what() << '\n';
            }
        } else if (command == 5) {
            try {
                Journey *j = buyTicket<string>();
                cout << j << '\n';
                journeys.push_back(j);
            } catch (std::exception &err) {
                cerr << err.what() << '\n';
            }
        } else if (command == 6) {
            try {
                for (const Station* station : stations) {
                    cout << station;
                }
            } catch (std::exception &err) {
                cerr << err.what() << '\n';
            }
        } else if (command == 7) {
            try {
                for (const auto *t : transports) {
                    cout << *t;
                }
            } catch (std::exception &err) {
                cerr << err.what() << '\n';
            }
        }
    } while (command != 8);
}

void Menu::readStation() {
    auto* stat = new Station();
    cin >> stat;
    cout << stat;
    stations.push_back(stat);
}

void Menu::readRoute() {
    int length, duration, transportID;
    cout << "Enter the route length: \n";
    cin >> length;
    cout << "Duration (in minutes): \n";
    cin >> duration;
    cout << "Transport ID: \n";
    cin >> transportID;
    auto actualStations = getStations();
    auto iter = std::find_if(transports.begin(), transports.end(), [transportID](Transportation *t) {
        return t->getTransportId() == transportID;
    });
    if (iter == transports.end()) {
        throw std::runtime_error("Invalid transportation ID");
    }
    auto *transport = *iter;
    world->addRoute(new Route(length, actualStations[0], actualStations[1], transport, duration));
}

std::array<Station *, 2> Menu::getStations() {
    auto getActualStation = [this](const string &station) {
        auto ans = std::find_if(stations.begin(), stations.end(), [station](Station *s) {
            return s->getName() == station;
        });
        if (ans == stations.end()) {
            throw std::runtime_error("Station doesn't exist");
        }
        return *ans;
    };
    string station1, station2;
    cout << "Enter the start station name: \n";
    cin >> station1;
    auto actualStat1 = getActualStation(station1);
    cout << "Enter the finish station name: \n";
    cin >> station2;
    auto actualStat2 = getActualStation(station2);
    return {actualStat1, actualStat2};
}

void Menu::addTransportation() {
    auto *transport = new Transportation();
    cin >> transport;
    transports.push_back(transport);
    cout << "Transport added successfully!\n";
}

template<typename T, typename U>
Customer<T>* Menu::readCustomer() {
    std::string customerType;
    std::cout << "Type of customer (normal / discount): \n";
    cin >> customerType;
    if (customerType == "normal") {
        auto* customer = new Customer<T>();
        cin >> customer;
        return customer;
    } else if (customerType == "discount") {
        auto* customer = new DiscountCustomer<T, U>();
        cin >> customer;
        DiscountCustomer<T, U>* auxCustomer = customer;
        return auxCustomer;
    } else {
        throw std::runtime_error("Invalid customer type");
    }
}

template<typename T>
Journey *Menu::buyTicket() {
    if (customers.empty()) {
        throw std::invalid_argument("Customers array must not be empty");
    }
    T customerID;
    cout << "Insert the customer ID: \n";
    cin >> customerID;
    auto currCustomer = std::find_if(customers.begin(), customers.end(), [customerID](const Customer<T> *c) {
        return c->getCitizenId() == customerID;
    });
    if (currCustomer == customers.end()) {
        throw std::runtime_error("Customer doesn't exist");
    }
    auto actualStations = getStations();
    int preferredTransportCount, neededSeats;
    cout << "Preferred transportation (count and list, 0 means no preference): \n";
    cin >> preferredTransportCount;
    vector<string> preferredTransport(preferredTransportCount);
    for (int i = 0; i < preferredTransportCount; ++i) {
        cin >> preferredTransport[i];
    }
    int timeWeight, priceWeight;
    cout << "Enter the price and time weights to get the optimal route: \n";
    cout << "Time weight: \n";
    cin >> timeWeight;
    cout << "Price weight: \n";
    cin >> priceWeight;
    cout << "Enter the number of seats to book: \n";
    cin >> neededSeats;
    return (*currCustomer)->buyTicket(actualStations[0], actualStations[1], world, preferredTransport, neededSeats,
                                      timeWeight, priceWeight);
}