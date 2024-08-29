# Ticketist
**Ticketist** is a console interactive tickets management tool built with abstraction in mind that helps the public transportation companies handle the purchasing of tickets and the finding of the most suitable journeys between 2 stations with the routes and transportation means available.

## Table of contents
- [Overview](#overview)
- [Installation setup](#installation-setup)
- [Functionalities](#functionalities)
- [Code snippets](#code-snippets)
- [Authors](#authors)
- [References](#references)


## Overview
This projects intends to facilitate the travel by public transportation, currently limited to train, bus or plane, but easily extensible, by finding the most suitable path between 2 stations using common shortest path algorithms like Dijkstra's algorithm and creating a ticket for the chosen path and with the desired seats. Also, in case of lack of direct transportation between 2 stations, a ticket (called `Journey` in this case, in project terms) will be made up of multiple tickets, one for each transportation mean. This is in order to maintain a realistic seats choosing logic, provide more detailed information within the ticket and increase travel comfort for customers.

## Installation setup
1. Clone the repository on your local machine and switch on it
   ```sh
   git clone https://github.com/eusebiuuu/oop-project.git && cd oop-project
   ```
2. Create the builds with cmake
   ```shell
   cmake -S . -B cmake-build-debug
   ```
3. Run the program
   ```shell
   ./cmake-build-debug/runner
   ```

## Functionalities
Basically, the app consists of an interactive menu that allows the user to perform some operations, like adding transportation means, customers, stations and routes. A route consists, among others, of a single transportation mean and 2 stations. Also, a transportation mean can be on multiple routes or none and the only ones that can buy tickets are the customers from the list.  
Besides this, the main functionality resides in ticket buying functionality. This consists of finding the shortest path between 2 inputted stations considering both time and price depending on the weights inserted by the customer and, also, the preferred transportation and the number of permanent free seats along the journey. As a result, the best found route according to the filters is printed to the screen and, after choosing the seats from the ones available, the tickets are generated. As stated above, if there is no direct path between 2 stations and one must use 2 or more transportation means, multiple tickets will be generated, one for each different transportation.  
One last notable functionality is the discount received by some special customers. More exactly, if a customer has the type of `DiscountCustomer` it can benefit of some discount for each journey, this depending on the exact type.

## Code snippets
#### Finding the best path (first part)
```c++
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
```
#### Reading routes
```c++
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
```
## Authors
This project was build only by me, with the knowledge acquired from Object-Oriented-Programming discipline from faculty I'm registered in.
## References
The project was build starting with [this template](https://github.com/Ionnier/oop-template).