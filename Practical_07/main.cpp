#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overload + operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload - operator
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overload == operator
    bool operator==(const Complex& other) const {
        return (real == other.real) && (imag == other.imag);
    }

    // Overload << operator for output
    friend std::ostream& operator<<(std::ostream& out, const Complex& c) {
        out << c.real << (c.imag >= 0 ? " + " : " - ") << std::abs(c.imag) << "i";
        return out;
    }
};

int main() {
    Complex c1(4.5, 3.0);
    Complex c2(2.0, 1.5);

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    std::cout << "c1 = " << c1 << "\n";
    std::cout << "c2 = " << c2 << "\n";
    std::cout << "Sum (c1 + c2) = " << sum << "\n";
    std::cout << "Difference (c1 - c2) = " << diff << "\n";
    std::cout << "Are c1 and c2 equal? " << (c1 == c2 ? "Yes" : "No") << "\n";

    return 0;
}