#include "ATM.h"
#include <fstream>

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

    cout << "\n===== ATM LOGIN =====\n";

    cout << "Enter Account Number: ";
    cin >> accNo;

    cout << "Enter PIN: ";
    cin >> pin;

    for (auto &acc : accounts) {

        if (acc.getAccountNumber() == accNo &&
            acc.authenticate(pin)) {

            cout << "\nLogin Successful!\n";

            return &acc;
        }
    }

    cout << "\nInvalid Credentials!\n";

    return nullptr;
}

void ATM::menu(Account *user) {

    int choice;

    do {

        cout << "\n===== ATM MENU =====\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Transfer Money\n";
        cout << "5. Transaction History\n";
        cout << "6. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            user->showBalance();
            break;

        case 2: {
            double amount;
            cout << "Enter Amount: ";
            cin >> amount;

            user->deposit(amount);

            cout << "Deposit Successful!\n";

            break;
        }

        case 3: {
            double amount;

            cout << "Enter Amount: ";
            cin >> amount;

            if (user->withdraw(amount))
                cout << "Withdrawal Successful!\n";
            else
                cout << "Insufficient Balance!\n";

            break;
        }

        case 4: {

            int receiverAcc;
            double amount;

            cout << "Enter Receiver Account Number: ";
            cin >> receiverAcc;

            cout << "Enter Amount: ";
            cin >> amount;

            bool found = false;

            for (auto &acc : accounts) {

                if (acc.getAccountNumber() == receiverAcc) {

                    found = true;

                    if (user->transfer(acc, amount))
                        cout << "Transfer Successful!\n";
                    else
                        cout << "Insufficient Balance!\n";
                }
            }

            if (!found)
                cout << "Receiver Account Not Found!\n";

            break;
        }

        case 5:
            user->showHistory();
            break;

        case 6:
            cout << "\nThank You For Using ATM!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while(choice != 6);
}