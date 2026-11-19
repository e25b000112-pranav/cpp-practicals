#include <iostream>
#include <string>

int main() {
    // Constant variable
    const double PASSING_MARKS = 40.0;

    // Basic data types
    int rollNo;
    double marks;
    char grade;
    std::string name;

    std::cout << "Enter Student Name: ";
    std::getline(std::cin, name);
    std::cout << "Enter Roll Number: ";
    std::cin >> rollNo;
    std::cout << "Enter Marks (out of 100): ";
    std::cin >> marks;

    // Arithmetic & Relational operations
    double percentage = (marks / 100.0) * 100.0;
    bool isPassed = (marks >= PASSING_MARKS) && (marks <= 100.0);

    if (marks >= 75) grade = 'A';
    else if (marks >= 60) grade = 'B';
    else if (isPassed) grade = 'C';
    else grade = 'F';

    std::cout << "\n--- Student Result ---\n";
    std::cout << "Name: " << name << " | Roll No: " << rollNo << "\n";
    std::cout << "Percentage: " << percentage << "% | Grade: " << grade << "\n";
    std::cout << "Status: " << (isPassed ? "PASS" : "FAIL") << "\n";

    return 0;
}