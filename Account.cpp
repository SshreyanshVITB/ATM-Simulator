#include "Account.h"

Account::Account(int accNo, int p, double bal) {
    accountNumber = accNo;
    pin = p;
    balance = bal;
}

bool Account::authenticate(int enteredPin) {
    return pin == enteredPin;
}

void Account::deposit(double amount) {
    balance += amount;
    history.push_back("Deposited: " + to_string(amount));
}

bool Account::withdraw(double amount) {
    if (amount > balance) {
        return false;
    }

    balance -= amount;
    history.push_back("Withdrawn: " + to_string(amount));

    return true;
}

bool Account::transfer(Account &receiver, double amount) {
    if (amount > balance) {
        return false;
    }

    balance -= amount;
    receiver.balance += amount;

    history.push_back("Transferred: " + to_string(amount));
    receiver.history.push_back("Received: " + to_string(amount));

    return true;
}

void Account::showBalance() {
    cout << "\nCurrent Balance: $" << balance << endl;
}

void Account::addHistory(string record) {
    history.push_back(record);
}

void Account::showHistory() {
    cout << "\nTransaction History:\n";

    for (string record : history) {
        cout << record << endl;
    }
}

int Account::getAccountNumber() {
    return accountNumber;
}

double Account::getBalance() {
    return balance;
}