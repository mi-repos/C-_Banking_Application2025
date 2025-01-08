#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

class Account {
private:
    std::string accountNumber;
    std::string owner;
    double balance;
    std::vector<std::string> transactionHistory;

public:
    Account(const std::string& accNum, const std::string& ownerName);

    std::string getAccountNumber() const;
    std::string getOwner() const;
    double getBalance() const;
    void deposit(double amount);
    bool withdraw(double amount);
    bool transfer(Account& toAccount, double amount);
    void addTransaction(const std::string& transaction);
    void displayTransactionHistory() const;
    void displayAccountDetails() const;
};

#endif // ACCOUNT_H
