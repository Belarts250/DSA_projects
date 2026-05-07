#include <iostream>
using namespace std;

class Stack {
private:
    int size;      // Maximum capacity of the stack
    int top;       // Index of the top element (-1 means stack is empty)
    int* arr;      // Dynamic array to store stack elements

public:
    // Constructor: Initializes the stack with given size
    Stack(int size) {
        this->size = size;
        this->top = -1;           // Stack is empty initially
        this->arr = new int[size]; // Allocate memory for stack
    }

    // Push operation: Adds an element to the top of the stack
    void push(int num) {
        if (top < size - 1) {     // Check if stack is not full
            arr[top + 1] = num;   // Better: place at next position first
            top++;                // Then increment top
            // Alternative (your original): arr[top++] = num;
        }
        // You can add else { cout << "Stack Overflow!" << endl; }
    }

    // Pop operation: Removes and returns the top element
    int pop() {
        if (top >= 0) {           // Check if stack is not empty
            int value = arr[top]; // Get the top value
            top--;                // Decrease top
            return value;
        }
        // You can add else { cout << "Stack Underflow!" << endl; return -1; }
        return -1;                // Return -1 if stack is empty (error case)
    }

    // Display all elements from bottom to top
    void display() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }
        
        cout << "Stack elements (bottom to top): ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Check if stack is full
    bool isFull() {
        return top == size - 1;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Destructor: Free allocated memory to prevent memory leak
    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack* stack = new Stack(5);   // Create a stack of size 5

    stack->push(100);
    stack->push(200);
    stack->push(300);
    stack->push(400);
    stack->push(500);   // Now stack is full (5 elements)

    cout << "Is stack full? " << (stack->isFull() ? "Yes" : "No") << endl;

    int popped = stack->pop();
    cout << "Popped element: " << popped << endl;

    cout << "Is stack full after pop? " << (stack->isFull() ? "Yes" : "No") << endl;

    stack->display();

    // Clean up memory
    delete stack;

    return 0;
}