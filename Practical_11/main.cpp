#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename = "student_notes.txt";

    // 1. Write data to a file
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << "Name: Pranav Dixit\n";
        outFile << "Subject: Object Oriented Programming (C++)\n";
        outFile << "Status: Practical 11 File Handling Completed\n";
        outFile.close();
        std::cout << "Data successfully written to " << filename << "\n\n";
    } else {
        std::cout << "Error opening file for writing!\n";
        return 1;
    }

    // 2. Read data back from the file
    std::ifstream inFile(filename);
    std::string line;
    if (inFile.is_open()) {
        std::cout << "--- Reading from " << filename << " ---\n";
        while (std::getline(inFile, line)) {
            std::cout << line << "\n";
        }
        inFile.close();
    } else {
        std::cout << "Error opening file for reading!\n";
        return 1;
    }

    return 0;
}