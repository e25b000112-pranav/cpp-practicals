#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    // 1. Write 3 records to students.csv
    std::ofstream outCsv("students.csv");
    if (!outCsv) {
        std::cout << "Failed to open students.csv!\n";
        return 1;
    }
    outCsv << "101,Pranav Dixit,92\n";
    outCsv << "102,Aarav Sharma,88\n";
    outCsv << "103,Rohan Patil,85\n";
    outCsv.close();

    // 2. Read and display CSV records
    std::ifstream inCsv("students.csv");
    std::string line;
    std::cout << "--- Reading students.csv ---\n";
    while (std::getline(inCsv, line)) {
        std::stringstream ss(line);
        std::string id, name, marks;
        std::getline(ss, id, ',');
        std::getline(ss, name, ',');
        std::getline(ss, marks, ',');
        std::cout << "ID: " << id << " | Name: " << name << " | Marks: " << marks << "\n";
    }
    inCsv.close();

    // 3. Demonstrate tellp(), seekp(), tellg(), seekg()
    std::fstream posFile("position_demo.txt", std::ios::out | std::ios::in | std::ios::trunc);
    posFile << "Hello World";
    std::cout << "\nWrite position (tellp): " << posFile.tellp() << "\n";

    posFile.seekp(6);
    posFile << "C++!!"; // Overwrites "World" with "C++!!"

    posFile.seekg(0);
    std::cout << "Read position after seekg(0) (tellg): " << posFile.tellg() << "\n";
    std::string content;
    std::getline(posFile, content);
    std::cout << "Updated File Content: " << content << "\n";
    posFile.close();

    return 0;
}