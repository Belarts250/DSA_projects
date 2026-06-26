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
    Student* next;
    Student(int i, string n, float m) : id(i), name(n), marks(m), next(nullptr) {}
};

Student* head = nullptr;
const string filename = "students_mixed.txt";

void load() {
    ifstream in(filename);
    if (!in) return;
    int id; string name; float marks;
    Student* tail = nullptr;
    while (in >> id >> ws && getline(in, name) && in >> marks) {
        Student* s = new Student(id, name, marks);
        if (!head) head = tail = s;
        else { tail->next = s; tail = s; }
    }
    in.close();
}

void save() {
    ofstream out(filename);
    Student* temp = head;
    while (temp) {
        out << temp->id << "\n" << temp->name << "\n" << temp->marks << "\n";
        temp = temp->next;
    }
    out.close();
}

void addStudent() {
    int id; string name; float marks;
    cout << "ID: "; cin >> id;
    cout << "Name: "; cin.ignore(); getline(cin, name);
    cout << "Marks: "; cin >> marks;
    Student* s = new Student(id, name, marks);
    if (!head) head = s;
    else {
        Student* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = s;
    }
    save();
    cout << "Student added.\n";
}

void display() {
    if (!head) { cout << "No students.\n"; return; }
    Student* temp = head;
    while (temp) {
        cout << temp->id << " " << temp->name << " " << temp->marks << "\n";
        temp = temp->next;
    }
}

Student* searchById(int id) {
    Student* temp = head;
    while (temp && temp->id != id) temp = temp->next;
    return temp;
}

void search() {
    int id; cout << "ID: "; cin >> id;
    Student* s = searchById(id);
    if (s) cout << "Found: " << s->name << ", " << s->marks << "\n";
    else cout << "Not found.\n";
}

void sortByMarks() {
    // Convert linked list to vector for easy sorting
    vector<Student*> vec;
    Student* temp = head;
    while (temp) {
        vec.push_back(temp);
        temp = temp->next;
    }
    sort(vec.begin(), vec.end(), [](Student* a, Student* b) { return a->marks > b->marks; });
    // Rebuild linked list
    head = nullptr;
    Student* tail = nullptr;
    for (auto s : vec) {
        s->next = nullptr;
        if (!head) head = tail = s;
        else { tail->next = s; tail = s; }
    }
    save();
    cout << "Sorted by marks (descending).\n";
}

void deleteStudent() {
    int id; cout << "ID: "; cin >> id;
    if (!head) { cout << "Empty.\n"; return; }
    if (head->id == id) {
        Student* temp = head;
        head = head->next;
        delete temp;
        save();
        cout << "Deleted.\n";
        return;
    }
    Student* prev = head;
    Student* curr = head->next;
    while (curr && curr->id != id) {
        prev = curr;
        curr = curr->next;
    }
    if (curr) {
        prev->next = curr->next;
        delete curr;
        save();
        cout << "Deleted.\n";
    } else cout << "Not found.\n";
}

int main() {
    load();
    int choice;
    do {
        cout << "\n1.Add 2.Display 3.Search 4.Sort by Marks 5.Delete 6.Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: addStudent(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: sortByMarks(); break;
            case 5: deleteStudent(); break;
        }
    } while (choice != 6);
    return 0;
}