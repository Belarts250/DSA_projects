#include <iostream>
using namespace std;

const int MAX = 100;
int queue[MAX];
int front = -1, rear = -1;

bool isEmpty() { return front == -1; }
bool isFull() { return rear == MAX - 1; }

void enqueue(int val) {
    if (isFull()) { cout << "Queue Full\n"; return; }
    if (isEmpty()) front = 0;
    queue[++rear] = val;
    cout << val << " enqueued.\n";
}

void dequeue() {
    if (isEmpty()) { cout << "Queue Empty\n"; return; }
    cout << queue[front] << " dequeued.\n";
    if (front == rear) front = rear = -1;
    else front++;
}

void frontElem() {
    if (isEmpty()) cout << "Queue empty\n";
    else cout << "Front: " << queue[front] << "\n";
}

void display() {
    if (isEmpty()) { cout << "Empty\n"; return; }
    for (int i = front; i <= rear; i++) cout << queue[i] << " ";
    cout << "\n";
}

int main() {
    int choice, val;
    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Front 4.Display 5.Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Value: "; cin >> val; enqueue(val); break;
            case 2: dequeue(); break;
            case 3: frontElem(); break;
            case 4: display(); break;
        }
    } while (choice != 5);
    return 0;
}