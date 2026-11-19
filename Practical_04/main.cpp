#include <iostream>
#include <memory>
#include <string>

class Resource {
private:
    std::string name;

public:
    Resource(std::string n) : name(n) {
        std::cout << "Resource [" << name << "] acquired.\n";
    }

    ~Resource() {
        std::cout << "Resource [" << name << "] automatically destroyed.\n";
    }

    void show() const {
        std::cout << "Using resource: " << name << "\n";
    }
};

void shareOwnership(std::shared_ptr<Resource> ptr) {
    std::cout << "Inside function - Reference Count: " << ptr.use_count() << "\n";
    ptr->show();
}

int main() {
    std::cout << "--- 1. std::unique_ptr Demo ---\n";
    {
        std::unique_ptr<Resource> uPtr = std::make_unique<Resource>("UniqueFile");
        uPtr->show();
        std::unique_ptr<Resource> uPtr2 = std::move(uPtr);
        if (!uPtr) {
            std::cout << "uPtr is now null after move.\n";
        }
        uPtr2->show();
    }

    std::cout << "\n--- 2. std::shared_ptr Demo ---\n";
    {
        std::shared_ptr<Resource> sPtr1 = std::make_shared<Resource>("SharedDatabase");
        std::cout << "Initial Reference Count: " << sPtr1.use_count() << "\n";

        {
            std::shared_ptr<Resource> sPtr2 = sPtr1;
            std::cout << "After sPtr2 copy - Reference Count: " << sPtr1.use_count() << "\n";
            shareOwnership(sPtr1);
            std::cout << "After function returns - Reference Count: " << sPtr1.use_count() << "\n";
        }

        std::cout << "After inner block - Reference Count: " << sPtr1.use_count() << "\n";
    }

    return 0;
}