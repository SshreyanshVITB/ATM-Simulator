#include "ATM.h"

int main() {

    ATM atm;

    Account *user = atm.login();

    if (user != nullptr) {
        atm.menu(user);
    }

    return 0;
}