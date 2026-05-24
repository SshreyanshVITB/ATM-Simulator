#ifndef ATM_H
#define ATM_H

#include "Account.h"
#include <vector>

class ATM {
private:
    vector<Account> accounts;

public:
    ATM();

    void loadAccounts();
    Account* login();
    void menu(Account *user);
};

#endif