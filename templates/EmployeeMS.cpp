#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Employee {
public:
    int id;
    string name;
    double salary;
};

vector<Employee> employees;
const string filename = "employees.txt";

void load() {
    ifstream in(filename);
    if (!in) return;
    Employee e;
    while (in >> e.id >> ws && getline(in, e.name) && in >> e.salary) {
        employees.push_back(e);
    }
}

void save() {
    ofstream out(filename);
    for (const auto &e : employees)
        out << e.id << "\n" << e.name << "\n" << e.salary << "\n";
}

void add() {
    Employee e;
    cout << "ID: "; cin >> e.id;
    cout << "Name: "; cin.ignore(); getline(cin, e.name);
    cout << "Salary: "; cin >> e.salary;
    employees.push_back(e);
    save();
    cout << "Added.\n";
}

void display() {
    for (const auto &e : employees)
        cout << e.id << " " << e.name << " $" << e.salary << "\n";
}

void search() {
    int id; cout << "ID: "; cin >> id;
    for (const auto &e : employees)
        if (e.id == id) { cout << "Found: " << e.name << "\n"; return; }
    cout << "Not found.\n";
}

void update() {
    int id; cout << "ID: "; cin >> id;
    for (auto &e : employees)
        if (e.id == id) {
            cout << "New name: "; cin.ignore(); getline(cin, e.name);
            cout << "New salary: "; cin >> e.salary;
            save();
            cout << "Updated.\n";
            return;
        }
    cout << "Not found.\n";
}

void del() {
    int id; cout << "ID: "; cin >> id;
    auto it = remove_if(employees.begin(), employees.end(), [id](const Employee &e) { return e.id == id; });
    if (it != employees.end()) {
        employees.erase(it, employees.end());
        save();
        cout << "Deleted.\n";
    } else cout << "Not found.\n";
}

int main() {
    load();
    int ch;
    do {
        cout << "\n1.Add 2.Display 3.Search 4.Update 5.Delete 6.Exit\nChoice: ";
        cin >> ch;
        switch (ch) {
            case 1: add(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: update(); break;
            case 5: del(); break;
        }
    } while (ch != 6);
    return 0;
}