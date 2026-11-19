#include <iostream>
#include <utility>

class DynamicArray {
private:
    int* data;
    size_t size;

public:
    // 1. Default Constructor
    DynamicArray() : data(nullptr), size(0) {
        std::cout << "[Default Constructor]\n";
    }

    // 2. Parameterized Constructor
    DynamicArray(size_t s) : size(s) {
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = static_cast<int>((i + 1) * 10);
        }
        std::cout << "[Parameterized Constructor] Size = " << size << "\n";
    }

    // 3. Destructor
    ~DynamicArray() {
        delete[] data;
        std::cout << "[Destructor] Memory freed\n";
    }

    // 4. Copy Constructor (Deep Copy)
    DynamicArray(const DynamicArray& other) : size(other.size) {
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        std::cout << "[Copy Constructor]\n";
    }

    // 5. Copy Assignment Operator
    DynamicArray& operator=(const DynamicArray& other) {
        std::cout << "[Copy Assignment]\n";
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // 6. Move Constructor
    DynamicArray(DynamicArray&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
        std::cout << "[Move Constructor]\n";
    }

    // 7. Move Assignment Operator
    DynamicArray& operator=(DynamicArray&& other) noexcept {
        std::cout << "[Move Assignment]\n";
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    void display() const {
        std::cout << "Elements: ";
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    DynamicArray arr1(3);
    arr1.display();

    // Calls Copy Constructor
    DynamicArray arr2 = arr1;
    arr2.display();

    // Calls Move Constructor
    DynamicArray arr3 = std::move(arr1);
    arr3.display();

    // Calls Copy Assignment
    DynamicArray arr4;
    arr4 = arr2;

    // Calls Move Assignment
    DynamicArray arr5;
    arr5 = std::move(arr3);

    return 0;
}