#include <iostream>
#include <vector>

// Abstract Base Class
class Shape {
public:
    // Pure virtual function
    virtual double area() const = 0;

    // Virtual destructor
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() const override {
        return length * width;
    }
};

class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double area() const override {
        return 0.5 * base * height;
    }
};

int main() {
    // Base class pointers pointing to derived objects
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));
    shapes.push_back(new Triangle(3.0, 8.0));

    std::cout << "--- Runtime Polymorphism Area Calculation ---\n";
    std::cout << "Circle Area: " << shapes[0]->area() << "\n";
    std::cout << "Rectangle Area: " << shapes[1]->area() << "\n";
    std::cout << "Triangle Area: " << shapes[2]->area() << "\n";

    // Clean up memory
    for (Shape* s : shapes) {
        delete s;
    }

    return 0;
}