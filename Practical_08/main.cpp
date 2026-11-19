#include <iostream>
#include <memory>
#include <string>

// Abstract Product
class Vehicle {
public:
    virtual void drive() const = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    void drive() const override {
        std::cout << "Driving a 4-wheeler Car.\n";
    }
};

class Bike : public Vehicle {
public:
    void drive() const override {
        std::cout << "Riding a 2-wheeler Bike.\n";
    }
};

// Factory Class
class VehicleFactory {
public:
    static std::unique_ptr<Vehicle> createVehicle(const std::string& type) {
        if (type == "car") return std::make_unique<Car>();
        if (type == "bike") return std::make_unique<Bike>();
        return nullptr;
    }
};

int main() {
    auto v1 = VehicleFactory::createVehicle("car");
    auto v2 = VehicleFactory::createVehicle("bike");

    if (v1) v1->drive();
    if (v2) v2->drive();

    return 0;
}