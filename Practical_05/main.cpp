#include <iostream>
#include <string>

// Base Class
class Person {
protected:
    std::string name;
    int age;

public:
    Person(std::string n, int a) : name(n), age(a) {}

    void displayPerson() const {
        std::cout << "Name: " << name << "\nAge: " << age << "\n";
    }
};

// Derived Class 1 (Single Inheritance from Person)
class Student : public Person {
protected:
    int rollNumber;
    std::string course;

public:
    Student(std::string n, int a, int r, std::string c)
        : Person(n, a), rollNumber(r), course(c) {}

    void displayStudent() const {
        displayPerson();
        std::cout << "Roll Number: " << rollNumber << "\nCourse: " << course << "\n";
    }
};

// Derived Class 2 (Multilevel Inheritance: Person -> Student -> GraduateStudent)
class GraduateStudent : public Student {
private:
    std::string researchTopic;

public:
    GraduateStudent(std::string n, int a, int r, std::string c, std::string topic)
        : Student(n, a, r, c), researchTopic(topic) {}

    void displayGraduate() const {
        displayStudent();
        std::cout << "Research Topic: " << researchTopic << "\n";
    }
};

int main() {
    std::cout << "--- Single Inheritance Demo ---\n";
    Student s1("Pranav", 20, 112, "B.Tech CSE");
    s1.displayStudent();

    std::cout << "\n--- Multilevel Inheritance Demo ---\n";
    GraduateStudent gs1("Aarav", 23, 205, "M.Tech AI", "Neural Network Optimization");
    gs1.displayGraduate();

    return 0;
}