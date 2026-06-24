#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    int id;
    string name;
    float marks;
};

vector<Student> students;

void addStudent() {
    Student s;
    cout << "ID: "; cin >> s.id;
    cout << "Name: "; cin.ignore(); getline(cin, s.name);
    cout << "Marks: "; cin >> s.marks;
    students.push_back(s);
}

void display() {
    for (const auto &s : students)
        cout << s.id << " " << s.name << " " << s.marks << "\n";
}

void sortByMarks() {
    sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
        return a.marks > b.marks;
    });
    cout << "Sorted by marks (descending).\n";
}

void searchById() {
    int id; cout << "ID: "; cin >> id;
    for (const auto &s : students)
        if (s.id == id) { cout << "Found: " << s.name << ", " << s.marks << "\n"; return; }
    cout << "Not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n1.Add 2.Display 3.Sort by Marks 4.Search by ID 5.Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: addStudent(); break;
            case 2: display(); break;
            case 3: sortByMarks(); break;
            case 4: searchById(); break;
        }
    } while (choice != 5);
    return 0;
}