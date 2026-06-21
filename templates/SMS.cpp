#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
public:
    int id;
    string name;
    float marks;
};

vector<Student> students;
const string filename = "students.txt";

void loadFromFile() {
    ifstream in(filename);
    if (!in) return;
    Student s;
    while (in >> s.id >> ws && getline(in, s.name) && in >> s.marks) {
        students.push_back(s);
    }
    in.close();
}

void saveToFile() {
    ofstream out(filename);
    for (const auto &s : students) {
        out << s.id << "\n" << s.name << "\n" << s.marks << "\n";
    }
    out.close();
}

void addStudent() {
    Student s;
    cout << "Enter ID: "; cin >> s.id;
    cout << "Enter Name: "; cin.ignore(); getline(cin, s.name);
    cout << "Enter Marks: "; cin >> s.marks;
    students.push_back(s);
    saveToFile();
    cout << "Student added!\n";
}

void displayAll() {
    if (students.empty()) {
        cout << "No students.\n";
        return;
    }
    for (const auto &s : students) {
        cout << "ID: " << s.id << ", Name: " << s.name << ", Marks: " << s.marks << "\n";
    }
}

void searchById() {
    int id;
    cout << "Enter ID: "; cin >> id;
    for (const auto &s : students) {
        if (s.id == id) {
            cout << "Found: " << s.name << ", Marks: " << s.marks << "\n";
            return;
        }
    }
    cout << "Not found.\n";
}

void updateStudent() {
    int id;
    cout << "Enter ID to update: "; cin >> id;
    for (auto &s : students) {
        if (s.id == id) {
            cout << "New Name: "; cin.ignore(); getline(cin, s.name);
            cout << "New Marks: "; cin >> s.marks;
            saveToFile();
            cout << "Updated.\n";
            return;
        }
    }
    cout << "Not found.\n";
}

void deleteStudent() {
    int id;
    cout << "Enter ID to delete: "; cin >> id;
    auto it = remove_if(students.begin(), students.end(), [id](const Student &s) { return s.id == id; });
    if (it != students.end()) {
        students.erase(it, students.end());
        saveToFile();
        cout << "Deleted.\n";
    } else {
        cout << "Not found.\n";
    }
}

int main() {
    loadFromFile();
    int choice;
    do {
        cout << "\n1. Add Student\n2. Display All\n3. Search by ID\n4. Update Student\n5. Delete Student\n6. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchById(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: cout << "Goodbye!\n"; break;
            default: cout << "Invalid.\n";
        }
    } while (choice != 6);
    return 0;
}