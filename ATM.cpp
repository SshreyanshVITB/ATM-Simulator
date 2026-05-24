#include "ATM.h"
#include <fstream>
#include <sstream>

ATM::ATM() {
    loadAccounts();
}

void ATM::loadAccounts() {
    accounts.push_back(Account(1001, 1234, 5000));
    accounts.push_back(Account(1002, 5678, 3000));
    accounts.push_back(Account(1003, 1111, 7000));
}

Account* ATM::login() {

    int accNo, pin;

    cout << "Account: ";
    cin >> accNo;

    cout << "PIN: ";
    cin >> pin;

    for (auto &acc : accounts) {
        if (acc.getAccountNumber() == accNo && acc.authenticate(pin)) {
            cout << "Login Success!\n";
            return &acc;
        }
    }

    cout << "Invalid login!\n";
    return nullptr;
}

void ATM::menu(Account *user) {

    int choice;
    double amount;

    do {
        cout << "\n1. Balance\n2. Deposit\n3. Withdraw\n4. History\n5. Exit\n";
        cin >> choice;

        switch(choice) {

        case 1:
            user->showBalance();
            break;

        case 2:
            cin >> amount;
            user->deposit(amount);
            cout << "Deposited\n";
            break;

        case 3:
            cin >> amount;
            if (user->withdraw(amount))
                cout << "Withdrawn\n";
            else
                cout << "Not enough balance\n";
            break;

        case 4:
            user->showHistory();
            break;

        case 5:
            cout << "Exit\n";
            break;
        }

    } while(choice != 5);
}