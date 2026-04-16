#include <iostream>
#include <string>
using namespace std;

struct Employee {
    int id;
    string name;
    double salary;
};

void displayEmployees(Employee** employees, int size) {
    for (int i = 0; i < size; i++) {
        cout << "ID: " << employees[i]->id
             << ", Name: " << employees[i]->name
             << ", Salary: " << employees[i]->salary
             << endl;
    }
}

int main() {
 
    Employee employees[5] = {
        {1, "Belise", 3000.50},
        {2, "Sandrine", 2800.75},
        {3, "Prisca", 3500.00},
        {4, "Diana", 4000.20},
        {5, "keza", 2700.10}
    };

    Employee* empPtrs[5];


    for (int i = 0; i < 5; i++) {
        empPtrs[i] = &employees[i];
    }

    displayEmployees(empPtrs, 5);

    return 0;
}
