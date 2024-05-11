### Project description
Welcome to "Ticketist", the app to rule all the ticket management systems. I have decided to create an app with this theme, because I am a huge fan of public transportation and I find it a very customisable and challenging theme to implement. Also, I hate the concept of personal car as a transportation mean.

### Objects
* World
  - this represents the oriented graph obtained with stations and routes
  - needed for simplifying the structure and future logic
* Station
  - these represent the nodes in the graph
  - can be a departure or an arrival for a route
  - props (till now): name
* Journey (to be implemented)
  - this is the path between the given stations capable of using more than 1 route
  - price
  - start & finish
  - totalTime
* Route
  - routeID
  - this constitutes a directed edge from the graph
  - transportation
  - duration
  - start & finish
  - price
  - distance
* Ticket
  - seat(s)
  - ticketID
  - total price
  - start station
  - end station
* Transportation
  - type: train, bus, plane (only them - to be implemented)
  - cost (price per km)
  - average speed (km per hour)
  - available seats (to be implemented: sit - premium, sit - normal, stand)
* Customer
  - type: single, family, elder, student, scholar group
  - citizenID
  - bought tickets
  - full name

### Major functionalities
* A customer can buy tickets
  * Specify the origin and destination
  * Choose a route from a list
  * Choose which seats to occupy
  * Apply discount on ticket
  * Possible routes are sorted by default based on price

### Given tasks
#### Part 1
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
- funcționalitatea creată să folosească metode ale obiectului generic
- ar fi bine ca relația de agregare să fie făcută cu un obiect general în stilul celor de mai sus ^

#### Part 2
- [x] separarea codului din clase în `.h` (sau `.hpp`) și `.cpp` [(0.5p)](https://github.com/Ionnier/poo/tree/main/proiect/P01#separarea-implement%C4%83rii-metodelor-din-clase)
- [x] cât mai multe `const` [(0.5p)](https://github.com/Ionnier/poo/tree/main/labs/L04#reminder-const-everywhere)
- [x] moșteniri [(5p)](https://github.com/Ionnier/poo/tree/main/labs/L04#exemplu):
  - [x] minim o clasă de bază și **2 clase derivate**
  - [x] derivați o clasă creată anterior
  - [x] ilustrați [upcast](https://github.com/Ionnier/poo/tree/main/labs/L04#solu%C8%9Bie-func%C8%9Bii-virtuale-late-binding)-ul și [downcast](https://github.com/Ionnier/poo/tree/main/labs/L04#smarter-downcast-dynamic-cast)-ul folosind funcții virtuale și pointeri la clasa de bază
    - aceasta va fi făcută prin **2-3** metode specifice temei alese
    - funcțiile pentru citire / afișare sau destructorul nu sunt incluse deși o să trebuiască să le implementați
  - [x] apelarea constructorului din clasa de bază din [constructori din derivate](https://github.com/Ionnier/poo/tree/main/labs/L04#comportamentul-constructorului-la-derivare)
  - [x] suprascris [cc](https://github.com/Ionnier/poo/tree/main/labs/L04#comportamentul-constructorului-de-copiere-la-derivare) / op= pentru copieri/atribuiri corecte
  - [x] destructor [virtual](https://github.com/Ionnier/poo/tree/main/labs/L04#solu%C8%9Bie-func%C8%9Bii-virtuale-late-binding)
- [x] funcții și atribute `static` (în clase) [(1p)](https://github.com/Ionnier/poo/tree/main/labs/L04#static)
- [x] excepții [(1p)](https://github.com/Ionnier/poo/tree/main/labs/L04#exception-handling)
  - porniți de la `std::exception`
  - ilustrați propagarea excepțiilor
  - ilustrati upcasting-ul în blocurile catch
  - minim folosit într-un loc în care tratarea erorilor în modurile clasice este mai dificilă
- [x] folosirea unei clase abstracte (fie la exceptii, fie la moșteniri) [(0.5p)](https://github.com/Ionnier/poo/tree/main/labs/L04#clase-abstracte)
- [x] actualizarea meniului & scenariului de utilizare [(0.5p)](https://github.com/Ionnier/oop-template-t1/blob/main/main.cpp#L16)
- [x] citirea și afișarea a n obiecte [(0.5p)](https://github.com/Ionnier/oop-template-t1/blob/main/main.cpp#L13)
  - poate fi combinat cu demonstrarea upcasting-ului & downcast-ului printr-un vector către o clasă de bază
  - poate fi făcut oriunde (dacă aveți deja o clasă cu un vector, de exemplu o clasă Coș cu un vector<Produs>)
- [x] existența unui pull request către branch-ul în care lucrați ce include adăugarea unei noi derivate ce evidențiază că modificările aduse sunt minimale (0.5p)
  - derivata nu poate fi una ștearsă și rescrisă
  - derivata va avea date membre noi + o modificare de comportament pe una dintre funcțiile virtuale
- [x] Add more tests

#### Part 3
- Clase template (2p)
  - [ ] crearea unei ierarhii de clase template cu minim 2 clase
  - [ ] ilustrarea RTTI pe clase template
  - [ ] instanțieri cu logică a claselor create
- STL (2p)
  - [ ] utilizarea a două structuri (containere) din (fără vector)
  - [ ] utilizarea a unui algoritm cu funcție lambda (de exemplu, sort, transform)
- Design Patterns (2p)
  - [ ] utilizarea a două șabloane de proiectare
- Prezentare (4p)
  - [ ] răspunsuri la întrebări din cod / generale C++
  - [ ] explicarea a unei alte structuri sau a altui algoritm neutilizat (STL)
  - [ ] explicarea a altor două șabloane de proiectare