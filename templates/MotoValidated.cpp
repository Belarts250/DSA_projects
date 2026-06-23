#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cctype>    // for isdigit, isalpha
#include <regex>     // for date format checking (optional but clean)

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

// ------------------- Helper Validation Functions -------------------

// Check if a string consists only of letters, spaces, hyphens, and dots
bool isValidName(const string& name) {
    if (name.empty()) return false;
    for (char c : name) {
        if (!(isalpha(c) || c == ' ' || c == '-' || c == '.'))
            return false;
    }
    return true;
}

// Check if a phone number is exactly 10 digits (no spaces, dashes, etc.)
bool isValidPhone(const string& phone) {
    if (phone.length() != 10) return false;
    for (char c : phone) {
        if (!isdigit(c)) return false;
    }
    return true;
}

// Check if motorcycle number is non‑empty and contains only allowed characters
// (alphanumeric, space, hyphen) – adjust as needed.
bool isValidMotorcycle(const string& mc) {
    if (mc.empty()) return false;
    for (char c : mc) {
        if (!(isalnum(c) || c == ' ' || c == '-'))
            return false;
    }
    return true;
}

// Check if date is in DD-MM-YYYY format and represents a real date
bool isValidDate(const string& date) {
    // Basic format check using regex: DD-MM-YYYY
    regex datePattern(R"(^(0[1-9]|[12][0-9]|3[01])-(0[1-9]|1[0-2])-(\d{4})$)");
    smatch match;
    if (!regex_match(date, match, datePattern))
        return false;

    int day = stoi(match[1]);
    int month = stoi(match[2]);
    int year = stoi(match[3]);

    // Year range (reasonable)
    if (year < 1900 || year > 2100) return false;

    // Days per month (leap year not critical for this demo)
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // Adjust February for leap years
    if (month == 2) {
        bool isLeap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
        if (isLeap) daysInMonth[2] = 29;
    }
    return day <= daysInMonth[month];
}

// Check if an ID already exists in the member list
bool idExists(const vector<Member>& members, int id) {
    for (const auto& m : members) {
        if (m.id == id)
            return true;
    }
    return false;
}

// ------------------- File I/O Functions -------------------

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

        // Skip lines that are malformed
        if (idStr.empty()) continue;
        try {
            m.id = stoi(idStr);
        } catch (...) {
            continue;   // invalid ID, skip this record
        }

        members.push_back(m);
    }

    file.close();
    return members;
}

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

// ------------------- Core Operations -------------------

void addMember()
{
    Member m;
    vector<Member> existing = loadMembers();   // needed for ID uniqueness check

    cout << "\nEnter Member Details:\n";

    // --- Validate ID ---
    while (true) {
        cout << "ID: ";
        cin >> m.id;
        cin.ignore();

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive integer.\n";
            continue;
        }
        if (m.id <= 0) {
            cout << "ID must be a positive number.\n";
            continue;
        }
        if (idExists(existing, m.id)) {
            cout << "ID already exists. Please use a unique ID.\n";
            continue;
        }
        break;
    }

    // --- Validate Name ---
    while (true) {
        cout << "Name: ";
        getline(cin, m.name);
        if (isValidName(m.name))
            break;
        cout << "Invalid name. Use only letters, spaces, hyphens, and dots.\n";
    }

    // --- Validate Phone ---
    while (true) {
        cout << "Phone (10 digits): ";
        getline(cin, m.phone);
        if (isValidPhone(m.phone))
            break;
        cout << "Invalid phone. Must be exactly 10 digits (no spaces or dashes).\n";
    }

    // --- Validate Motorcycle No ---
    while (true) {
        cout << "Motorcycle No: ";
        getline(cin, m.motorcycle);
        if (isValidMotorcycle(m.motorcycle))
            break;
        cout << "Invalid motorcycle number. Use only letters, digits, spaces, and hyphens.\n";
    }

    // --- Validate Date Joined ---
    while (true) {
        cout << "Date Joined (DD-MM-YYYY): ";
        getline(cin, m.dateJoined);
        if (isValidDate(m.dateJoined))
            break;
        cout << "Invalid date. Use format DD-MM-YYYY with a valid calendar date.\n";
    }

    // Append to file
    ofstream file(FILE_NAME, ios::app);
    file << m.id << "|"
         << m.name << "|"
         << m.phone << "|"
         << m.motorcycle << "|"
         << m.dateJoined << endl;
    file.close();

    cout << "\nMember added successfully!\n";
}

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
            cout << "\nEnter new details (press Enter to keep current value):\n";

            // --- Update Name ---
            cout << "Name (" << m.name << "): ";
            string input;
            getline(cin, input);
            if (!input.empty()) {
                while (!isValidName(input)) {
                    cout << "Invalid name. Use only letters, spaces, hyphens, and dots: ";
                    getline(cin, input);
                }
                m.name = input;
            }

            // --- Update Phone ---
            cout << "Phone (" << m.phone << "): ";
            getline(cin, input);
            if (!input.empty()) {
                while (!isValidPhone(input)) {
                    cout << "Invalid phone. Exactly 10 digits, no spaces or dashes: ";
                    getline(cin, input);
                }
                m.phone = input;
            }

            // --- Update Motorcycle No ---
            cout << "Motorcycle No (" << m.motorcycle << "): ";
            getline(cin, input);
            if (!input.empty()) {
                while (!isValidMotorcycle(input)) {
                    cout << "Invalid motorcycle number. Use letters, digits, spaces, hyphens: ";
                    getline(cin, input);
                }
                m.motorcycle = input;
            }

            // --- Update Date Joined ---
            cout << "Date Joined (" << m.dateJoined << "): ";
            getline(cin, input);
            if (!input.empty()) {
                while (!isValidDate(input)) {
                    cout << "Invalid date. Use DD-MM-YYYY with a valid calendar date: ";
                    getline(cin, input);
                }
                m.dateJoined = input;
            }

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

// ------------------- Main Menu -------------------

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

        // Validate menu choice
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input. Please enter a number.\n";
            continue;
        }

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
                cout << "\nInvalid choice! Please choose 1-5.\n";
        }

    } while (choice != 5);

    return 0;
}