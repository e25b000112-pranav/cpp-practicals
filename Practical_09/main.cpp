#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

template <typename T>
class GenericStack {
private:
    std::vector<T> elements;

public:
    void push(const T& item) {
        elements.push_back(item);
    }

    void pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack Underflow: Cannot pop from an empty stack!");
        }
        elements.pop_back();
    }

    T top() const {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty!");
        }
        return elements.back();
    }

    bool isEmpty() const {
        return elements.empty();
    }
};

int main() {
    // 1. int Stack
    GenericStack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    std::cout << "Int Stack Top: " << intStack.top() << "\n";
    intStack.pop();

    // 2. float Stack
    GenericStack<float> floatStack;
    floatStack.push(3.14f);
    floatStack.push(9.81f);
    std::cout << "Float Stack Top: " << floatStack.top() << "\n";

    // 3. std::string Stack
    GenericStack<std::string> strStack;
    strStack.push("C++");
    strStack.push("Templates");
    std::cout << "String Stack Top: " << strStack.top() << "\n";

    // 4. Empty Stack Exception Test
    try {
        intStack.pop();
        intStack.pop(); // Triggers underflow
    } catch (const std::exception& e) {
        std::cout << "Error Caught: " << e.what() << "\n";
    }

    return 0;
}