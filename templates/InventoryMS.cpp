#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Product {
    int id;
    string name;
    int qty;
    double price;
};

vector<Product> products;
const string filename = "inventory.txt";

void load() {
    ifstream in(filename);
    if (!in) return;
    Product p;
    while (in >> p.id >> ws && getline(in, p.name) && in >> p.qty >> p.price)
        products.push_back(p);
}

void save() {
    ofstream out(filename);
    for (const auto &p : products)
        out << p.id << "\n" << p.name << "\n" << p.qty << "\n" << p.price << "\n";
}

void addProduct() {
    Product p;
    cout << "ID: "; cin >> p.id;
    cout << "Name: "; cin.ignore(); getline(cin, p.name);
    cout << "Quantity: "; cin >> p.qty;
    cout << "Price: "; cin >> p.price;
    products.push_back(p);
    save();
    cout << "Product added.\n";
}

void display() {
    for (const auto &p : products)
        cout << p.id << " " << p.name << " Qty:" << p.qty << " Price:$" << p.price << "\n";
}

void search() {
    int id; cout << "ID: "; cin >> id;
    for (const auto &p : products)
        if (p.id == id) { cout << p.name << ", " << p.qty << ", $" << p.price << "\n"; return; }
    cout << "Not found.\n";
}

void update() {
    int id; cout << "ID: "; cin >> id;
    for (auto &p : products)
        if (p.id == id) {
            cout << "New Name: "; cin.ignore(); getline(cin, p.name);
            cout << "New Quantity: "; cin >> p.qty;
            cout << "New Price: "; cin >> p.price;
            save();
            cout << "Updated.\n";
            return;
        }
    cout << "Not found.\n";
}

void del() {
    int id; cout << "ID: "; cin >> id;
    auto it = remove_if(products.begin(), products.end(), [id](const Product &p) { return p.id == id; });
    if (it != products.end()) {
        products.erase(it, products.end());
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
            case 1: addProduct(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: update(); break;
            case 5: del(); break;
        }
    } while (ch != 6);
    return 0;
}