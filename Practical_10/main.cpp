#include <iostream>
#include <stdexcept>
#include <string>

class InvalidAmount : public std::exception {
public:
    const char* what() const noexcept override {
        return "InvalidAmount Error: Transaction amount must be greater than zero.";
    }
};

class InsufficientFunds : public std::exception {
public:
    const char* what() const noexcept override {
        return "InsufficientFunds Error: Withdrawal exceeds current balance.";
    }
};

class BankAccount {
private:
    std::string holder;
    double balance;

public:
    BankAccount(std::string name, double initial) : holder(name), balance(initial) {}

    void withdraw(double amount) {
        if (amount <= 0) throw InvalidAmount();
        if (amount > balance) throw InsufficientFunds();
        balance -= amount;
        std::cout << "Withdrew Rs." << amount << " | Remaining Balance: Rs." << balance << "\n";
    }

    double getBalance() const { return balance; }
};

int main() {
    BankAccount acc("Pranav Dixit", 5000.0);

    try {
        acc.withdraw(1500.0);  // Valid
        acc.withdraw(-200.0);  // Throws InvalidAmount
    } catch (const InvalidAmount& e) {
        std::cout << e.what() << "\n";
    } catch (const InsufficientFunds& e) {
        std::cout << e.what() << "\n";
    }

    try {
        acc.withdraw(8000.0);  // Throws InsufficientFunds
    } catch (const InsufficientFunds& e) {
        std::cout << e.what() << "\n";
    }

    std::cout << "Final Safe Balance: Rs." << acc.getBalance() << "\n";
    return 0;
}