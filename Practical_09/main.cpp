#include <iostream>
#include <stdexcept>
#include <string>

// Custom Exception Class
class InvalidAgeException : public std::exception {
private:
    std::string message;

public:
    InvalidAgeException(std::string msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

double divide(double numerator, double denominator) {
    if (denominator == 0) {
        throw std::runtime_error("Division by zero is not allowed!");
    }
    return numerator / denominator;
}

void registerVoter(int age) {
    if (age < 18) {
        throw InvalidAgeException("Registration failed: Age must be 18 or older.");
    }
    std::cout << "Voter registered successfully (Age: " << age << ").\n";
}

int main() {
    std::cout << "--- Standard Exception Demo ---\n";
    try {
        std::cout << "10 / 2 = " << divide(10, 2) << "\n";
        std::cout << "10 / 0 = " << divide(10, 0) << "\n";
    } catch (const std::runtime_error& e) {
        std::cout << "Caught Standard Exception: " << e.what() << "\n";
    }

    std::cout << "\n--- Custom Exception Demo ---\n";
    try {
        registerVoter(20);
        registerVoter(16);
    } catch (const InvalidAgeException& e) {
        std::cout << "Caught Custom Exception: " << e.what() << "\n";
    }

    return 0;
}