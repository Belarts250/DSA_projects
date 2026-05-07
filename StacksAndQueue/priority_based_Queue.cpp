//Twarimitswe Aaron
//Kamana Clare
//Igihozo Belise

#include <bits/stdc++.h>
using namespace std;


enum Priority {
    LOW,
    HIGH
};

class Student {
public:
    int code;
    string name;
    int age;
    Priority prio;
    Student* next;

    Student(int c, string n, int a, Priority p) {
        code = c;
        name = n;
        age = a;
        prio = p;
        next = nullptr;
    }
};

class CircularPriorityQueue {
private:
    Student* front = nullptr;
    Student* last = nullptr;
    int highCount = 0;


public:
    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int code, string name, int age, Priority prio) {
        Student* s = new Student(code, name, age, prio);

        if (prio == HIGH) highCount++;
       

        if (isEmpty()) {
            front = last = s;
            last->next = front;
        } else {
            last->next = s;
            last = s;
            last->next = front;
        }

        cout << "Student enqueued successfully.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No student to serve.\n";
            return;
        }

        Student* curr = front;
        Student* prev = last;

        if (highCount > 0) {
            do {
                if (curr->prio == HIGH)
                    break;
                prev = curr;
                curr = curr->next;
            } while (curr != front);
            highCount--;
        } 

        cout << "Serving student: " << curr->name << endl;

        if (curr == front && curr == last) {
            delete curr;
            front = last = nullptr;
        } else {
            prev->next = curr->next;
            if (curr == front) front = curr->next;
            if (curr == last) last = prev;
            delete curr;
            last->next = front;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        Student* temp = front;
        cout << "\nQueue contents:\n";
        do {
            cout << "Code: " << temp->code
                 << ", Name: " << temp->name
                 << ", Age: " << temp->age
                 << ", Priority: "
                 << (temp->prio == HIGH ? "HIGH" : "LOW") << endl;
            temp = temp->next;
        } while (temp != front);
    }
};

int main() {
    CircularPriorityQueue queue;
    bool running = true;
    int option;

    while (running) {
        cout << "\nCIRCULAR QUEUE OPERATIONS\n";
        cout << "========================\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1: {
                int code, age, p;
                string name;

                cout << "Enter student code: ";
                cin >> code;
                cin.ignore();

                cout << "Enter student name: ";
                getline(cin, name);

                cout << "Enter age: ";
                cin >> age;

                cout << "Enter priority (0 = LOW, 1 = HIGH): ";
                cin >> p;

                queue.enqueue(code, name, age, p == 1 ? HIGH : LOW);
                break;
            }

            case 2:
                queue.dequeue();
                break;

            case 3:
                queue.display();
                break;

            case 4:
                running = false;
                break;

            default:
                cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
