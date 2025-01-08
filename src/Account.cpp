#include "Account.h"
#include <iostream>
#include <iomanip>

Account::Account(const std::string& accNum, const std::string& ownerName)
    : accountNumber(accNum), owner(ownerName), balance(0.0) {}

std::string Account::getAccountNumber() const {
    return accountNumber;
}

std::string Account::getOwner() const {
    return owner;
}

double Account::getBalance() const {
    return balance;
}

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        addTransaction("Deposited: $" + std::to_string(amount));
    }
}

bool Account::withdraw(double amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
        addTransaction("Withdrew: $" + std::to_string(amount));
        return true;
    }
    return false;
}

bool Account::transfer(Account& toAccount, double amount) {
    if (withdraw(amount)) {
        toAccount.deposit(amount);
        addTransaction("Transferred: $" + std::to_string(amount) + " to " + toAccount.getAccountNumber());
        return true;
    }
    return false;
}

void Account::addTransaction(const std::string& transaction) {
    transactionHistory.push_back(transaction);
}

void Account::displayTransactionHistory() const {
    std::cout << "Transaction History for " << accountNumber << ":\n";
    for (const auto& trans : transactionHistory) {
        std::cout << trans << "\n";
    }
}

void Account::displayAccountDetails() const {
    std::cout << "Account Number: " << accountNumber << "\n";
    std::cout << "Owner: " << owner << "\n";
    std::cout << "Balance: $" << std::fixed << std::setprecision(2) << balance << "\n";
}
