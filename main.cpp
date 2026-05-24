#include "ATM.h"
#include <fstream>
#include <sstream>

void processFile(Account *user) {

    ifstream file("request.txt");
    string line;

    while (getline(file, line)) {

        stringstream ss(line);
        string cmd;
        ss >> cmd;

        if (cmd == "AMOUNT") {
            double amt;
            ss >> amt;
            user->deposit(amt);
            cout << "Deposited from file: " << amt << endl;
        }
    }
}

int main() {

    ATM atm;

    Account *user = atm.login();

    if (user != nullptr) {

        processFile(user);

        atm.menu(user);
    }

    return 0;
}