#include "iostream"
#include "string"
#include "map"

class Telefon {
private:
    std::string producator, model;
    bool isOpen = false;
    std::map<std::string, std::string> contacts;
    std::string lastDialedNumber;
public:
    Telefon(std::string producator, std::string model) :
        producator(std::move(producator)), model(std::move(model)) {}

    void aplicatie_apel() {
        isOpen = true;
    }

    void apeleaza(std::string number) {
        if (!isOpen) {
            return;
        }
        lastDialedNumber = number;
        isOpen = false;
    }

    std::string& operator~() {
        return lastDialedNumber;
    }

    void creeaza_contact(std::string contactName, std::string contactNumber) {
        contacts[contactName] = contactNumber;
    }

    std::string& operator[](std::string contactName) {
        return contacts[contactName];
    }

    friend std::ostream& operator<<(std::ostream& out, const Telefon &telefon) {
        out << telefon.model << '\n' << telefon.producator << '\n';
        return out;
    }
};

int main() {
    Telefon t("Producator", "Model");

    t.aplicatie_apel();

    t.apeleaza("XXXXXXXXXX"); // poate fi accesat doar din 'ecranul' în care intrăm prin funcția precedentă

    std::cout << ~t; // va afișa ultimul număr format

    t.aplicatie_apel();

    t.creeaza_contact("XXXXXXXXXX", "BBBB"); // poate fi accesată doar din 'ecranul' funcției precedente

    t["XXXXXXXXXX"]; // va returna numele contactului cu numărul "XXXXXXXXXX" "BBBB"

    std::cout << t;
}