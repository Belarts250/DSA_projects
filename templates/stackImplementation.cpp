#include <iostream>
using namespace std;

const int MAX = 100;
int stack[MAX];
int top = -1;

bool isEmpty() { return top == -1; }
bool isFull() { return top == MAX - 1; }

void push(int val) {
    if (isFull()) { cout << "Stack Overflow\n"; return; }
    stack[++top] = val;
    cout << val << " pushed.\n";
}

void pop() {
    if (isEmpty()) { cout << "Stack Underflow\n"; return; }
    cout << stack[top--] << " popped.\n";
}

void peek() {
    if (isEmpty()) cout << "Stack empty\n";
    else cout << "Top: " << stack[top] << "\n";
}

void display() {
    if (isEmpty()) { cout << "Empty\n"; return; }
    for (int i = top; i >= 0; i--) cout << stack[i] << " ";
    cout << "\n";
}

int main() {
    int choice, val;
    do {
        cout << "\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Value: "; cin >> val; push(val); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
        }
    } while (choice != 5);
    return 0;
}