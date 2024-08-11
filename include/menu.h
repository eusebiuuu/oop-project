#ifndef OOP_MENU_H
#define OOP_MENU_H

#include <iostream>
#include <world.h>
#include "customer.h"
#include "customer.cpp"
#include "iostream"
#include "station.h"
#include "ticket.h"
#include "customer.h"
#include "discount-customer.h"
#include "discount-customer.cpp"
#include "route.h"
#include "world.h"
#include "exception"
#include <algorithm>
#include "array"

class Menu {
private:
    World* world;
    vector<Station *> stations;
    vector<Customer<string> *> customers;
    vector<Transportation *> transports;
    vector<Journey *> journeys;
    Menu() {
        world = new World();
    };
    ~Menu() {
        for (const auto* customer : customers) {
            delete customer;
        }
        for (const Journey *j : journeys) {
            delete j;
        }
        for (const Station* station : stations) {
            delete station;
        }
        for (const Transportation *t : transports) {
            delete t;
        }
        delete world;
        customers.clear();
        stations.clear();
        transports.clear();
        journeys.clear();
    }
public:

    Menu(const Menu&) = delete;

    Menu& operator=(const Menu&) = delete;

    static Menu& getMenu() {
        static Menu menu;
        return menu;
    }

    static void printMenu();

    void controlPanel();

    template<typename T>
    Journey *buyTicket();

    template<typename T, typename U = int>
    Customer<T>* readCustomer();

    void readRoute();

    void addTransportation();

    std::array<Station *, 2> getStations();

    void readStation();
};

#endif //OOP_MENU_H
