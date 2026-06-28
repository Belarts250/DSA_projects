#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

struct Member {
    int id;
    string name;
    string bikeModel;
    Member* next;
};

Member* head = nullptr;
const string filename = "coop.txt";

void load() {
    ifstream in(filename);
    if (!in) return;
    Member* tail = nullptr;
    int id; string name, bike;
    while (in >> id >> ws && getline(in, name) && getline(in, bike)) {
        Member* m = new Member{id, name, bike, nullptr};
        if (!head) head = tail = m;
        else { tail->next = m; tail = m; }
    }
    in.close();
}

void save() {
    ofstream out(filename);
    Member* temp = head;
    while (temp) {
        out << temp->id << "\n" << temp->name << "\n" << temp->bikeModel << "\n";
        temp = temp->next;
    }
    out.close();
}

void addMember() {
    Member* m = new Member;
    cout << "ID: "; cin >> m->id;
    cout << "Name: "; cin.ignore(); getline(cin, m->name);
    cout << "Bike Model: "; getline(cin, m->bikeModel);
    m->next = nullptr;
    if (!head) head = m;
    else {
        Member* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = m;
    }
    save();
    cout << "Member added.\n";
}

void display() {
    if (!head) { cout << "No members.\n"; return; }
    Member* temp = head;
    while (temp) {
        cout << temp->id << " | " << temp->name << " | " << temp->bikeModel << "\n";
        temp = temp->next;
    }
}

Member* searchById(int id) {
    Member* temp = head;
    while (temp && temp->id != id) temp = temp->next;
    return temp;
}

void searchMember() {
    int id; cout << "ID: "; cin >> id;
    Member* m = searchById(id);
    if (m) cout << "Found: " << m->name << ", " << m->bikeModel << "\n";
    else cout << "Not found.\n";
}

void updateMember() {
    int id; cout << "ID: "; cin >> id;
    Member* m = searchById(id);
    if (m) {
        cout << "New name: "; cin.ignore(); getline(cin, m->name);
        cout << "New bike model: "; getline(cin, m->bikeModel);
        save();
        cout << "Updated.\n";
    } else cout << "Not found.\n";
}

void deleteMember() {
    int id; cout << "ID: "; cin >> id;
    if (!head) { cout << "Empty.\n"; return; }
    if (head->id == id) {
        Member* temp = head;
        head = head->next;
        delete temp;
        save();
        cout << "Deleted.\n";
        return;
    }
    Member* prev = head;
    Member* curr = head->next;
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
        cout << "\n1.Add 2.Display 3.Search 4.Update 5.Delete 6.Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: addMember(); break;
            case 2: display(); break;
            case 3: searchMember(); break;
            case 4: updateMember(); break;
            case 5: deleteMember(); break;
        }
    } while (choice != 6);
    return 0;
}