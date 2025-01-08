#ifndef BANKINGAPP_H
#define BANKINGAPP_H

#include "Account.h"
#include <vector>

class BankingApp {
private:
    std::vector<Account> accounts;
    
public:
    void createAccount();
    Account* findAccount(const std::string& accountNumber);
    void displayMenu();
    void run();
};

#endif // BANKINGAPP_H
