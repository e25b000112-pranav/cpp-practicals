#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    std::string holderName;
    double balance;

public:
    BankAccount(std::string accNo, std::string name, double initialBalance) {
        accountNumber = accNo;
        holderName = name;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited Rs." << amount << " into " << accountNumber << "\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrew Rs." << amount << " from " << accountNumber << "\n";
        } else {
            std::cout << "Insufficient funds or invalid amount!\n";
        }
    }

    void display() const {
        std::cout << "Account: " << accountNumber
                  << " | Holder: " << holderName
                  << " | Balance: Rs." << balance << "\n";
    }
};

int main() {
    BankAccount acc1("ACC101", "Pranav", 5000.0);
    BankAccount acc2("ACC102", "Rohan", 3000.0);

    acc1.deposit(1500.0);
    acc1.withdraw(2000.0);
    acc1.display();

    std::cout << "\n";

    acc2.withdraw(4000.0);
    acc2.deposit(1000.0);
    acc2.display();

    return 0;
}