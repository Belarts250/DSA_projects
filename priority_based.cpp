// ================================================
// Circular Priority Queue Implementation
// ================================================
// Students: 
// - Twarimitswe Aaron
// - Kamana Clare
// - Igihozo Belise
// ================================================

#include <bits/stdc++.h>
using namespace std;

// Enum for student priority levels
enum Priority {
    LOW,
    HIGH
};

// Student Node structure
class Student {
public:
    int code;
    string name;
    int age;
    Priority prio;
    Student* next;

    // Constructor
    Student(int c, string n, int a, Priority p) {
        code = c;
        name = n;
        age = a;
        prio = p;
        next = nullptr;
    }
};

// Circular Priority Queue using Linked List
class CircularPriorityQueue {
private:
    Student* front = nullptr;   // Points to the first student
    Student* last = nullptr;    // Points to the last student (rear)
    int highCount = 0;          // Tracks number of HIGH priority students

public:
    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Add a student to the circular queue
    void enqueue(int code, string name, int age, Priority prio) {
        Student* s = new Student(code, name, age, prio);

        if (prio == HIGH) 
            highCount++;

        if (isEmpty()) {
            // First student in the queue
            front = last = s;
            last->next = front;        // Make it circular
        } 
        else {
            // Add at the end and maintain circular link
            last->next = s;
            last = s;
            last->next = front;
        }

        cout << "Student enqueued successfully.\n";
    }

    // Remove and serve a student (HIGH priority first)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No student to serve.\n";
            return;
        }

        Student* curr = front;
        Student* prev = last;

        // If there are HIGH priority students, find the first one
        if (highCount > 0) {
            do {
                if (curr->prio == HIGH)
                    break;
                prev = curr;
                curr = curr->next;
            } while (curr != front);

            highCount--;
        }
        // If no HIGH priority, curr remains at front (FIFO for LOW)

        cout << "Serving student: " << curr->name << endl;

        // If only one student in queue
        if (curr == front && curr == last) {
            delete curr;
            front = last = nullptr;
        } 
        else {
            // Remove the student from circular list
            prev->next = curr->next;
            
            if (curr == front) 
                front = curr->next;
            
            if (curr == last) 
                last = prev;

            delete curr;
            last->next = front;   // Maintain circular structure
        }
    }

    // Display all students in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        Student* temp = front;
        cout << "\n=== Current Queue Contents ===\n";
        
        do {
            cout << "Code: " << temp->code
                 << " | Name: " << temp->name
                 << " | Age: " << temp->age
                 << " | Priority: " 
                 << (temp->prio == HIGH ? "HIGH" : "LOW") << endl;
            
            temp = temp->next;
        } while (temp != front);
        
        cout << "==============================\n";
    }
};

// ====================== MAIN PROGRAM ======================
int main() {
    CircularPriorityQueue queue;
    bool running = true;
    int option;

    cout << "========================================\n";
    cout << "   CIRCULAR PRIORITY QUEUE SYSTEM\n";
    cout << "========================================\n";

    while (running) {
        cout << "\nMenu:\n";
        cout << "1. Enqueue Student\n";
        cout << "2. Dequeue (Serve Student)\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1: {
                int code, age, p;
                string name;

                cout << "Enter student code: ";
                cin >> code;
                cin.ignore();                    // Clear newline before getline

                cout << "Enter student name: ";
                getline(cin, name);

                cout << "Enter age: ";
                cin >> age;

                cout << "Enter priority (0 = LOW, 1 = HIGH): ";
                cin >> p;

                Priority priority = (p == 1) ? HIGH : LOW;
                queue.enqueue(code, name, age, priority);
                break;
            }

            case 2:
                queue.dequeue();
                break;

            case 3:
                queue.display();
                break;

            case 4:
                cout << "Thank you! Exiting program...\n";
                running = false;
                break;

            default:
                cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}