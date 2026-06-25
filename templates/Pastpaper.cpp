#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

struct Member
{
    int id;
    string name;
    string phone;
    string motorcycle;
    string dateJoined;
};

const string FILE_NAME = "members.txt";

//loading all members

vector<Member> loadMembers()
{
    vector<Member> members;
    ifstream file(FILE_NAME);

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        Member m;
        string idStr;

        getline(ss, idStr, '|');
        getline(ss, m.name, '|');
        getline(ss, m.phone, '|');
        getline(ss, m.motorcycle, '|');
        getline(ss, m.dateJoined, '|');

        m.id = stoi(idStr);

        members.push_back(m);
    }

    file.close();
    return members;
}

// Save all members to file
void saveMembers(vector<Member>& members)
{
    ofstream file(FILE_NAME);

    for (auto m : members)
    {
        file << m.id << "|"
             << m.name << "|"
             << m.phone << "|"
             << m.motorcycle << "|"
             << m.dateJoined << endl;
    }

    file.close();
}

// Add Member
void addMember()
{
    Member m;

    cout << "\nEnter Member Details:\n";

    cout << "ID: ";
    cin >> m.id;
    cin.ignore();

    cout << "Name: ";
    getline(cin, m.name);

    cout << "Phone: ";
    getline(cin, m.phone);

    cout << "Motorcycle No: ";
    getline(cin, m.motorcycle);

    cout << "Date Joined (DD-MM-YYYY): ";
    getline(cin, m.dateJoined);

    ofstream file(FILE_NAME, ios::app);

    file << m.id << "|"
         << m.name << "|"
         << m.phone << "|"
         << m.motorcycle << "|"
         << m.dateJoined << endl;

    file.close();

    cout << "\nMember added successfully!\n";
}

// Displaying Members
void displayMembers()
{
    vector<Member> members = loadMembers();

    cout << "\nMember List:\n";

    cout << left
         << setw(8) << "ID"
         << setw(20) << "Name"
         << setw(15) << "Phone"
         << setw(15) << "Motorcycle"
         << setw(15) << "Date Joined"
         << endl;

    cout << string(73, '-') << endl;

    for (auto m : members)
    {
        cout << left
             << setw(8) << m.id
             << setw(20) << m.name
             << setw(15) << m.phone
             << setw(15) << m.motorcycle
             << setw(15) << m.dateJoined
             << endl;
    }
}

// Updating a Member
void updateMember()
{
    vector<Member> members = loadMembers();

    int id;
    bool found = false;

    cout << "\nEnter Member ID to update: ";
    cin >> id;
    cin.ignore();

    for (auto &m : members)
    {
        if (m.id == id)
        {
            found = true;

            cout << "\nEnter new details:\n";

            cout << "Name (" << m.name << "): ";
            getline(cin, m.name);

            cout << "Phone (" << m.phone << "): ";
            getline(cin, m.phone);

            cout << "Motorcycle No (" << m.motorcycle << "): ";
            getline(cin, m.motorcycle);

            cout << "Date Joined (" << m.dateJoined << "): ";
            getline(cin, m.dateJoined);

            break;
        }
    }

    if (found)
    {
        saveMembers(members);
        cout << "\nMember updated successfully!\n";
    }
    else
    {
        cout << "\nMember not found!\n";
    }
}

// Delete Member
void deleteMember()
{
    vector<Member> members = loadMembers();

    int id;
    bool found = false;

    cout << "\nEnter Member ID to delete: ";
    cin >> id;

    vector<Member> updatedList;

    for (auto m : members)
    {
        if (m.id == id)
        {
            found = true;
        }
        else
        {
            updatedList.push_back(m);
        }
    }

    if (found)
    {
        saveMembers(updatedList);
        cout << "\nMember deleted successfully!\n";
    }
    else
    {
        cout << "\nMember not found!\n";
    }
}

// Main Menu
int main()
{
    int choice;

    do
    {
        cout << "\nCollaborative Space Company Management\n";
        cout << "1. Add New Member\n";
        cout << "2. Display All Members\n";
        cout << "3. Update Member\n";
        cout << "4. Delete Member\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addMember();
                break;

            case 2:
                displayMembers();
                break;

            case 3:
                updateMember();
                break;

            case 4:
                deleteMember();
                break;

            case 5:
                cout << "\nProgram terminated.\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}