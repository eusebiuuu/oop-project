#include <fstream>
#include "iostream"
#include "station.h"
#include "ticket.h"
#include "customer.h"
#include "route.h"
#include "world.h"
using namespace std;
int const MAX_ID = 1000;

int main() {
    ifstream fin;
    fin.open("/home/eusebiuu/CLionProjects/oop-project/tastatura.txt");
    if (fin.fail()) {
        cout << "Error\n";
        return 1;
    }
    World world;
    int statCount;
    fin >> statCount;
    vector<Station> stations;
    for (int i = 0; i < statCount; ++i) {
        Station stat;
        fin >> stat;
        stations.push_back(stat);
    }
    // print n objects
    for (int i = 0; i < statCount; ++i) {
        cout << stations[i];
    }
    int routesCount;
    fin >> routesCount;
    vector<Route> routes;
    // read n objects
    for (int i = 0; i < routesCount; ++i) {
        Transportation transport;
        fin >> transport;
        int length, idxStat1, idxStat2;
        fin >> length >> idxStat1 >> idxStat2;
        Route currRoute(length, stations[idxStat1 - 1], stations[idxStat2 - 1], transport);
        world.addRoute(currRoute);
    }
    Customer customer1;
    fin >> customer1;
    Customer customer2("2938", "RomicaIon", "elder");
    Ticket gotTicket = customer1.buyTicket(stations[0], stations[1], world.getRoutes()[stations[0].getName()]);
    cout << '\n' << gotTicket << '\n';
    const Ticket& copyTicket(gotTicket);
    cout << '\n' << copyTicket;
    fin.close();
    return 0;
}
