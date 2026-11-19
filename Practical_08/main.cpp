#include <iostream>
#include <string>

// Function Template to find maximum of two values
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

// Class Template for a Generic Key-Value Pair
template <typename T1, typename T2>
class KeyValuePair {
private:
    T1 key;
    T2 value;

public:
    KeyValuePair(T1 k, T2 v) : key(k), value(v) {}

    void display() const {
        std::cout << "Key: " << key << " | Value: " << value << "\n";
    }
};

int main() {
    std::cout << "--- Function Template Demo ---\n";
    std::cout << "Max of 15 and 27: " << findMax(15, 27) << "\n";
    std::cout << "Max of 8.45 and 3.92: " << findMax(8.45, 3.92) << "\n";
    std::cout << "Max of 'A' and 'Z': " << findMax('A', 'Z') << "\n";

    std::cout << "\n--- Class Template Demo ---\n";
    KeyValuePair<int, std::string> student(112, "Pranav");
    KeyValuePair<std::string, double> course("OOP C++", 9.5);

    student.display();
    course.display();

    return 0;
}