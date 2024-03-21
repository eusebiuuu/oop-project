### Project description
Welcome to "Ticketist", the app to rule all the ticket management systems. I have decided to create an app with this theme, because I am a huge fan of public transportation and I find it a very customisable and challenging theme to implement. Also, I hate the concept of personal car as a transportation mean.

### Objects
* Station
  - this represents both a possible departure or a possible arrival for a journey
  - name
  - neighbouring stations: outward, inward
* Journey (to be implemented)
  - this is the path between the given stations capable of using more than 1 route
  - price
  - start & finish
  - totalTime
* Route
  - routeID
  - transportation type
  - duration
  - start & finish
  - price
  - distance
* Ticket
  - seat(s)
  - ticketID
  - total price
  - get information
  - update ticket
  - cancel booking
  - start station, end station
* Transportation (to be implemented)
  - type: train, bus, plane
  - cost (price per km)
  - average speed (km per hour)
  - available seats (later: sit - premium, sit - normal, stand)
* Customer
  - type: single, family, elder, student, scholar group
  - citizenID
  - bought tickets
  - buy ticket
  - full name

### Major functionalities
* A customer can buy tickets
  * Specify the origin and destination
  * Choose a route from a list
  * Choose which seats to occupy
  * Apply discount on ticket
  * Possible routes are sorted by default based on price

### Given tasks
- [x] definirea a minim **2-3 clase** care sa interactioneze in cadrul temei alese (fie prin compunere, agregare sau doar sa apeleze metodele celeilalte intr-un mod logic) (5p)
  - pentru o clasă:
    - [x] constructori de inițializare (customer.h)
    - [x] constructor supraîncărcat (customer.h)
    - [x] constructori de copiere (ticket.h)
    - [x] `operator=` de copiere (customer.h)
    - [x] destructor (transportation.h)
    - [x] `operator<<` pentru afișare (std::ostream) (ticket.h)
    - [x] `operator>>` pentru citire (std::istream) (customer.h)
    - [x] alt operator supraîncărcat ca funcție membră (ticket.h)
    - [x] alt operator supraîncărcat ca funcție non-membră (route.h)
  - pentru celelalte clase se va defini doar ce e nevoie
- [x] implementarea a minim 3 funcții membru publice pentru funcționalități specifice temei alese, dintre care cel puțin 1-2 funcții mai complexe (3p) (customer.cpp - 2, transport.cpp - 1)
- [x] scenariu de utilizare a claselor definite (1p):
  - crearea de obiecte și apelarea tuturor funcțiilor membru publice în main
- [x] opțiune pentru citirea și afișarea a n obiecte (1p) (main.cpp)
- ? funcționalitatea creată să folosească metode ale obiectului generic
- ? ar fi bine ca relația de agregare să fie făcută cu un obiect general în stilul celor de mai sus ^


