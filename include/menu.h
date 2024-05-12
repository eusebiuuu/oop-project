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
#include "bus.h"
#include "train.h"
#include "plane.h"
#include "exception"
#include "transportation-exception.h"
#include <algorithm>

class Menu {
private:
    World* world;
    vector<Station*> stations;
    vector<Customer<string>*> customersStr;
    vector<Customer<int>*> customersInt;
    Menu() {
        world = new World();
    };
    ~Menu() {
        for (const auto* customer : customersStr) {
            delete customer;
        }
        for (const auto* customer : customersInt) {
            delete customer;
        }
        customersStr.clear();
        customersInt.clear();
        for (const Station* station : stations) {
            delete station;
        }
        stations.clear();
        delete world;
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
    Ticket buyTicket(const vector<Customer<T> *> &customers);

    template<typename T, typename U = int>
    Customer<T>* readCustomer();

    void readNRoutes();

    vector<Station *> readNStations();
};

#endif //OOP_MENU_H
