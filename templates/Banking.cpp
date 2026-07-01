#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Account {
public:
    int accNo;
    string name;
    double balance;
};

vector<Account> accounts;
const string filename = "bank.txt";

void load() {
    ifstream in(filename);
    if (!in) return;
    Account a;
    while (in >> a.accNo >> ws && getline(in, a.name) && in >> a.balance)
        accounts.push_back(a);
}

void save() {
    ofstream out(filename);
    for (const auto &a : accounts)
        out << a.accNo << "\n" << a.name << "\n" << a.balance << "\n";
}

void createAccount() {
    Account a;
    cout << "Account No: "; cin >> a.accNo;
    cout << "Name: "; cin.ignore(); getline(cin, a.name);
    a.balance = 0;
    accounts.push_back(a);
    save();
    cout << "Account created.\n";
}

void deposit() {
    int no; double amt;
    cout << "Account No: "; cin >> no;
    for (auto &a : accounts)
        if (a.accNo == no) {
            cout << "Amount: "; cin >> amt;
            a.balance += amt;
            save();
            cout << "Deposited. New balance: " << a.balance << "\n";
            return;
        }
    cout << "Not found.\n";
}

void withdraw() {
    int no; double amt;
    cout << "Account No: "; cin >> no;
    for (auto &a : accounts)
        if (a.accNo == no) {
            cout << "Amount: "; cin >> amt;
            if (amt > a.balance) cout << "Insufficient balance.\n";
            else { a.balance -= amt; save(); cout << "Withdrawn. New balance: " << a.balance << "\n"; }
            return;
        }
    cout << "Not found.\n";
}

void searchAccount() {
    int no; cout << "Account No: "; cin >> no;
    for (const auto &a : accounts)
        if (a.accNo == no) {
            cout << a.name << ", Balance: " << a.balance << "\n";
            return;
        }
    cout << "Not found.\n";
}

void displayAll() {
    for (const auto &a : accounts)
        cout << a.accNo << " " << a.name << " $" << a.balance << "\n";
}

int main() {
    load();
    int ch;
    do {
        cout << "\n1.Create 2.Deposit 3.Withdraw 4.Search 5.Display 6.Exit\nChoice: ";
        cin >> ch;
        switch (ch) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: searchAccount(); break;
            case 5: displayAll(); break;
        }
    } while (ch != 6);
    return 0;
}