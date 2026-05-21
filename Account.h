#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <vector>
using namespace std;

class Account {
private:
    int accountNumber;
    int pin;
    double balance;
    vector<string> history;

public:
    Account(int accNo, int p, double bal);

    bool authenticate(int enteredPin);

    void deposit(double amount);

    bool withdraw(double amount);

    bool transfer(Account &receiver, double amount);

    void showBalance();

    void addHistory(string record);

    void showHistory();

    int getAccountNumber();

    double getBalance();
};

#endif