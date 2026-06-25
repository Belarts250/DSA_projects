#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Book {
public:
    int id;
    string title, author;
    bool issued;
};

vector<Book> books;
const string filename = "library.txt";

void load() {
    ifstream in(filename);
    if (!in) return;
    Book b;
    while (in >> b.id >> ws && getline(in, b.title) && getline(in, b.author) && in >> b.issued)
        books.push_back(b);
}

void save() {
    ofstream out(filename);
    for (const auto &b : books)
        out << b.id << "\n" << b.title << "\n" << b.author << "\n" << b.issued << "\n";
}

void addBook() {
    Book b;
    cout << "ID: "; cin >> b.id;
    cout << "Title: "; cin.ignore(); getline(cin, b.title);
    cout << "Author: "; getline(cin, b.author);
    b.issued = false;
    books.push_back(b);
    save();
}

void displayBooks() {
    for (const auto &b : books)
        cout << b.id << " | " << b.title << " | " << b.author << " | " << (b.issued ? "Issued" : "Available") << "\n";
}

void searchBook() {
    int id; cout << "ID: "; cin >> id;
    for (const auto &b : books)
        if (b.id == id) {
            cout << b.title << " by " << b.author << " - " << (b.issued ? "Issued" : "Available") << "\n";
            return;
        }
    cout << "Not found.\n";
}

void issueBook() {
    int id; cout << "ID: "; cin >> id;
    for (auto &b : books)
        if (b.id == id && !b.issued) {
            b.issued = true;
            save();
            cout << "Book issued.\n";
            return;
        }
    cout << "Not available or invalid ID.\n";
}

void returnBook() {
    int id; cout << "ID: "; cin >> id;
    for (auto &b : books)
        if (b.id == id && b.issued) {
            b.issued = false;
            save();
            cout << "Book returned.\n";
            return;
        }
    cout << "Invalid.\n";
}

int main() {
    load();
    int ch;
    do {
        cout << "\n1.Add 2.Display 3.Search 4.Issue 5.Return 6.Exit\nChoice: ";
        cin >> ch;
        switch (ch) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
        }
    } while (ch != 6);
    return 0;
}