#include "menu.h"
using namespace std;

int main() {
    Menu &menu = Menu::getMenu();
    menu.controlPanel();
    return 0;
}
