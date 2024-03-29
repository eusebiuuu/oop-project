#include <fstream>
#include "iostream"
#include "station.h"
#include "ticket.h"
#include "customer.h"
#include "route.h"
#include "world.h"
using namespace std;

int main() {
    // ifstream fin;
    // fin.open("/home/eusebiuu/CLionProjects/oop-project/tastatura.txt");
    // if (fin.fail()) {
    //     cout << "Error\n";
    //     return 1;
    // }
    World world;
    int statCount;
    cin >> statCount;
    vector<Station> stations;
    for (int i = 0; i < statCount; ++i) {
        Station stat;
        cin >> stat;
        stations.push_back(stat);
    }
    // print n objects
    for (int i = 0; i < statCount; ++i) {
        cout << stations[i];
    }
    int routesCount;
    cin >> routesCount;
    // read n objects
    for (int i = 0; i < routesCount; ++i) {
        Transportation transport;
        cin >> transport;
        int length, idxStat1, idxStat2;
        cin >> length >> idxStat1 >> idxStat2;
        Route currRoute(length, stations[idxStat1 - 1], stations[idxStat2 - 1], transport);
        world.addRoute(currRoute);
    }
    Customer customer1;
    cin >> customer1;
    Customer customer2("2938", "RomicaIon", "elder");
    Ticket ticket1 = customer1.buyTicket(stations[0], stations[1], world.getRoutes()[stations[0].getName()]);
    Ticket ticket2 = customer2.buyTicket(stations[0], stations[2], world.getRoutes()[stations[0].getName()]);
    cout << '\n' << ticket1 << '\n' << ticket2 << '\n';
    const Ticket& copyTicket(ticket1);
    cout << '\n' << copyTicket;
    cout << copyTicket.getOrigin().getName() << '\n';
    // fin.close();
    return 0;
}
