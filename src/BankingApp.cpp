#include "BankingApp.h"
#include <iostream>
#include <limits>

void BankingApp::createAccount() {
    std::string accNum, ownerName;
    
    std::cout << "Enter Account Number: ";
    std::cin >> accNum;
    std::cout << "Enter Account Owner Name: ";
    std::cin.ignore();
    std::getline(std::cin, ownerName);

    Account newAccount(accNum, ownerName);
    accounts.push_back(newAccount);
    std::cout << "Account created successfully.\n";
}

Account* BankingApp::findAccount(const std::string& accountNumber) {
    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accountNumber) {
            return &acc;
        }
    }
    return nullptr;
}

void BankingApp::displayMenu() {
    std::cout << "\nBanking App Menu\n";
    std::cout << "1. Create Account\n";
    std::cout << "2. View Account Balance\n";
    std::cout << "3. Deposit Funds\n";
    std::cout << "4. Withdraw Funds\n";
    std::cout << "5. Transfer Funds\n";
    std::cout << "6. View Transaction History\n";
    std::cout << "7. Exit\n";
    std::cout << "Select an option: ";
}

void BankingApp::run() {
    int choice;
    while (true) {
        displayMenu();
        std::cin >> choice;

        std::string accNum;
        double amount;
        Account* selectedAccount = nullptr;

        switch (choice) {
            case 1:
                createAccount();
                break;

            case 2:
                std::cout << "Enter Account Number: ";
                std::cin >> accNum;
                selectedAccount = findAccount(accNum);
                if (selectedAccount) {
                    selectedAccount->displayAccountDetails();
                } else {
                    std::cout << "Account not found.\n";
                }
                break;

            case 3:
                std::cout << "Enter Account Number: ";
                std::cin >> accNum;
                selectedAccount = findAccount(accNum);
                if (selectedAccount) {
                    std::cout << "Enter amount to deposit: $";
                    std::cin >> amount;
                    selectedAccount->deposit(amount);
                    std::cout << "Deposit successful.\n";
                } else {
                    std::cout << "Account not found.\n";
                }
                break;

            case 4:
                std::cout << "Enter Account Number: ";
                std::cin >> accNum;
                selectedAccount = findAccount(accNum);
                if (selectedAccount) {
                    std::cout << "Enter amount to withdraw: $";
                    std::cin >> amount;
                    if (selectedAccount->withdraw(amount)) {
                        std::cout << "Withdrawal successful.\n";
                    } else {
                        std::cout << "Insufficient funds or invalid amount.\n";
                    }
                } else {
                    std::cout << "Account not found.\n";
                }
                break;

            case 5:
                std::cout << "Enter your Account Number: ";
                std::cin >> accNum;
                Account* fromAccount = findAccount(accNum);
                if (fromAccount) {
                    std::string toAccNum;
                    std::cout << "Enter recipient's Account Number: ";
                    std::cin >> toAccNum;
                    Account* toAccount = findAccount(toAccNum);
                    if (toAccount) {
                        std::cout << "Enter amount to transfer: $";
                        std::cin >> amount;
                        if (fromAccount->transfer(*toAccount, amount)) {
                            std::cout << "Transfer successful.\n";
                        } else {
                            std::cout << "Transfer failed. Check balance and amount.\n";
                        }
                    } else {
                        std::cout << "Recipient account not found.\n";
                    }
                } else {
                    std::cout << "Your account not found.\n";
                }
                break;

            case 6:
                std::cout << "Enter Account Number: ";
                std::cin >> accNum;
                selectedAccount = findAccount(accNum);
                if (selectedAccount) {
                    selectedAccount->displayTransactionHistory();
                } else {
                    std::cout << "Account not found.\n";
                }
                break;

            case 7:
                std::cout << "Exiting the Banking App.\n";
                return;

            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    }
}
