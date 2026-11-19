#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

class Book {
public:
    int id;
    std::string title;
    std::string author;
    bool isIssued;

    Book(int i, std::string t, std::string a, bool issued = false)
        : id(i), title(t), author(a), isIssued(issued) {}

    void display() const {
        std::cout << "ID: " << id << " | Title: " << title
                  << " | Author: " << author
                  << " | Status: " << (isIssued ? "Issued" : "Available") << "\n";
    }
};

class Library {
private:
    std::vector<Book> books;
    const std::string filename = "library_books.csv";

public:
    void addBook(int id, std::string title, std::string author) {
        books.push_back(Book(id, title, author, false));
        saveToFile();
        std::cout << "Book added: " << title << "\n";
    }

    void listBooks() const {
        std::cout << "\n--- Library Catalog ---\n";
        for (const auto& b : books) b.display();
    }

    void issueBook(int id) {
        for (auto& b : books) {
            if (b.id == id) {
                if (b.isIssued) throw std::runtime_error("Book is already issued!");
                b.isIssued = true;
                saveToFile();
                std::cout << "Book ID " << id << " issued successfully.\n";
                return;
            }
        }
        throw std::invalid_argument("Book ID not found!");
    }

    void saveToFile() const {
        std::ofstream out(filename);
        for (const auto& b : books) {
            out << b.id << "," << b.title << "," << b.author << "," << b.isIssued << "\n";
        }
    }
};

int main() {
    Library lib;
    lib.addBook(1, "Clean Code", "Robert Martin");
    lib.addBook(2, "Effective C++", "Scott Meyers");
    lib.listBooks();

    try {
        lib.issueBook(1);
        lib.issueBook(1); // Triggers already-issued error
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    lib.listBooks();
    return 0;
}