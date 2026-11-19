#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

class Account {
private:
    std::string owner;
    double balance;

    void logTransaction(const std::string& message) {
        std::ofstream logFile("transactions.log", std::ios::app);
        if (logFile.is_open()) {
            logFile << owner << ": " << message << " | Balance: Rs." << balance << "\n";
            logFile.close();
        }
    }

public:
    Account(std::string name, double initialBalance) : owner(name), balance(initialBalance) {
        logTransaction("Account opened");
    }

    void deposit(double amount) {
        if (amount <= 0) {
            throw std::invalid_argument("Deposit amount must be positive!");
        }
        balance += amount;
        logTransaction("Deposited Rs." + std::to_string(amount));
        std::cout << "Deposited Rs." << amount << " | New Balance: Rs." << balance << "\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            throw std::runtime_error("Insufficient balance for withdrawal!");
        }
        balance -= amount;
        logTransaction("Withdrew Rs." + std::to_string(amount));
        std::cout << "Withdrew Rs." << amount << " | New Balance: Rs." << balance << "\n";
    }
};

int main() {
    try {
        Account acc("Pranav", 5000.0);
        acc.deposit(2000.0);
        acc.withdraw(1500.0);
        acc.withdraw(10000.0);
    } catch (const std::exception& e) {
        std::cout << "Transaction Error: " << e.what() << "\n";
    }

    return 0;
}